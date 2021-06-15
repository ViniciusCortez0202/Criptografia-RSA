#include <stdlib.h>
#include "inverso.cpp"
#include <stdio.h>

using namespace std;


void lerArquivo(vectorDados &numeros);
void descriptografar(int p, int q, int e);
void escrever(vectorDados &numeros);

void lerArquivo(vectorDados &numeros){
	
	FILE *file;
    
    file = fopen("criptografado.txt", "r");
	long long int valor;
	
	if (file==NULL)
    {
        printf("Arquivo nao encontrado\n");
        return;
    }
    
	while(fscanf(file, "%lld", &valor) != EOF){
		numeros.push_back(valor);
	}
	fclose(file);  
}


void descriptografar(int p, int q, int e){
	
	vectorDados numeros;
	
	lerArquivo(numeros);
	
	vectorDados numerosDescriptados;
	
	long long int inverso = calcularInversa(e, (p-1)*(q-1));
	
	for(vectorDados::iterator i = numeros.begin(); i != numeros.end(); i++){
		numerosDescriptados.push_back(classeEquivalente(*i, *i, inverso, (p*q)));
	}
		
	escrever(numerosDescriptados);
}

void escrever(vectorDados &numeros){
    FILE *file;
    
    file = fopen("descriptado.txt", "w");

	string mensagem = converterNumeros(numeros);

	
	fprintf(file, "%s ", mensagem.c_str());
	
	
	/*for(vectorDados::iterator i = numeros.begin(); i != numeros.end(); i++){
		fprintf(file, "%lld ", *i);
  	}*/

    fclose(file);

}