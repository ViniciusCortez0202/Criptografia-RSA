#include <vector>
#include <map>
#include <string>
#include <stdlib.h>

using namespace std;

typedef vector<long long int> vectorDados;

static map<int, int> codigo;
static map<int, int> codigoReverso;


void converterLetra(string texto, vectorDados &numeros);
string converterNumeros(vectorDados &numeros);
int criarCodigo(int tipo);


//Tipo 1: Letras para Numeros;
//Tipo 2: Numeros para Letras;
int criarCodigo(int tipo){
	if(tipo == 1){
		int inicial = 'A';
		
		for(int i = 2; i < 28; i++){
			
			codigo[inicial++] = i;
				
		}
		codigo[' '] = 28;
		return 1;
	}
	if(tipo == 2){
		int inicial = 'A';
		for(int i = 2; i < 28; i++){
			codigoReverso[i] = inicial++;
		}
		codigo['28'] = ' ';
		return 1;
	}
	return 0;
}

void converterLetra(string texto, vectorDados &numeros){
	criarCodigo(1);
	
	for(register int i = 0; i < texto.size(); i++){
		int numero = codigo[texto[i]];
 		numeros.push_back(numero);
	}	
}

string converterNumeros(vectorDados &numeros){
	criarCodigo(2);
	
	char texto[numeros.size()];

	int size = 0;
	for(vectorDados::iterator i = numeros.begin(); i != numeros.end(); i++){
		texto[size++] = codigoReverso[*i] == 0 ? ' ' : codigoReverso[*i];	
		texto[size] = '\0';
	}

	return texto;
}
