#include "vigenere.hpp"
using namespace std;

VIGENERE::VIGENERE (string men, string cla)
{
  mensaje = men;
  clave = cla;
  cifrado.clear();
  descifrado.clear();
}

VIGENERE::~VIGENERE(void){}

string VIGENERE::get_mensaje(void)
{
  return mensaje;
}

string VIGENERE::get_clave(void)
{
  return clave;
}

string VIGENERE::get_cifrado(void)
{
  return cifrado;
}

string VIGENERE::get_descifrado(void)
{
  return descifrado;
}

void VIGENERE::set_cifrado (string cad)
{ 
  cifrado = cad;
  mensaje.clear();
}

void VIGENERE::set_mensaje(string cad)
{
  mensaje = cad;
}

//Pasa a mayúscula y limpia los espacios en blanco
string VIGENERE::preparar_cadena(string cad)
{
  int i=0;
  string aux;
  
  while (cad[i]){
    if (cad[i] != ' ')
      aux += toupper(cad[i]);
    i++;
  }
  return aux;
}

//Prepara todas las cadenas dadas por el usuario para su cifrado/descifrado
void VIGENERE::preparar(void)
{
  mensaje = preparar_cadena (mensaje);
  clave = preparar_cadena(clave);
}

//Busca un caracter y devuelve su posicion en el alfabeto
int VIGENERE::buscar (char c)
{
  int max = sizeof(ABC);
  for (int i=0; i<max; i++)
    if (c == ABC[i])
      return i;
  return -1; //ese caracter no existe en el alfabeto
}


//Cifrar el mensaje dado por el usuario a partir de la clave aportada por el mismo
void VIGENERE::cifrar(void)
{
  unsigned max_abc = sizeof(ABC);
  unsigned max_m = mensaje.size();
  unsigned max_c = clave.size();
  
  int j= -1;
  for (int i=0; i< max_m; i++)
  {
      if (j == (max_c-1))
	j=0;
      else
	j++;
      int aux = buscar(mensaje[i]) + buscar(clave[j]);
      if (aux > (max_abc - 1))
	aux = aux % max_abc;
      cifrado += ABC[aux];
  }
}

//Descifrar
void VIGENERE::descifrar(void)
{
  unsigned max_abc = sizeof(ABC);
  unsigned max_m = cifrado.size();
  unsigned max_c = clave.size();
  
  int j= -1;
  for (int i=0; i< max_m; i++)
  {
      if (j == (max_c-1))
	j=0;
      else
	j++;
      int aux = buscar(cifrado[i]) - buscar(clave[j]);
      if (aux < 0)
	aux = aux + max_abc;
      descifrado += ABC[aux];
  }
}