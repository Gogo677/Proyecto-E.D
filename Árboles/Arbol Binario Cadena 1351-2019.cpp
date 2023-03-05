#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAXNAMELENTH 64
#define MAXDATALENTH 1465

typedef struct node
{
    char name[MAXNAMELENTH];
    char data[MAXDATALENTH];
    struct node* left;
    struct node* right;
}node;

node* root;
node* search(node ** tree, char *key, int count, FILE *fp_out);
node* insertion(node* r, char *key, char *value);
void deltree(node * tree);
char* strtok_r(char *str, const char *delim, char **nextp);

int main(int argc, char *argv[])
{
    node *root;
    node *tmp;
    FILE *fp;
    FILE *outputfile;
    FILE *keyfile;
    FILE *fp_key;
    int i;
    int counter = 0;
    int bufsize = MAXDATALENTH + MAXNAMELENTH;
    int keyfilelen = MAXNAMELENTH;
    char *keyread;
    char *buffer,*saveptr;
    char *line = NULL;
    char *keyin = NULL;
    char *valuein = NULL;
    char inputkey[MAXNAMELENTH];
    char *target_key = NULL;
    char *keyline = NULL;


    root = NULL;
    
     buffer = (char *)malloc(bufsize * sizeof(char));
    if (buffer == NULL)
    {
        exit(1);
    }

    fp = fopen(argv[1], "r");
    outputfile = fopen("outputfile.txt", "a");

    while(fgets(buffer, bufsize, fp))
    {
        fgets(buffer, bufsize, fp);
        buffer = line;
        keyin = strtok_r(buffer, ",", &saveptr);
        valuein = strtok_r(NULL, "\n", &saveptr);
        root=insertion(root, keyin, valuein);
    }

}
node* insertion(node* r, char *key, char *value)
{
    if(r==NULL) // BST is not created created
    {
        r = (struct node*) malloc(sizeof(struct node)); // create a new node
        // insert data to new node
        strcpy(r->name,key);
        strcpy(r->data,value);
        // make left and right childs empty
        r->left = NULL;   
        r->right = NULL;
    }
    // if the data is less than node value then we must put this in left sub-tree
    else if(strcmp(key, r->name) < 0){ 
        r->left = insertion(r->left, key, value);
    }
    // else this will be in the right subtree
    else if (strcmp(key, r -> name) > 0){
         r->right = insertion(r->right, key, value);
    }
    else {
        if(strcmp(value, r -> data) > 0){
            r -> left = insertion(r -> left, key, value); 
        }
        else if(strcmp(value, r->data) < 0){ 
            r -> right = insertion(r->right, key, value);
        }   
    }
    return r;
}
