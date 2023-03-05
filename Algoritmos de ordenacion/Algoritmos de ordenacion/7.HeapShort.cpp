#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <iostream>
using namespace std;
#include <time.h>

void imprimeVector(int vect[],int n){
	cout<<"\n";
	for(int i = 0;i<100;i++){
		cout<<" "<<vect[i];
		if((i+1)%20==0)
		{
			cout<<"\n";
		}
	}
	
}

void intercambio(int &a,int &b){
int temp=a;
a=b;
b=temp;
}

void HeapSort(int vec[],int n){
int i,j;
for (i=0;i<n;i++){
	j=i+1;
	while(j>1)
	if (vec[j-1]>vec[j/2-1]){
		intercambio(vec[j-1],vec[j/2-1]);
		j/=2;
	}
	else
	break;
}
for(i=n-1;i>0;i--){
		intercambio(vec[0],vec[i]);
		j=1;
	while (j*2<i)
	if (j*2+1>i)
	if(vec[j-1]>vec[j*2-1])
	break;
	else{
		intercambio (vec[j-1],vec[j*2-1]);
		j*=2;
	}
	else
	if (vec[j*2-1]>vec[j*2])
	if (vec[j-1]>vec[j*2-1])
	break;
	else{
		intercambio (vec[j-1],vec[j*2-1]);
		j*=2;
	}
	else
	if(vec[j-1]>vec[j*2])
	break;
	else{
		intercambio (vec[j-1],vec[j*2]);
		j*=2+1;
	}
}
}//cierra la función HeapSort

main (){
	FILE *arch;
    time_t tiempoInic,tiempoFin;
    int n=100000;
	int datos[n];
	
	arch = fopen("c:/proyecto/codigos/datos.txt", "r");
    for(int i=0;i<n;i++) 
	fscanf(arch,"%d",&datos[i]);
	fclose(arch);
	
	cout<<"primeros 100 elementos del vector sin ordenar: \n";
	imprimeVector(datos,n);
	
	tiempoInic=time(NULL);
    HeapSort(datos,n);
    tiempoFin=time(NULL);
    
    cout<<"\nprimeros 100 elementos del vector ordenado: \n";
    imprimeVector(datos,n);
    cout<<"\nHora de Entrada:"<<asctime(localtime(&tiempoInic));
    cout<<"\nHora de Salida:"<<asctime(localtime(&tiempoFin));
    printf("\nDuracion: %.5f",difftime(tiempoFin,tiempoInic));
	getch();
}
