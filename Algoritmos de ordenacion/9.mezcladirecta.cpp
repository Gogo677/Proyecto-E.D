#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<time.h>
#define n 100
using namespace std;
void ImprimeVector (int vector[n])
{
 for (int i=0; i<n; i++)
 {
 cout<<" "<<vector[i];
 }
 cout<<endl;
 system("pause");
}
void mezclar(int vector[], int inicio, int medio, int fin)
{
 int aux[fin-inicio+1];
 int indAux, indPrimeraMitad, indSegundaMitad;
 int i;
 indAux = 0; //<! indice del arreglo auxiliar
 indPrimeraMitad = inicio; //<! indice de la primera mitad
 indSegundaMitad = medio+1; //<! indice de la segunda mitad
 while (indPrimeraMitad <= medio && indSegundaMitad <= fin) {
 if (vector[indPrimeraMitad] <= vector[indSegundaMitad]) {
 aux[indAux++] = vector[indPrimeraMitad++];
 }
 else{
 aux[indAux++] = vector[indSegundaMitad++];
 }
 }

 // Se copian los elementos de la primera mitad no comparados
 while (indPrimeraMitad<=medio){
 aux[indAux++] = vector[indPrimeraMitad++];
 }
 // Se copian los elementos de la segunda mitad no comparados
 while (indSegundaMitad <= fin){
 aux[indAux++] = vector[indSegundaMitad++];
 }
 indAux = 0;
 /* Finalmente se copian los elementos del arreglo auxiliar (ordenados)
 en el arreglo original */
 for (i = inicio; i <= fin; i++)
 {
 vector[i] = aux[indAux++];
 }
}
void mergeSort(int vector[], int inicio, int fin)
{
 int medio = (inicio + fin)/2;
 if (inicio < fin){
 mergeSort(vector, inicio, medio);
 mergeSort(vector, medio +1, fin);
 mezclar(vector, inicio, medio, fin);
 }
}
int generaNumeroAleatorio()
{
 return(rand()%100);
}
main()
{
	system("COLOR 0A");
 srand(time(NULL));
 int vec[n];
 for (int i=0; i<n; i++)
 {
 vec[i] = generaNumeroAleatorio();
 }
 cout<<"\n\nEl vector original es:\n";
 ImprimeVector(vec);
 mergeSort(vec,0,n-1);
 cout<<"\n\nEl vector ordenado por el metodo de mezcla directa es:\n";
 ImprimeVector(vec);
}
