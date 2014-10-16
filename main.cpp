//ALUMNO: Aaron Socas Gaspar
//Seguridad curso 2013-2014
//Practica 1: Vigenere

#include "vigenere.hpp"
#include <unistd.h>
#include <string.h>

using namespace std;

//Menu
unsigned short menu(void)
{
  unsigned short op;
  do  {
      system ("clear");
      cout<<"\n\t\tCIFRADO VIGENERE"<<endl;
      cout<<"\n\t\t----------------"<<endl;
      cout<<"\n\t[1] Cifrar mensaje"<<endl;
      cout<<"\n\t[2] Descifrar mensaje"<<endl;
      cout<<"\n\t[3] Salir."<<endl;
      cin>>op;
  }while ((op<1)&&(op>3));
  return op;
}


//Compara los caracteres. Devuelve error si existe algun caracter invalido
bool buscar(char c)
{
    char abc[]= {' ','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    int MAX= sizeof(abc);
    for (int i=0; i<MAX; i++){
      if ((c==abc[i]) || (c==tolower(abc[i])))
	return true;
    }
    return false;
}

//Comprueba si se ha introducido algun caracter invalido en la cadena
bool control(string cad)
{
  int i=0;
  while (cad[i])  {
    if (!buscar(cad[i]))
      return false; //hay un caracter invalido
    i++;
  }
  return true;
}

int main (int argc, char* argv[])
{
  if (argc != 2)
  {
      cout<<"Error de argumentos"<<endl;
      cout<<"Introduzca 'cifrar' para cifrar o 'd' para descifrar."<<endl;
  }
  else
  {
      cout<<argv[1]<<endl;
      string aux=argv[1];
      string m, c;
      
      if (aux=="c")
      {
	  cout<<"Introduzca mensaje a cifrar: "<<endl;
	  getline(cin, m);
	  cout<<"Introduzca la clave: "<<endl;
	  getline(cin, c);
	  if ((control(m)) && (control(c)))
	  {
	      VIGENERE v(m,c);
	      v.preparar();
	      v.cifrar();
	      cout<<"Men original: "<<v.get_mensaje()<<endl;
	      cout<<"Clave	 : "<<v.get_clave()<<endl;
	      cout<<"Cifrado	 : "<<v.get_cifrado()<<endl;
	      cout<<"descifrando..."<<endl;
	      sleep(2);
	      v.descifrar();
	      cout<<"Mensaje	 : "<<v.get_descifrado()<<endl;
	  }
	  else
	    cout<<"Error. Cadena con caracteres invalidos."<<endl;
      }
      
      if (aux=="d")
      {
	  cout<<"Introduzca mensaje a descifrar: "<<endl;
	  getline(cin, m);
	  cout<<"Introduzca la clave: "<<endl;
	  getline(cin, c);
	  if ((control(m)) && (control(c)))
	  {
	      VIGENERE v(m,c);
	      v.preparar();
	      v.set_cifrado(m);
	      v.descifrar();
	      v.set_mensaje(v.get_descifrado());
	      cout<<"Men original: "<<v.get_mensaje()<<endl;
	      cout<<"Clave	   : "<<v.get_clave()<<endl;
	  }
	  else
	    cout<<"Error. Cadena con caracteres invalidos."<<endl;
      }
  }
  return 0;
}
