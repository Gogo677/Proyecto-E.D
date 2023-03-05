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

void quicksort(int vector[], int iz, int de){
	int i, j, k, x,w;
	i=iz;
	j=de;
	x=vector[(iz+de)/2];
	do{
		while(vector[i]< x)
			i++;
			while(x < vector[j])
			j=j-1;
			if(i<=j){
			w=vector[i];
			vector[i]=vector[j];
			vector[j]=w;
			i++;
			j--;
		}
	}while(i<j);
	if(iz < j)quicksort(vector, iz, j);
	if(i < de)quicksort(vector, i, de);
}


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
	getch();
	
	tiempoInic=time(NULL);
    quicksort(datos,0,n);
    tiempoFin=time(NULL);
    
    cout<<"\nprimeros 100 elementos del vector ordenado: \n";
    imprimeVector(datos,n);
    cout<<"\nHora de Entrada:"<<asctime(localtime(&tiempoInic));
    cout<<"\nHora de Salida:"<<asctime(localtime(&tiempoFin));
    printf("\nDuracion: %.5f",difftime(tiempoFin,tiempoInic));
	getch();
}
