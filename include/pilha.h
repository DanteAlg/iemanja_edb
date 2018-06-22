//Definição e implementação da classe pilha, na sua vertente genérica
#ifndef PILHA_H
#define PILHA_H
#include <iostream>
#include <memory>
#include "listacircular.h"

namespace minhasTads {

	// Declaracao antecipada da pilha
	template <typename T> class pilha; 
	// Definicao antecipada do template para o operador de insercao
	template <typename T> std::ostream& operator<< ( std::ostream&, lista<T> const &);

	template <typename T>
	class pilha
	{
	private:
		minhasTads::lista<T> pilha_fila;
		//Quantidade de elementos que estão sendo guardados na pilha
		int tam;    
	public:
		pilha();
		~pilha ();		
		bool vazia();
		T topo();
		bool insere ( T novo );
		void tira ();
		int tamanho();
		//Sobrecarga do operador <<, retorna um std::ostream com todos os elementos
		// da lista em uma linha separados por espaço - Falta implementar
		friend std::ostream& operator<< <T>( std::ostream&, lista<T> const &l);

	};
	//Construtor padrão, que instanciará a pilha com tamanho igual a zero
	template <typename T>
	pilha<T>::pilha (): tam(0){}

	//Destrutor padrão
	template <typename T>
	pilha<T>::~pilha ()
	{
		int n = tam;
		for(int i = 0; i < n; i++)
			this->tira();
	}

	//Método que verifica se a pilha esta vazia ou não
	template <typename T>
	bool pilha<T>::vazia ()
	{
		return tam == 0;
	}

	//Método de empilhamento
	template <typename T>
	bool pilha<T>::insere ( T novo )
	{
		 this->tam++;
		 return pilha_fila.insere_atras(novo);
	}
	
	//Método de desempilhamento	
	template <typename T>
	void pilha<T>::tira ()
	{
		//Verifica se a pilha está vazia. Se sim exibe mensagem de erro, se não, executa o desempilhamento	
		if(vazia()) 
		{
			std::cout << std::endl << "Erro: pilha vazia!" << std::endl;
		}
		else
		{
			this->tam--;
			pilha_fila.tira_atras();
		}
	
	}

	//Método de acesso ao elemento do topo da pilha
	template <typename T>
	T pilha<T>::topo()
	{	
		// Verificação da existência de elementos na pilha. Se pilha vazia exibe mensagem, senão
		// retorna o elemento do topo. 
		if (vazia()) 
		{
			std::cerr << "Não há mais expressões para serem executadas. O programa sera fechado!" << std::endl;
			exit(EXIT_FAILURE);
		}
		return pilha_fila.atras();
	}

	// Método de verficação do tamanho da pilha
	template <typename T>
	int pilha<T>::tamanho ()
	{
		return tam;
	}

}
#endif 