//Definição e implementação da classe fila, na sua vertente genérica
#ifndef FilaCircular_H
#define FilaCircular_H
#include "listacircular.h"
#include <iostream>
#include <memory>

namespace minhasTads{

	// Declaracao antecipada da classe
	template <typename T> class fila; 
	// Definicao antecipada do template para o operador de insercao
	template <typename T> std::ostream& operator<<( std::ostream&, fila<T> const & ); 
	
	template <typename T>
	class fila
	{
	private:
		// Todos os elementos da fila serão armazenados em uma Listacircular
		minhasTads::lista<T> lista;
		// Armazena a quantidade de elementos que estão na fila
		int tam;
	public:
		
		fila();		
		~fila();		
		bool insere(T content);		
		bool tira();		
		int tamanho();		
		bool vazia();		
		T frente();		
		T atras();		
		friend std::ostream& operator<< <T>( std::ostream&, fila<T> const &l);
	};

	//Construtor padrão 
	template <typename T>
	fila<T>::fila():  tam(0) {}

	// Destrutor padrão
	template <typename T>
	fila<T>::~fila() 
	{	
		int n = tam;
		for(int i = 0; i < n; i++)
			this->tira();
	}

	// Retorna true se a fila está vázia, caso contrário, retorna verdadeiro
	template <typename T>
	bool fila<T>::vazia()
	{
		bool r = (tam == 0) ? true : false;
		return r; 
	}

	// Coloca um ume elemento na fila, ou seja, coloca o elemento como o último elemento da fila
	template <typename T>
	bool fila<T>::insere(T content) 
	{

		if(this->tam == 0)
		{
			this->tam++;
			return lista.insere_frente( content);
		} 
			this->tam++;
		return lista.insere_atras( content);
	}

	// Remove o primeiro elemento da fila 
	template <typename T>
	bool fila<T>::tira() {
		if( lista.tira_frente() == true)
		{
			this->tam--;
			return true;
		}

		return false;
	}

	// Retorna o tamanho da Fila, ou seja, a quantidade de elementos que estão na fila
	template <typename T>
	int fila<T>::tamanho()
	{
		return this->tam;
	}

	//Sobrecarga do operador <<, retorna um std::ostream com todos os elementos da fila
	// em uma linha separados por espaço
	template <typename T>
	std::ostream& operator<< ( std::ostream& o, fila<T> const &l) 
	{
		if(l.tam==0)
		{
			o << "**| Fila vazia |** " ;
			return o;
		}
			o << l.lista ;
		return o;
	}

	// Acessa o elemento que está na frente da fila
	template <typename T>
	T fila<T>::frente()
	{
		return this->lista.frente();
	}

	// Acessa o elemento que está na última possição 
	template <typename T>
	T fila<T>::atras()
	{
		return this->lista.atras();
	}


}
#endif