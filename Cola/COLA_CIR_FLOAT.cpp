#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
typedef struct nodo
{
 float x;
 struct nodo *p;
}sn;
sn *inic=NULL;
void insertaFC(float nvdato)
{
 sn *nvo, *aux=inic;
 nvo=new sn;
 nvo->x=nvdato;
 if(inic!=NULL) {
 while(aux->p!=inic) {
 aux=aux->p;
 }
 nvo->p=inic;
 aux->p=nvo;
 return;
 }
 else {
 inic=nvo;
 nvo->p=inic;
 }
}
void sacar()
{
 sn *aux=inic, *aux2;
 if(inic==NULL) {
 cout<<"\nLa fila esta vacia";
 system("pause");
 return;
 }
 inic=aux->p;
 aux2=inic;
 if(inic==inic->p) {
 inic=NULL;
 }
 while(aux2->p!=aux) {
 aux2=aux2->p;
 }
 aux2->p=inic;
 cout<<"\nSale el: "<<aux->x;
 delete(aux);
}
void imprimir ()
{
 sn *aux=inic;

 if(inic==NULL)
 {
 cout<<"\nFila vacia";
 system("pause");
 return;
 }
 while(aux->p!=inic)
 {
 cout<<aux->x<<"->";
 aux=aux->p;
 }
 cout<<aux->x;
}
main()
{
 int opc;
 float ndato;

 do
 {
 cout<<"\n\nCola circular";
 cout<<"\n1.Insertar";
 cout<<"\n2.Sacar";
 cout<<"\n3.Imprimir";
 cout<<"\n4.Salir";
 cout<<"\n\nElija opcion: ";
 cin>>opc;

 switch(opc)
 {
 case 1: cout<<"\nDato a insertar:";
 cin>>ndato;
 insertaFC(ndato);
 break;
 case 2: sacar();
 break;
 case 3: imprimir();
 break;
 case 4: cout<<"\n";
 break;
 default: cout<<"\nOpcion incorrecta. Vuelva a elegir\n";
 system("pause");
 }
 } while(opc!=4);
}
