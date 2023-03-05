#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <iostream>
using namespace std;
 
void GuardaVector(int vect[],int T)
{
FILE *arch;
arch=fopen("c:/borrame/datosOrdename.txt","w");
for (int i=0; i<T;i++)
{
fprintf(arch, "%d\n",vect[i]);
}
fclose (arch);
}
 
void imprimirVector(int datos[], int T)
{
 for(int i=0;i<T;i++)
 {
    cout<<" "<<datos[i];
 }  
}
 
void insercion_binaria(int vector[],int T){
int i,j, iz, der, m, temp;
for(i=1; i<T; i++)
{
 temp=vector[i]; 
 iz=0;der= i-1;
 while(iz<= der)
  {
   m=(iz+ der)/2;
   if(temp< vector[m])
   der=m-1;
   else
   iz=m+1;
   }
   for(j=i-1;j>= iz; j--)
   {
    vector[j+1]=vector[j];
	}
	vector[iz]=temp;
 }
}
 
main()
{
	system("COLOR 0A");
    time_t tiempoinicial, tiempofinal;
    int T=8;
    int datos[T]={44,55,12,42,94,18,06,67};
    imprimirVector(datos,T);
    getch();
    tiempoinicial=time(NULL);
    insercion_binaria(datos,T);
    GuardaVector(datos,T);
    tiempofinal=time(NULL);
     
    cout<<"\n\n Hora de entrada "<<asctime(localtime(&tiempoinicial))<<"";
    cout<<"\n Hora de salida "<<asctime(localtime(&tiempofinal))<<"";
    cout<<"\n Tiempo de permanecia: "<<difftime(tiempofinal,tiempoinicial)<<" segundos";
    getch();
}
