// usando referencia (&), que faz a mesma coisa q ponteiro, porem é diferente
// referencia ja faz toda aquela coisa d ponteiro pra vc, mais feguro
#include <iostream>

using namespace std;

void foo(const int &, int); // voce passa por referencia, porem nao pode alterar
 // e nao passa a copia(apenas numero), pq se torna mais rapido, nao tem q fazer uma copia gigante
 // oq acontece quand se passa o objeto

int main(int argc, char const *argv[])
{
	int a =1, b=2;

	foo(a,b);

	cout<< "Main" <<endl;
	cout << a << endl;
	cout << b << endl;


	return 0;
}

void foo(const int & a, int b){

	a =5;
	b =7;

	cout<< "Function" <<endl;
	cout<< a << endl;
	cout<< b << endl;
}
