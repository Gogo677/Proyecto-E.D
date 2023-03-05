#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include <time.h>
typedef struct nodo{
	float num;
	struct nodo *p;
}nod;
nod *inic=NULL;
void insertaFila(float ndato)
{
	nod *nvo,*aux=inic;
	
	nvo=new nod;
	if(nvo==NULL)
	{
		printf("\n No existe memoria suficiente para crear el nodo. \n Pulse tecla para terminar \n");
		getch();
		return;
	}
	nvo->num=ndato;

	if(inic==NULL)
	{
		inic=nvo;
	}
	else
	{
		while(aux->p!=inic)
		{
			aux=aux->p;
		}
		aux->p=nvo;
	}
	nvo->p=inic;
}

void sacarElementoDeLaFila()
{
	nod *aux=inic, *aux2=inic;
	if(inic==NULL)
	{
		printf("Fila cirular vacia, pulse tecla para continuar\n");
		getch();
		return;
	}
	while(aux2->p!=inic){
		aux2=aux2->p;
	}
	if(aux->p==inic){
		inic=NULL;
	}else{
		inic=inic->p;
		aux2->p=inic;
	}
	printf("Sale de la fila cirular: %d",aux->num);
	printf("\nPulse tecla para continuar\n");
	getch();
	delete(aux);
}

void imprimeFila()
{
	nod *aux=inic;
	if(inic==NULL)
	{
		printf("La fila cirular esta vacia\nPulse tecla para terminar");
		getch();
		return;
	}
	while(aux->p!=inic)
	{
		printf("<- %d ",aux->num);
		aux=aux->p;
	}
	printf("<- %d ",aux->num);
	printf("\nPulse tecla para continuar\n");
	getch();
}

int buscarEnlaFila(int busca)
{
	nod *aux=inic;
	int posicion=1;
	
	if(inic==NULL)
	{
		printf("\n Fila cirular vacia. \n Pulse tecla para continuar \n");
		getch();
		return 2;
	}
	while(aux->p!=inic)
	{
		if(aux->num==busca)
		{
			printf("\n El dato se encuentra en la posicion %d de la fila cirular \n",posicion);
			return 1;
		}
		else
		{
			aux=aux->p;
			posicion++;
		}	
	}
	if(aux->num==busca){
		printf("\n El dato se encuentra en la posicion %d de la fila cirular \n",posicion);
		return 1;
	}else{
		printf("\n El dato no se encuentra en la fila cirular. \n Pulse tecla para continuar");
	}
	return 0;
}

void eliminaTodaFila()
{
	while(inic!=NULL)
	{
		sacarElementoDeLaFila();	
	}
}

void guardarFila()
{
	nod *aux=inic;
	char nomArch[30];
	printf("\n dar ruta y nombre del archivo en donde se guardara la fila cirular: ");
	fflush(stdin);
	gets(nomArch);
	
	FILE *archi=fopen(nomArch,"w");
	if(archi==NULL)
	{
		printf("No se pudo abrir el archivo \n Pulse algo para continuar");
		getch();
		return;
	}
	if(inic==NULL){
		printf("\nLa fila cirular esta vacia. \nPulse tecla para terminar.\n");
		getch();
		return;
	}
	while(aux->p!=inic){
		fprintf(archi,"%d\n",aux->num);
		aux=aux->p;
	}
	fprintf(archi,"%d\n",aux->num);
	fclose(archi);
	getch();
}

void cargarFilaDesdeArchivo()
{
	int aux;
	char nomArch[30];
	printf("\n dar ruta y nombre del archivo en donde se cargar? la fila cirular: ");
	fflush(stdin);
	gets(nomArch);
	
	FILE *archi=fopen(nomArch,"r");
	if(archi==NULL)
	{
		printf("No se pudo abrir el archivo \n Pulse algo para continuar");
		getch();
		return;
	}else{
		printf("Se creo el archivo correctamente.");
	}
	while(!feof(archi))
	{
		fscanf(archi,"%d\n",&aux);
		insertaFila(aux);
	}
	
	fclose(archi);
}

main()
{
	int nPaleat;
    time_t tinic, tfinal;
	tinic=time(NULL);
	int opc, nvonum;
	
	do{
		printf("\n[1] Insertar en la fila circular.");
		printf("\n[2] Sacar de la fila circular.");
		printf("\n[3] Imprimir la fila circular.");
		printf("\n[4] Buscar elemento en la fila circular.");
		printf("\n[5] Elimina toda la fila circular.");
		printf("\n[6] guardar fila circular.");
		printf("\n[7] Cargar fila circular desde archivo");
		printf("\n[8] Salir.");
		printf("\nElija opcion [1, 2, 3, 4, 5, 6, 7, 8]");
		scanf("%d",&opc);
		
		switch(opc){
			case 1:
				printf("\nIngresa valor en la fila circular: ");
				scanf("%d",&nvonum);
				insertaFila(nvonum);
				break;
			case 2:
				sacarElementoDeLaFila();
				break;
			case 3: 
				imprimeFila();
				break;
			case 4:	
				printf("\n ingresa el dato que quieres buscar: ");
				scanf("%d",&nvonum);
				printf("\n resultado de la busqueda: %d \n",buscarEnlaFila(nvonum));
				break;
			case 5:
				eliminaTodaFila();
				break;
			case 6:
				guardarFila();
				break;	
			case 7:
				cargarFilaDesdeArchivo();
				break;				
			case 8:
				
				tfinal=time(NULL);
				printf("\nTiempo de entrada. %s segundos", asctime(localtime(&tinic)));
				printf("\nTiempo de salida. %s segundos", asctime(localtime(&tfinal)));
				printf("\nTiempo de permanencia. %.2f", difftime(tfinal,tinic));
				printf("\nFin del sistema. Pulse tecla para terminar.");
				eliminaTodaFila();
				break;
			default:
			printf("\nOpcion incorrecta.\nPulse tecla para continuar.");
			break;
		} 
	}while(opc!=8);
	
}	

