#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include <time.h>
typedef struct nodo{
	float num;
	struct nodo *p;
}nod;
nod *inic=NULL;
int generaPaleat()
{
	return(rand()%100);
}
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
	nvo->p=NULL;
	nvo->num=ndato;
	
	if(inic==NULL)
	{
		inic=nvo;
		
	}
	else
	{
		while(aux->p!=NULL)
		{
			aux=aux->p;
			generaPaleat();
		}
		aux->p=nvo;
	}
}

void sacarElementoDeLaFila()
{
	nod *aux=inic;
	if(inic==NULL)
	{
		printf("Fila vacia, pulse tecla para continuar\n");
		getch();
		return;
	}
	inic=inic->p;
	printf("Sale de la fila: %.2f",aux->num);
	printf("\nPulse tecla para continuar");
	delete(aux);
}

void imprimeFila()
{
	nod *aux=inic;
	if(inic==NULL)
	{
		printf("La Fila esta vacia\nPulse tecla para terminar");
		getch();
		return;
	}
	while(aux!=NULL)
	{
		printf("<- %.2f ",aux->num);
		aux=aux->p;
	}
	/*printf("\nPulse tecla para continuar");
	getch();*/
}

int buscarEnlaFila(int busca)
{
	nod *aux=inic;
	int posicion=1;
	
	if(inic==NULL)
	{
		printf("\n Pila vacia. \n Pulse tecla para continuar \n");
		getch();
		return 2;
	}
	while(aux!=NULL)
	{
		if(aux->num==busca)
		{
			printf("\n El dato se encuentra en la posicion %d de la Pila \n",posicion);
			return 1;
		}
		else
		{
			aux=aux->p;
			posicion++;
		}	
	}
	printf("\n El dato no se encuentra en la fila. \n Pulse tecla para continuar");
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
	printf("\n dar ruta y nombre del archivo en donde se guardar? la fila: ");
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
		printf("\nLa fila esta vacia. \nPulse tecla para terminar.\n");
		getch();
		return;
	}
	while(aux!=NULL){
		fprintf(archi,"%.2f\n",aux->num);
		aux=aux->p;
	}
	fclose(archi);
	getch();
}

void cargarFilaDesdeArchivo()
{
	int aux;
	char nomArch[30];
	printf("\n dar ruta y nombre del archivo en donde se cargar? la fila: ");
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
		fscanf(archi,"%.2f\n",&aux);
		insertaFila(aux);
	}
	
	fclose(archi);
}

main()
{
	int nPaleat;
    time_t tinic, tfinal;
    srand(1000);
	tinic=time(NULL);
	int opc; 
	float nvonum;
	
	do{
		printf("\n[1] Insertar en la fila.");
		printf("\n[2] Sacar de la fila.");
		printf("\n[3] Imprimir la fila.");
		printf("\n[4] Buscar elemento en la fila.");
		printf("\n[5] Elimina toda la fila.");
		printf("\n[6] guardar fila");
		printf("\n[7] Cargar fila desde archivo");
		printf("\n[8] Llena fila con 10000 nodos");
		printf("\n[9] Salir.");
		printf("\nElija opcion [1, 2, 3, 4, 5, 6, 7,8,9]");
		scanf("%d",&opc);
		
		switch(opc){
			case 1:
				printf("\nIngresa valor en la fila: ");
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
				scanf("%.2f",&nvonum);
				printf("\n resultado de la busqueda: %.2f \n",buscarEnlaFila(nvonum));
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
			    for(int i=0;i<100;i++)
				{
					insertaFila(generaPaleat());
				}
				break;				
			case 9:
				
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
	}while(opc!=9);
	
}	

