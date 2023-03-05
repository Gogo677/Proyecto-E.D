#include<iostream>
#include<stdio.h>
using namespace std;
typedef struct nodo
{
	struct nodo *iz;
	float dat;
	struct nodo *de;
}nod;
nod *raiz=NULL;
void inserta_en_Arbol(nod *aux, float ndat)
{
	if(raiz==NULL)
	{
		aux=new nod;
		aux->dat=ndat;
		aux->de=NULL;
		aux->iz=NULL;
		raiz=aux;
	}
	else if(ndat<aux->dat)
	{
		cout<<"\n Inserta a la izquierda\n";
		if(aux->iz==NULL)
		{
			aux->iz=new nod;
			aux->iz->iz=NULL;
			aux->iz->de=NULL;
			aux->iz->dat=ndat;
		}
		else
		{
			inserta_en_Arbol(aux->iz, ndat);
		}
	}
	else if(ndat>aux->dat)
	{
		cout<<"\n Inserta a la derecha\n";
		if(aux->de==NULL)
		{
			aux->de=new nod;
			aux->de->dat=ndat;
			aux->de->iz=NULL;
			aux->de->de=NULL;
		}
		else
		{
			inserta_en_Arbol(aux->de, ndat);
		}
	}
	else if(ndat==aux->dat)
	{
	cout<<"\n El dato ya existe\n";
    }
} //Cierra a la funcion

void imprimeArbol(nod *aux, float n)
{
	if(aux==NULL) return;
	imprimeArbol(aux->de, n+1);
	for(int i=1; i<=n; i++) cout<<"  ";
	cout<<aux->dat<<endl;
	imprimeArbol(aux->iz, n+1);
}

main()
{
	nod *auxMain;
	float num_nodos=0.0;
	float x;
	cout<<"\nNumero de nodos deseado:";
	cin>>num_nodos;
	for(int i=1; i<=num_nodos; i++)
	{
		cout<<"\nIngresa dato:";
		cin>>x;
		auxMain=raiz;
		inserta_en_Arbol(auxMain, x);
	}
	auxMain=raiz;
	imprimeArbol(auxMain, 0);
	cin.get();
}
