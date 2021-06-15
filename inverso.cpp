#include <map>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct 
{
	long long int resultado;
	long long int classe;
	long long int fator;
	long long int resto;
}equacao;

typedef struct 
{
	long long int resultado;
	long long int modulo;
	long long int classe;
	long long int fator;
}equacaoReorganizada;

typedef map<long long int, equacao> mapResultados;
typedef vector<equacao> vectorEquacoes; 


long long int somarModulo(long long int classe,  long long int modulo);
long long int calcularInversa(long long int classe, long long int modulo);
void criarEquacoes(long long int classe, long long int modulo, vectorEquacoes &valoresEquacoes);
void reorganizarEquacoes(vectorEquacoes &valoresEquacoes, mapResultados &resultados);

long long int somarModulo(long long int classe,  long long int modulo){
	return classe > 0 ? classe : somarModulo((classe + modulo), modulo);
}

long long int calcularInversa(long long int classe, long long int modulo){
	
	mapResultados resultados;
	vectorEquacoes equacoes;
	
	criarEquacoes(classe, modulo, equacoes);
	reorganizarEquacoes(equacoes, resultados);
	
	long long int classeResultado = 0;
	
	if(resultados.size() == 1){
		mapResultados::iterator i = resultados.begin();
		classeResultado =  i->second.fator;
		goto apenas;
	}
	
	for(mapResultados::iterator i = --(--resultados.end()); i != (--resultados.begin()); i--){

		//valores da equacao
		long long int primeiro = 1, segundo = 0;
		
		if(i->second.resto != classe){
			primeiro = resultados[i->second.resto].fator; 
		}
		
		segundo = resultados[i->second.classe].fator * i->second.fator;
		
		i->second.fator = primeiro + segundo;

		classeResultado = i->second.fator;
	}
	apenas:
	return classeResultado < 0 ? somarModulo(classeResultado, modulo) : classeResultado;
}

void criarEquacoes(long long int classe, long long int modulo, vectorEquacoes &valoresEquacoes){
	
	vectorEquacoes::iterator i = valoresEquacoes.end() - 1;
	equacao eq;
	eq.resultado = modulo;
	eq.classe = classe;
	
	long long int fator, resto = modulo;
	
	
	/*
		if(modulo % raizModulo != 0){
		fator = raizModulo;
	 	resto = modulo % raizModulo;
	} else {
		fator = raizModulo - 1;
		resto = modulo % (raizModulo - 1);
	}
	*/
	
	for(long long int i = 1; i < modulo; ++i){
		if(modulo - (classe * i) < 0) break;
		if(abs(modulo - (classe * i)) < resto){
			fator = i;
		 	resto = modulo - (classe * i);
		}
	}
	
	eq.fator = fator;
	eq.resto = resto;
	
	valoresEquacoes.push_back(eq);
	
	if(resto == 1){
		return;
	}
	criarEquacoes(resto, classe, valoresEquacoes);		
}

void reorganizarEquacoes(vectorEquacoes &valoresEquacoes, mapResultados &resultados){
	
	for(vectorEquacoes::iterator i = valoresEquacoes.begin(); i != valoresEquacoes.end(); i++){
		
		swap(i->resultado, i->resto);
		
		i->fator *= -1;
		resultados[i->resultado] = *i;
		
	}
	
}

