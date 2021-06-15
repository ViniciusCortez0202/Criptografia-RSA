#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <string>
#include <iostream>
#include "conversao.cpp"
#include "equivalencia.cpp"
#include "primeiro.cpp"
#include "segundo.cpp"
#include "terceiro.cpp"

using namespace std;

int main() {
    int i;
    int p, q, r, e;
    string mensagem_encriptar;
    long long int chave_publica;

	do{
		printf("Bem vindo! Escolha uma das 3 opcoes:\n1 - Gerar chave publica,\n2 - Encriptar,\n3 - Desencriptar.\n0 - Sair\n\n");
    scanf("%d", &i);

    switch (i) {
        case 1:
            criarChave();
            break;
        case 2:

            printf("Digite a mesagem de texto a encriptar:\n");
            getchar();
            getline(cin, mensagem_encriptar);
            
            for(register int i = 0; i < mensagem_encriptar.size(); i++){
				mensagem_encriptar[i] = toupper(mensagem_encriptar[i]);
			}

            printf("Digite a chave publica recebida previamente:\n");
            scanf("%lld", &chave_publica);
            printf("Digite o expoente:");
            scanf("%d", &e);
            
            criarCriptografia(mensagem_encriptar, chave_publica, e);
            
            break;
        case 3:
        	chave:
            printf("Digite 'p', 'q', e 'e':\n");
            scanf("%d %d %d", &p, &q, &e);
            if(!validacao(p, q, e)){
				printf("\n\n");
				goto chave;
			}
			descriptografar(p, q, e);
            
            break;
        case 0: 
        	exit(0);
        default:
            printf("Opcao invalida!\n");
            break;

    }
	}while(true);
	
    

    return 0;
}