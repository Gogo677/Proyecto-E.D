#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define TOTAL 10000
using namespace std;

typedef struct nodo
{
	int dato;
	struct nodo *pt;
}nod;

class Pila
{
	private:
		nod *tope;
		int contador;
		
	public:
		Pila();
		~Pila();
		int getContador();
		void push(int);
		void pop();
		void imprimePila();	
};

Pila::Pila()
{
	tope=NULL;
	contador=0;
}

void Pila::push(int n)
{
	nod *nvo;
	nvo=new(nod);
	nvo->dato=n;
	if(tope==NULL)
	{
		nvo->pt=NULL;
	} else {
		nvo->pt=tope;
	}
	tope=nvo;
	contador++;
}
int Pila::getContador()
{
	return contador;
}
void Pila::pop()
{
	nod *aux;
	aux=tope;
	if(tope==NULL)
	{
		cout<<"\n Pila Vacia ";
		cin.get();
		return;
	}
	tope=aux->pt;
	cout<<"\n Sale " << aux->dato;
	delete(aux);
}

void Pila::imprimePila()
{
	nod *aux=tope;
	if(tope==NULL)
	{
		cout<<"\n Pila Vacia \n";
		cin.get();
		return;
	}
	while(aux!=NULL)
	{
		cout<<"\n"<< aux->dato;
		aux=aux->pt;	
	}
}

Pila::~Pila()
{
	while(tope!=NULL)
	{
		pop();
	}
}

main()
{
	Pila pilita;
	int opc,num=0,aleat;
	srand((unsigned)time(NULL));
	unsigned ti,tf;
	ti=clock();
	do
	{ 
		aleat=rand()/100;
		pilita.push(aleat);
		num++;		
	}while(num<TOTAL);
	pilita.imprimePila();
	cout<<"\nTotal de elementos insertados: "<<pilita.getContador();
	tf=clock();
	double tiempo=(double(tf-ti)/CLOCKS_PER_SEC);
	cout << "\nTiempo de ejecucion: "<<tiempo;
	cin.get();
}



