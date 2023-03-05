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

void IncrementosDecrecienteShell(int vector[], int totalItems){
	int i, j, k, s ,temp, m, t=4, h[t];
	h[0]=8; h[1]=4; h[2]=2; h[3]=1;
	for(m=0; m<t ;m++){
		k=h[m];
		s=k;
		for(i=k; i< totalItems ;i++){
			temp=vector[i];
			j=i-k;
			if(s==0){
				s=-k;
				s++;
				vector[s]=temp;
			}
			while(j>=0 && temp<vector[j]){
				vector[j+k]= vector[j];
				j=j-k;
			}
			vector[j+k]= temp;
		}
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
    IncrementosDecrecienteShell(datos,n);
    tiempoFin=time(NULL);
    
    cout<<"\nprimeros 100 elementos del vector ordenado: \n";
    imprimeVector(datos,n);
    cout<<"\nHora de Entrada:"<<asctime(localtime(&tiempoInic));
    cout<<"\nHora de Salida:"<<asctime(localtime(&tiempoFin));
    printf("\nDuracion: %.5f",difftime(tiempoFin,tiempoInic));
	getch();
}
