#include<iostream>
#include<stdio.h>
#include <locale>
using namespace std;

typedef struct nodo
{
	float dato;
	struct nodo *pt;
}nod;

class Pila
{
	private:
		nod *tope;
		
	public:
		Pila();
		~Pila();
		void push(float);
		void pop();
		void imprimePila();	
};

Pila::Pila()
{
	tope=NULL;
	
}

void Pila::push(float n)
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
	system("COLOR 0A");
	setlocale (LC_ALL, "spanish");
	Pila pilita;
	int opc;
	float num;
	do
	{
		cout<<"\t\t Menú Pila Flotantes\n";
		cout<<"\n 1. Insertar en la pila de flotantes";
		cout<<"\n 2. Sacar de la pila de flotantes";
		cout<<"\n 3. Imprime la pila de flotantes";
		cout<<"\n 4. Salir \n";
		cin>>opc;
		switch(opc)
		{
			case 1: 
				cout<<"\n Dar un flotante: ";
				cin>>num;
				pilita.push(num);
				break;
			case 2:
				pilita.pop();
				break;
			case 3:
				pilita.imprimePila();
				break;
			case 4:
				cout<<"\n Fin de ejecucion";
				break;
			default: cout<<"\n Opcion incorrecta";
		}
	}while(opc!=4);
}
