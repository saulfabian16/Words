#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int lineCounter(string str,string palabra){
  int found;
  int count=0;
  int i=0;
  while(1){
    found=str.find(palabra,i);
    i=found+1;
    if(found!=-1) count++;
    else break;
  }
  return count;
}

int contador(string archivo, string palabra){
  int count=0;
  string linea;
  ifstream myfile;
  myfile.open(archivo.c_str());
  if(myfile.is_open())
  while(getline(myfile,linea))
  count+=lineCounter(linea,palabra);
  else cout<<"Error al abrir el archivo"<<endl;
  myfile.close();
  return count;
}


int main(){
  int resp;
  string archivo, palabra;
  cout<<"Este programa calculara cuantas veces sale una palabra en un texto"<<endl;
  cout<<"Escriba el nombre del texto (EJEMPLO: texto.txt)"<<endl;
  cin >> archivo;
  cout<<"¿Qué palabra quieres que busque?: ";
  cin >> palabra;
  resp=contador(archivo, palabra);
  cout<<"La palabra aparece: "<< resp << " veces";
}
