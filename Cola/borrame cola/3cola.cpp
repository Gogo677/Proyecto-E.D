//Cola dinámica
#include<iostream>
#include<stdlib.h>
using namespace std;

typedef struct nodo
{
	float  num;
	struct nodo *pt;
}nod;

nod *inic=NULL;

void insertaFila(float nnum)
{
	nod *nvo,*aux=inic;
	nvo=(nod *)malloc(sizeof(nod));
	nvo->pt=NULL;
	nvo->num=nnum;
	if(inic==NULL)
	{
		inic=nvo;
	}
	else
	{ 
		while(aux->pt!=NULL)
		{
		aux=aux->pt;
		}
		aux->pt=nvo;
		cout<<"\nEl dato se inserto con exito\n";
		system("pause");
	}
}
void sacaFila()
{
	nod *aux=inic;
	if(inic==NULL)
		{
		cout<<"\nFila Vacia";
		system("pause");
		return;
		}
	inic=aux->pt; // inic=inic->pt;
	cout<<"\nSale:"<<aux->num<<"\n";
	system("pause");
	free(aux);	
}
void imprimeFila()
{
	nod *aux=inic;
	if(inic==NULL)
		{
			cout<<"\nFila Vacia\n";
			system("pause");
			return;
		}
	while(aux!=NULL)
		{
			cout<<"<--"<<aux->num;
			aux=aux->pt;
		}	
		cout<<endl;
		system("pause");	
}
void eliminaTodaLaFila()
{
	while(inic!=NULL)
		{
			sacaFila();
		}
}
void principioFila()
{
	if(inic==NULL)
		{
			cout<<"\nFila vacia";
		}
	else
		{
			cout<<"\nEl primero de la Fila es: "<<inic->num;
			system("pause");
		}
}
void ultimoFila()
{
  nod *aux=inic;
	if(inic==NULL)
  	{
  		cout<<"\nFila Vacia";
  		system("pause");
  		return;
	}	
	else		
		{
			while(aux->pt!=NULL)
			{
				aux=aux->pt;
			}
			cout<<"\nEl ultimo es: "<<aux->num<<endl;
			system("pause");
		}
}
main ()
{
	int opc;
	float dato;
	do
	{
		cout<<"\n1.- Insertar en la Fila\n";
		cout<<"\n2.- Eliminar un elemento de la Fila\n";
		cout<<"\n3.- Imprimir Fila\n";
		cout<<"\n4.- Elimina Toda la Fila\n";
		cout<<"\n5.- El primero de la Fila\n";
		cout<<"\n6.- El ultimo de la Fila\n";
		cout<<"\n7.- Salir\n";
		cout<<"\nEscoge una opcion:\n";
		cin>>opc;
		switch(opc)
		{
			case 1:
				cout<<"\nDato a insertar: ";
				cin>>dato;
				insertaFila(dato);
				break;
			case 2:
				cout<<"\nSacar un elemento";
				sacaFila();	
				break;
			case 3:
				cout<<"\nLa Fila esta conformada de: ";
				imprimeFila();
				break;
			case 4:
				cout<<"\nElimina Toda la Fila\n";
				eliminaTodaLaFila();
				break;
			case 5:
				principioFila();
				break; 	
			case 6:
				ultimoFila();
				break;
			case 7:
				cout<<"\nFin";
				eliminaTodaLaFila();
				break;
						
			default:
				cout<<"\nOpcion incorrecta. Vuelva a elegir";
				system("pause");
				break; 	
		}
		
		
		
	}while(opc!=7);
}


