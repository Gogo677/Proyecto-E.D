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

void seleccion(int vector[], int totalItems){
	int i, j, min, temp;
	for(i=0; i<totalItems; i++){
		min=i;
		for (j=i+1; j<totalItems; j++){
			if(vector[j]< vector[min])
			min=j;
		}
		temp= vector[i];
		vector[i]= vector[min];
		vector[min]= temp;
		}
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
    seleccion(datos,n);
    tiempoFin=time(NULL);
    
    cout<<"\nprimeros 100 elementos del vector ordenado: \n";
    imprimeVector(datos,n);
    cout<<"\nHora de Entrada:"<<asctime(localtime(&tiempoInic));
    cout<<"\nHora de Salida:"<<asctime(localtime(&tiempoFin));
    printf("\nDuracion: %.5f",difftime(tiempoFin,tiempoInic));
	getch();
}
