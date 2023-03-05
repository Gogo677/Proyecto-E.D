#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
FILE * abrirArchivo(char modo[4]){
 FILE *archivo;
 char nombre[120];
 cout<<"\nDar ruta del archivo: \n";
 fflush(stdin);
 gets(nombre);
 if((archivo = fopen(nombre,modo)) == NULL)
 {
 cout<<"\n No se pudo abrir el archivo";
 system("pause");
 exit(0);

 }
 return (archivo);
}
void MostrarArchivo(FILE *arch){
 char linea[128];
 rewind(arch);
 fgets(linea, 128, arch);
 while(!feof(arch)) {
 puts(linea);
 fgets(linea, 128, arch);
 }
 cout<<"\n";
 system("pause");
}
//Imprime archivos auxiliares
void MostrarArchivoAuxiliar(FILE **aux){
 char linea[128];
 aux[0] = fopen("aux1.txt", "r");
 aux[1] = fopen("aux2.txt", "r");
 cout<<"Contenido del Auxiliar 0 \n";
 fgets(linea, 128, aux[0]);
 while(!feof(aux[0])) {
 puts(linea);
 fgets(linea, 128, aux[0]);
 }
 cout<<"\n";
 system("pause");
 cout<<"Contenido del Auxiliar 1 \n";
 fgets(linea, 128, aux[1]);
 while(!feof(aux[1])) {
 puts(linea);
 fgets(linea, 128, aux[1]);
 }
 fclose(aux[0]);
 fclose(aux[0]);
 cout<<"\n";
 system("pause");
}
// Separa los tramos ordenados alternando entre los archivos auxiliares:
void Separar(FILE *fich, FILE **aux){
 char linea[128], anterior[2][128];
 int salida = 0;
 // Valores iniciales para los últimos valores almacenados en los archivos auxiliares
 strcpy(anterior[0], "");
 strcpy(anterior[1], "");
 // Captura la primero línea:
 fgets(linea, 128, fich);
 while(!feof(fich)) {
 // Decide a qué archivo de salida corresponde la línea leída:
 if(salida == 0 && strcmp(linea, anterior[0]) < 0) salida = 1;
 else if(salida == 1 && strcmp(linea, anterior[1]) < 0) salida = 0;
 // Almacena la línea actual como la última añadida:
 strcpy(anterior[salida], linea);
 // Añade la línea al fichero auxiliar:
 fputs(linea, aux[salida]);
 // Lee la siguiente línea:
 fgets(linea, 128, fich);
 }
}
// Mezcla los archivos auxiliares:
int Mezclar(FILE *ArchOrigen, FILE **aux)
{
 char ultima[128], linea[2][128], anterior[2][128];
 int entrada;
 int tramos = 0;
 // Lee la primera línea de cada fichero auxiliar:
 fgets(linea[0], 128, aux[0]);
 fgets(linea[1], 128, aux[1]);

 // Valores iniciales;
 strcpy(ultima,"");
 strcpy(anterior[0], "");
 strcpy(anterior[1], "");
 // Bucle, mientras no se acabe ninguno de los ficheros auxiliares (quedan tramos por mezclar):
 while(!feof(aux[0]) && !feof(aux[1])) {
 // Selecciona la línea que se añadirá:
 if(strcmp(linea[0], linea[1]) <= 0) entrada = 0; else entrada = 1;
 // Almacena el valor como el último añadido:
 strcpy(anterior[entrada], linea[entrada]);
 // Añade la línea al archivo:
 fputs(linea[entrada], ArchOrigen);
 // Lee la siguiente línea del archivo auxiliar:
 fgets(linea[entrada], 128, aux[entrada]);
 // Verificar fin de tramo, si es así copiar el resto del otro tramo:
 if(strcmp(anterior[entrada], linea[entrada]) > 0) {
 if(!entrada) entrada = 1; else entrada = 0;
 tramos++;
 // Copia lo que queda del tramo actual al fichero de salida:
 do {
 strcpy(anterior[entrada], linea[entrada]);
 fputs(linea[entrada], ArchOrigen);
 fgets(linea[entrada], 128, aux[entrada]);
 } while(!feof(aux[entrada]) && strcmp(anterior[entrada], linea[entrada]) <= 0);
 }
 }
 // Añadir tramos que queden sin mezclar:
 if(!feof(aux[0])) tramos++;
 while(!feof(aux[0])) {
 fputs(linea[0], ArchOrigen);
 fgets(linea[0], 128, aux[0]);
 }
 if(!feof(aux[1])) tramos++;
 while(!feof(aux[1])) {
 fputs(linea[1], ArchOrigen);
 fgets(linea[1], 128, aux[1]);
 }
 return(tramos == 1);
}
int main()
{
 system("COLOR 0A");	
 FILE *ArchivoOrigen;
 ArchivoOrigen=abrirArchivo("r+");
 puts("Archivo desordenado\n");
 MostrarArchivo(ArchivoOrigen);
 puts("Ordenando Archivo\n");
 int ordenado;
 FILE *aux[2];
 // se repite hasta que el archivo esté ordenado:
 do {
 // Crea los dos Archivos auxiliares para separar los tramos:
 aux[0] = fopen("aux1.txt", "w+");
 aux[1] = fopen("aux2.txt", "w+");
 rewind(ArchivoOrigen);
 Separar(ArchivoOrigen, aux);
 rewind(aux[0]);
 rewind(aux[1]);
 rewind(ArchivoOrigen);
 ordenado = Mezclar(ArchivoOrigen, aux);
 fclose(aux[0]);
 fclose(aux[1]);
 MostrarArchivoAuxiliar(aux);
 } while(!ordenado);
 // Elimina los ficheros auxiliares:
 remove("aux1.txt");
 remove("aux2.txt");
 puts("Archivo ordenado\n");
 MostrarArchivo(ArchivoOrigen);
 fclose(ArchivoOrigen);
 return 0;
}
