#include <stdlib.h>
#include <set>
#include <math.h>

using namespace std;

long long int classeEquivalente(long long int valor, long long int dado, long long int exp, long long int modulo);

 long long int classeEquivalente(long long int valor, long long int dado, long long int exp, long long int modulo){
	
	 if(exp == 1){
		 return dado;
	 }
	 long long int classe = (dado * valor) % modulo;
	 return classeEquivalente(valor, classe, --exp, modulo);
}


