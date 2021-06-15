bool eh_primo(long long int n);
bool mdc(long long int a, long long int b);
void gerar_codigo();
bool validacao(long long int p, long long int q, long long int e);

bool eh_primo(long long int n){
    int mod, i = 2;

	if(n == 1) return false;
	if(n == 2) return true;
	
    for(i=2; i*i<=n; i++){
        mod = n%i;
        if(mod == 0){
            return false;
        }
    }
    return true;
}

bool mdc(long long int a, long long int b){
 
    if(b == 1) return true;
    if(b == 0) return false;
    
	return mdc(b, a % b);
}

bool validacao(long long int p, long long int q, long long int e){
	if(!eh_primo(p) || !eh_primo(q)){
        printf("Um dos numeros nao eh primo!\n");       
        return false;
    }
    if(!mdc(p-1, e) || !mdc(q-1, e)){
		printf("e nao eh coprimo com q e p");		
		return false;
	}
	return true;
}

void criarChave() {
    long long int p, q, e;

	novo:
    printf("Digite dois numeros primos: \n");
    scanf("%lld", &p);
    scanf("%lld", &q);

    printf("Digite agora o expoente: \n");
    scanf("%lld", &e);

	if(!validacao(p, q, e)) {
		printf("\n\n");
		goto novo;
	}
	
    long long int chave = p*q;
    
    char nomeArquivo[1000];
    
    sprintf(nomeArquivo, "%lld.txt", chave);
    
    FILE *output = fopen(nomeArquivo, "w");

    if (output == NULL){
        printf("ERRO NA CRIAÇÃO DO ARQUIVO!!!");
        return;
    }
    
    fprintf(output, "chave = %lld e = %lld", chave, e);

	printf("chave = %lld e = %lld\n", chave, e);
	
    fclose (output);
 
}