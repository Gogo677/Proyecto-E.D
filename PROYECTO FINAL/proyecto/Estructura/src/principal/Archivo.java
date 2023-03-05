package principal;

import java.io.*;
import java.nio.charset.StandardCharsets;

public class Archivo{
    

    public String leer(String nombre){

    try{
    File f = new File(nombre);;
    
    BufferedReader br;
    br = new BufferedReader(new InputStreamReader(new FileInputStream(f), "UTF-8"));

    String l="";
    String aux="";

    while(true)
    //este ciclo while se usa para repetir el proceso de lectura, ya que se lee solo 1 linea de texto
    {
    aux=br.readLine();
    //leemos una linea de texto y la guardamos en la variable auxiliar
    if(aux!=null)
        l=l+aux+"\n";
    else
        break;
    }

    br.close();

    return l;

    }catch(IOException e){
    System.out.println("Error:"+e.getMessage());
    }
    return null;
    }
}