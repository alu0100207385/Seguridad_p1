#include <iostream>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>

using namespace std;

const char ABC[]= {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
  
class VIGENERE
{
  //ATRIBUTOS
  string mensaje;
  string clave;
  string cifrado;
  string descifrado;
  //FUNCIONES
public:
  VIGENERE (string men, string cla);
  ~VIGENERE(void);
  string get_mensaje(void);
  string get_clave(void);
  string get_cifrado(void);
  string get_descifrado(void);
  void set_cifrado (string cad);
  void set_mensaje(string cad);
  string preparar_cadena(string cad);
  void preparar(void);
  int buscar (char c);
  void cifrar(void);
  void descifrar(void);
};
