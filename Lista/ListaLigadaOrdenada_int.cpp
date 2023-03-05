#include<iostream>
#include<stdio.h>
using namespace std;

typedef struct nodo
{
	int dat;
	struct nodo *p;
}nd;

class ListaLigadaOrdenada
{
	private:
		nd *inic;
	public:
		ListaLigadaOrdenada();
		//~ListaLigadaOrdenada();
		void insertaLLO(int);
		void sacarLLO(int);
		void imprimeLLO();	
};

ListaLigadaOrdenada::ListaLigadaOrdenada()
{
	inic=NULL;
}

void ListaLigadaOrdenada::insertaLLO(int num)
{
	nd *nvo, *aux1=inic, *aux2=NULL;
	nvo = new nd;
	nvo->dat=num;
	//Inserta el primer nodo
	if(inic==NULL)
	{
		nvo->p=NULL;
		inic=nvo;
	}
	//Inserta al inicio de la lista
	else if((nvo->dat<aux1->dat)&&(nvo==inic))
	{
	    nvo->p=inic;
		inic=nvo;
	}
	else if(nvo->dat > aux1->dat)
	{
		while(aux1->dat < nvo->dat)
	    {
		    aux2=aux1;
		    aux1=aux2->p;
	    }
	    //inserta al final
		if(aux1->dat < nvo->dat)
	    {
			nvo->p=NULL;
	    	aux1->p=nvo;
		}
		//Inserta en medio
		else
		{
			nvo->p=aux1;
	        aux2->p=nvo;
		}			
	}
}

void ListaLigadaOrdenada::sacarLLO(int num)
{
	nd *aux1=inic, *aux2=NULL;
	if(inic==NULL)
	{
	    cout<<"\n Lista Ligada Ordenada VACIA\n";
		cin.get();
		return;
	}
	else if(aux1->p == NULL)
	{
		cout<<"\n Sale "<<aux1->dat;
		inic=NULL;
		delete(aux1);
	}
	else
	{
		while(num > aux1->dat)
		{
			aux2=aux1;
			aux1=aux2->p;
		}
		if(num == aux1->dat)
		{
			if(aux1 == inic)
			{
				inic=aux1->p;
				delete(aux1);
			}
			else if(aux1->p != NULL)
			{
				aux2->p=aux1->p;
				cout<<"\n Sale: "<<aux1->dat;
				delete(aux1);
			}
			else
			{
				aux2=NULL;
				cout<<"\n Sale: "<<aux1->dat;
				delete(aux1);
			}
		}
	}
	
}

void ListaLigadaOrdenada::imprimeLLO(){
nd *aux=inic;
if(aux==NULL) {
cout << "Lista vacia" << endl;
system("pause");
return;
}
while(aux!=NULL){
cout << " <-> " << aux->dat;
aux=aux->p;
}
}

main()
{
 int opc, ndato;
 ListaLigadaOrdenada obj;
 do
 {
 cout<<endl<<"LISTA LIGADA ORDENADA CIRCULAR"<<endl;
 cout<<"\n1.Insertar";
 cout<<"\n2.Sacar";
 cout<<"\n3.Imprimir";
 cout<<"\n4.Salir";
 cout<<"\n\nElija opcion: ";
 cin>>opc;
  
 switch(opc)
 {
 case 1: cout<<"\nDato a insertar:"<<endl;
 cin>>ndato;
 obj.insertaLLO(ndato);
 break;
 case 2: cout<<"\nDato a sacar:"<<endl;
 cin>>ndato;
 obj.sacarLLO(ndato);
 break;
 case 3: 
 obj.imprimeLLO();
 break;
 case 4: cout<<"\n";
 break;
 default: cout<<"\nOpcion incorrecta. Vuelva a elegir\n";
 system("pause");
 }
 } while(opc!=4);
}

