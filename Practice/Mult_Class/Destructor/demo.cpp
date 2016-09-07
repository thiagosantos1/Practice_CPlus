// **** Very important ****
// Destructor it's a constructor, porem ele roda sempre apos o scope dos objetos
// depois que nao a temos mais, sendo assim usamos ele para limpar a memoria
// porem nao acontece automaticamente, vc deve usar o comando delete objetc;
// ou voce pode usar para outras milhares funcionalidades
// por exemplo um class onde temos a conexao com o banco de dados
// e apos terminar essa conexao, poremos usar o destructor para "limpar" o objeto
// usado e fechar a conexao do BD
// Sendo assim, usamos esse constructor para limpar ponteiros em nossa class,
// objetos referenciados, principalmente um vetor, pois a logica é
// limpar espaço em memoria que foi alocada dinamicamente

#include <iostream>
using namespace std;

class Foo
{
public:
	 Foo(int n_){

	 	n = n_;
	 	cout << "Foo constructor" << n<< endl;
	 }
	

	 // it's run after the scope of the object ends
	 ~Foo(){

	 	<<"Destructor " << n;

	 }

private:
	int n;
};


int  main(int argc, char const *argv[])
{
	Foo a(1);
	Foo b(2);


	if(1==1){

		Foo c(3);
	}

	return 0;


}