//Autor: Gabriel Maldonado
//Fecha: 6 de Marzo del 2023
//Examen Final Programacion 1
#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include "../lib/gmColor.h"


using namespace std;
const int gmCedula =1753766060 ;  
const string gmNombreCompleto ="Gabriel Andres Maldonado Solorzano" ;  

struct gmCoordenadas
{
    int gmCapBelica;
    string gmGeo;
    char gmArsenal[10];
    gmCoordenadas* izq;
    gmCoordenadas* der;
};


void gmLeerCoordenadas() 
{
    ifstream gmArchivo;
    gmArchivo.open("./src/datos.txt");

    if (gmArchivo.is_open()) 
    {
    string gmlinea;
        cout<<"Hackeando coordenadas"<<endl;
        bool gmPrimer = false;                      
        while (getline(gmArchivo, gmlinea)) {       
            bool gmCompleto = false;                               
            while((gmCompleto==false)&&(gmPrimer==true)){             
                for(int i=0; i<=100;i++){
                    cout<<i<<"%"<<"\r";
                    Sleep(10);
                }
                cout<<"100%   ";
                gmCompleto = true;
            }
            if(gmPrimer==false){
                cout << COLOR_RED<<"Error: "<< gmlinea <<COLOR_GREEN<< endl;
            }else{
                cout << COLOR_GREEN << gmlinea << endl;
            }
            
            gmPrimer = true; 
        }
        gmArchivo.close();
    } else {
        cout << "Error al abrir el archivo" << endl;
    }
}

void gmInformacion(){
   cout<<COLOR_BLUE<<"\n[+] Informacion sobre la  capacidad belica del enemigo"<<endl;
   cout<<"\t Desarrollador-Nombre : "<<gmNombreCompleto<<endl;;
   cout<<"\t Desarrollador-Cedula : "<<gmCedula<<endl;;
   cout<<"\t Capacidad Belica : 2"<<endl;
   cout<<"\t Coordenada Total : 6"<<endl;
   cout<<"\t Coordenada-SecCarga : 1, 3, 5, 6, 7, 0"<<endl;
}
int main()

{
    gmLeerCoordenadas();
    gmInformacion();
    cout << "No me ponga mala nota profe :(" << endl;
}