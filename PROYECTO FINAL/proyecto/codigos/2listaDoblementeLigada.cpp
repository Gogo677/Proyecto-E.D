//Lista ordenada doblemente ligada
#include<stdlib.h>
#include<stdio.h>
#include<iostream>
 
using namespace std;
typedef struct nodo{
 struct nodo *iz;
 char n;
 struct nodo *de;
}nod;
nod *LDL=NULL;
 
void insertar(char nd){
 nod *nvo;
 nod *aux=LDL;
 nvo=new nod;
 nvo->n=nd;
 
 if(LDL==NULL) {
 LDL=nvo;
 LDL->iz=NULL;
 LDL->de=NULL;
 return;
 }
 while(aux->de!=NULL && nd>aux->n) {
 aux=aux->de;
 }
 if(aux->de==NULL && nd>aux->n) {
 // inserta el ultimo elemento de la lista
 nvo->de=NULL;
 aux->de=nvo;
 nvo->iz=aux;
 return;
 }
 if(LDL==aux && nd<aux->n){
 // inserta al inicio de la lista
 nvo->de=LDL;
 aux->iz=nvo;
 nvo->iz=NULL;
 LDL=nvo;
 return;
 }
 if(nd<aux->n){
 // inserta el dato en medio de la lista
 nvo->de=aux;
 nvo->iz=aux->iz;
 aux->iz->de=nvo;
 aux->iz=nvo;
 return;
 }
 if(nd==aux->n) {
 cout<<"\nEL dato ya existe, no fue insertado";
 system("pause");
 return;
 }
}
 
void eliminar(int sd){
 nod *aux=LDL;
 if(LDL==NULL) {
 cout<<"\nLa lista esta vacia";
 system("pause");
 return;
 }
 while(aux->de!=NULL && sd>aux->n) {
 aux=aux->de;
 }
 if(aux->iz==NULL && aux->de==NULL && sd==aux->n)
 {//elimina un elemento unico
 LDL=NULL;
 cout<<"\nSale: "<<aux->n;
 system("pause");
 delete(aux);
 return;
 }
 if(aux->de==NULL && sd==aux->n)
 {//elimina al final de la lista
 aux->iz->de=NULL;
 cout<<"\nSale: "<<aux->n;
 system("pause");
 delete(aux);
 return;
 }
 if(aux->de!=NULL && aux->iz!=NULL && sd==aux->n)
 {//elimina al elemento medio
 aux->iz->de=aux->de;
 aux->de->iz=aux->iz;
 cout<<"\nSale: "<<aux->n;
 system("pause");
 delete(aux);
 return;
 }
 if(aux->iz==NULL && aux->de!=NULL && sd==aux->n)
 { //elimina elemento al principio
LDL=aux->de;
LDL->iz=NULL;
cout<<"\nSale: "<<aux->n << endl;
 system("pause");
 delete(aux);
 return;
 }
 cout << "El dato no existe en la LDL" << endl;
system("pause");
}
 
void imprime(){
nod *aux=LDL;
if(LDL==NULL) {
cout << "Lista vacia" << endl;
system("pause");
return;
}
while(aux!=NULL){
cout << " <-> " << aux->n;
aux=aux->de;
}
}
 
void eliminatodo()
{
nod *aux=LDL;
if(LDL==NULL) {
cout << endl << "Lista Vacia" << endl;
system("pause");
return;
}
while(aux!=NULL) {
eliminar(aux->n);
aux=aux->de;
}
}
 
main(){
 int opc;
 char datoi;
 do {
 cout<<"\nLista Doblemente Ligada\n";
 cout<<endl<<"1. Insertar";
 cout<<endl<<"2. Sacar elemento";
 cout<<endl<<"3. Imprimir";
 cout<<endl<<"4. Elimina Todo";
 cout<<endl<<"5. Salir";
 cout<<endl<<"Elija opcion: ";
 cin>>opc;
 switch(opc){
 case 1:
 cout<<endl<<"Dar el dato a insertar: ";
 cin>>datoi;
 insertar(datoi);
 break;
 
 case 2:
 cout<<endl<<"Dar el dato a eliminar: ";
 cin>>datoi;
 eliminar(datoi);
 break;
 
 case 3:
 imprime();
 break;
 
 case 4:
 eliminatodo();
 break;
 
 case 5:
 eliminatodo();
 break;
 
 default:
 cout<<"la opcion no existe, escoja otra";
 }
 }while (opc!=5);
}


