#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
typedef struct nodo{
	int num;
	struct nodo *p;
}nod;
nod *tope=NULL;

int buscarEnlaPila(int busca)
{
	nod *aux=tope;
	int nivel=0;
	
	if(tope==NULL)
	{
		printf("\n Pila vacia. \n Pulse tecla para continuar \n");
		getch();
		return 2;
	}
	while(aux!=NULL)
	{
		if(aux->num==busca)
		{
			printf("\n El dato se encuentra en el nivel %d de la Pila \n",nivel);
			return 1;
		}
		else
		{
			aux=aux->p;
			nivel++;
		}	
	}
	printf("\n El dato no se encuentra en la pila. \n Pulse tecla para continuar");
	return 0;
}

void insertaPila(int nvodato){
	nod *nvo;
	nvo=(nod*)malloc(sizeof(nod));//Toma memoria del monticulo
	if(nvo==NULL){
		printf("\nNo se pudo crear el nodo.");
		getch();
		return;	
	}
	nvo->num=nvodato;
	if(tope==NULL){
		nvo->p=NULL;
	}else{
		nvo->p=tope;
		//tope=nvo;
	}
	tope=nvo;
	printf("\nEl dato fue insertado con exito.");
}

void sacarElementoPila(){
	nod *aux=tope;
	if(tope==NULL){
		printf("\nPila vacia. \nPulse tecla ara terminar");
		getch();
		return;
	}
	tope=aux->p;
	printf("\nSale de la pila el elemento: %d", aux->num);
	free(aux);
}

void imprimirPila(){
	nod *aux=tope;
	if(tope==NULL){
		printf("\nLa pila esta vacia. \nPulse tecla para terminar.\n");
		getch();
		return;
	}
	while(aux!=NULL){
		printf("%d\n",aux->num);
		aux=aux->p;
	}
	getch();
}

void eliminaTodaPila()
{
	while(tope!=NULL)
	{
		sacarElementoPila();	
	}
}

void guardaPila(){
	nod *aux=tope;
	char nomArch[30];
	printf("\n dar ruta y nombre del archivo en donde se guardar? la pila: ");
	fflush(stdin);
	gets(nomArch);
	
	FILE *archi=fopen(nomArch,"w");
	if(archi==NULL)
	{
		printf("No se pudo abrir el archivo \n Pulse algo para continuar");
		getch();
		return;
	}
	if(tope==NULL){
		printf("\nLa pila esta vacia. \nPulse tecla para terminar.\n");
		getch();
		return;
	}
	while(aux!=NULL){
		fprintf(archi,"%d\n",aux->num);
		aux=aux->p;
	}
	fclose(archi);
	getch();
}

void cargarPilaDesdeArchivo()
{
	int aux;
	char nomArch[30];
	printf("\n dar ruta y nombre del archivo en donde se cargar? la pila: ");
	fflush(stdin);
	gets(nomArch);
	
	FILE *archi=fopen(nomArch,"r");
	if(archi==NULL)
	{
		printf("No se pudo abrir el archivo \n Pulse algo para continuar");
		getch();
		return;
	}
	while(!feof(archi))
	{
		fscanf(archi,"%d\n",&aux);
		insertaPila(aux);
	}
	
	fclose(archi);
}

main(){
	time_t tinic, tfinal;
	tinic=time(NULL);
	int opc, nvonum;
	
	do{
		printf("\n[1] Insertar en la pila.");
		printf("\n[2] Sacar de la pila.");
		printf("\n[3] Imprimir la pila.");
		printf("\n[4] Buscar elemento en la pila.");
		printf("\n[5] Elimina toda la pila.");
		printf("\n[6] guardar pila");
		printf("\n[7] Cargar pila desde archivo");
		printf("\n[8] Salir.");
		printf("\nElija opcion [1, 2, 3, 4, 5, 6, 7]");
		scanf("%d",&opc);
		
		switch(opc){
			case 1:
				printf("\nIngresa el valor: ");
				scanf("%d",&nvonum);
				insertaPila(nvonum);
				break;
			case 2:
				sacarElementoPila();
				break;
			case 3: 
				imprimirPila();
				break;
			case 4:	
				printf("\n ingresa el dato que quieres buscar: ");
				scanf("%d",&nvonum);
				printf("\n resultado de la busqueda: %d \n",buscarEnlaPila(nvonum));
				break;
			case 5:
				eliminaTodaPila();
				break;
			case 6:
				guardaPila();
				break;
				
			case 7:
				cargarPilaDesdeArchivo();
				break;				
			case 8:
				
				tfinal=time(NULL);
				printf("\nTiempo de entrada. %s segundos", asctime(localtime(&tinic)));
				printf("\nTiempo de salida. %s segundos", asctime(localtime(&tfinal)));
				printf("\nTiempo de permanencia. %.2f", difftime(tfinal,tinic));
				printf("\nFin del sistema. Pulse tecla para terminar.");
				eliminaTodaPila();
				break;
			default:
			printf("\nOpcion incorrecta.\nPulse tecla para continuar.");
			break;
		}
	}while(opc!=8);
	
}






