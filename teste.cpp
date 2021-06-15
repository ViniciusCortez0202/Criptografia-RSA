#include <stdio.h>
#include <math.h>
#include <iostream>
#include "inverso.cpp"
#include "conversao.cpp"
#include "equivalencia.cpp"

using namespace std;

int main(int argc, char** argv)
{
	 long long int p = 17, q = 23, e = 3;
	
	
	vectorDados numeros;
	vectorDados numerosEncriptados;
	vectorDados numerosDescriptados;
	string texto = "E U T";

	converterLetra(texto, numeros);
	long long int inverso = calcularInversa(e, ((p-1) * (q-1)));
	
		
	for(vectorDados::iterator i = numeros.begin(); i != numeros.end(); i++){
		numerosEncriptados.push_back(classeEquivalente(*i, *i, e, p*q));
  	}
	
	for(vectorDados::iterator i = numerosEncriptados.begin(); i != numerosEncriptados.end(); i++){
		numerosDescriptados.push_back(classeEquivalente(*i, *i, inverso, p*q));
  	}
  	
	for(vectorDados::iterator i = numeros.begin(); i != numeros.end(); i++){
		cout << *i << " ";
  	}
  	cout << endl;
	for(vectorDados::iterator i = numerosEncriptados.begin(); i != numerosEncriptados.end(); i++){
		cout << *i << " ";
  	}
  	cout << endl;
	for(vectorDados::iterator i = numerosDescriptados.begin(); i != numerosDescriptados.end(); i++){
		cout << *i << " ";
  	}
  	cout << endl;
  	cout << converterNumeros(numerosDescriptados) << endl;
	
	return 0;
}