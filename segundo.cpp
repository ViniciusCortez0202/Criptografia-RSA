using namespace std;

void criarCriptografia(string mensagem, long long int chave, long long int e);
void encriptar(string texto, vectorDados &numerosEncriptados, long long int chave, long long int e);
void escrever_file(vectorDados numeros);


void criarCriptografia(string mensagem, long long int chave, long long int e){
	
	vectorDados numeros;
	encriptar(mensagem, numeros, chave, e);
    escrever_file(numeros);
}


void encriptar(string texto, vectorDados &numerosEncriptados, long long int chave, long long int e){
	vectorDados numeros;

	converterLetra(texto, numeros);
	
	for(vectorDados::iterator i = numeros.begin(); i != numeros.end(); i++){
		numerosEncriptados.push_back(classeEquivalente(*i, *i, e, chave));
		
  	}	
}

void escrever_file(vectorDados numeros){
    FILE *file;
    
    file = fopen("criptografado.txt", "w");

	
	for(vectorDados::iterator i = numeros.begin(); i != numeros.end(); i++){
		fprintf(file, "%lld ", *i);
  	}

    fclose(file);

}
