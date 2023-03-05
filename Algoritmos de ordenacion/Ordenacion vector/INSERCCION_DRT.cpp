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
 
void insercion_directa(int vector[],int T){
int i,j, temp;
 for(i=1; i<T; i++)
 {
  temp=vector[i];
  cout<<"\n temp="<<temp<<"\n";
  j=i-1;
  while((vector[j] > temp)&&(j>=0))
  { 
   vector[j+1]=vector[j];
   j=j-1;
  }
  vector[j+1]=temp;
  imprimirVector(vector,T);
 }
}
 
main()
{
	system("COLOR 0A");
    time_t tiempoinicial, tiempofinal;
    int T=8;
    int datos[]={44,55,12,42,94,18,06,67};
    imprimirVector(datos,T);
    getch();
    tiempoinicial=time(NULL);
    insercion_directa(datos,T);
    GuardaVector(datos,T);
    tiempofinal=time(NULL);
     
    cout<<"\n\n Hora de entrada "<<asctime(localtime(&tiempoinicial))<<"";
    cout<<"\n Hora de salida "<<asctime(localtime(&tiempofinal))<<"";
    cout<<"\n Tiempo de permanecia: "<<difftime(tiempofinal,tiempoinicial)<<" segundos";
    getch();
}
