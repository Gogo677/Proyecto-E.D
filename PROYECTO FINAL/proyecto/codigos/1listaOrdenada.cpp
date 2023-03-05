// LISTA LIGADA ORDENADA CIRCULAR DE ENTEROS
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
typedef struct nodo
{
 int x;
 struct nodo *p;

}nd;
nd *inic = NULL;
void InsertarLLC (int ndat)
{
 nd *aux,*aux1 = NULL,*aux2 = inic;
 aux = new(nd);
 aux->x = ndat;
 if (inic == NULL)
 {
 // Inserta el primer nodo
 aux->p=aux;
 inic=aux;
 return;
 }
 if (aux->x < inic->x)
 {
 // Inserta al inicio de la lista ligada circular
 aux1=inic;
 while(aux1->p!=inic)
 {
 aux1=aux1->p;
 }
 aux->p = inic;
 inic = aux;
 aux1->p=inic;
 }
 else
 {
 while ((aux2->p) != inic && (aux->x) > (aux2->x))
 {
 aux1 = aux2;
 aux2 = aux2->p;
 }
 if (aux->x > aux2->x)
 {
 // Inserta al final de la lista ligada circular
 aux->p = inic;
 aux2->p = aux;
 }
 else
 {
 // Inserta en los nodos intermedios de la lista ligada circular
 aux->p = aux2;
 aux1->p = aux;
 }
 }
}
void SacarLLC(int dato)
{
 nd *aux = inic, *aux1 = NULL, *aux2 = inic;
 if (inic == NULL)
 {
 cout<<endl<<"La lista ligada ordenada circular esta vacia!"<<endl;
 cout<<endl;
 system("pause");
 return;
 }
 if (dato == inic->x)
 {
 // Sacar al inicio de la lista ligada circular
 while(aux2->p!=inic)
 {
 aux2=aux2->p;
 }
 inic = aux->p;
 cout<<endl<<"Sale: "<<aux->x<<endl;
 delete(aux);
 aux2->p=inic;
 return;
 }
 else
 {
 while ((aux2->p) != inic && dato > aux2->x) {
 aux1 = aux2;
 aux2 = aux2->p;
 }
 if ((dato == aux2->x) && (aux2->p == inic))
 {
 // Sacar al final de la lista ligada circular
 if(inic->p==inic)
 {
 inic=NULL;
 }
 else
 {
 aux1->p = inic;
 cout<<endl<<"Sale: "<<aux2->x<<endl;
 cout<<endl;
 system("pause");
 delete(aux2);
 }
 return;
 }

 if (dato == aux2->x)
 {
 // Sacar en la parte intermedia de la lista ligada circular
 aux1->p = aux2->p;
 cout<<endl<<"Sale: "<<aux2->x<<endl;
 cout<<endl;
 system("pause");
 delete(aux2);
 return;
 }
 cout<<endl<<"El dato no existe en la lista ligada ordenada circular!"<<endl;
 }
}
void ImprimeLLC()
{
 nd *aux = inic;
 if (inic != NULL)
 {
 while(aux->p != inic)
 {
 cout<<aux->x<<" -> ";
 aux = aux->p;
 }
 cout<<aux->x;
 }
 else
 {
 cout<<endl<<"Lista ligada ordenada circular vacia!"<<endl;
 }
 cout<<endl;
 system("pause");
 return;
}
main()
{
 int opc;
 int ndato;
 do
 {
 cout<<endl<<"LISTA LIGADA ORDENADA CIRCULAR"<<endl;
 cout<<"\n1.Insertar";
 cout<<"\n2.Sacar";
 cout<<"\n3.Imprimir";
 cout<<"\n4.Salir";
 cout<<"\n\nElija opcion";
 cin>>opc;
 
 switch(opc)
 {
 case 1: cout<<"\nDato a insertar:"<<endl;
 cin>>ndato;
 InsertarLLC(ndato);
 break;
 case 2: cout<<"\nDato a sacar:"<<endl;
 cin>>ndato;
 SacarLLC(ndato);
 break;
 case 3: ImprimeLLC();
 break;
 //LOS CASOS FALTANTES SERAN PROGRAMADOS POR LOS AULUMNOS ESTRELLA DEL 1351.
 case 4: cout<<"\n";
 break;
 default: cout<<"\nOpcion incorrecta. Vuelva a elegir\n";
 system("pause");
 }
 } while(opc!=4);
}
