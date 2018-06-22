#ifndef  LISTACIRCULAR_H
#define  LISTACIRCULAR_H
#include <memory>
#include <iostream>
#include "no.h"

using std::shared_ptr;
using std::make_shared;
using std::cout;
using std::endl;
using std::string;

namespace minhasTads{
	template <typename T> class lista; // Declaracao antecipada da classe
	template <typename T> std::ostream& operator<<( std::ostream&, lista<T> const & ); // Definicao antecipada do template para o operador de insercao

	template <typename T>
	class lista
	{
		// cauda é  um ponteiro que ira apontar para o último nó da lista
		shared_ptr<no<T>> cauda;
		// O atributo tamanho mastra quantos elementos estão atualmente na lista 
		int tam;
	public:		
		lista();		
		~lista();		
		bool insere_frente(T conteudo);
		bool insere_atras(T conteudo);
		bool insere(unsigned int pos, T conteudo);
	 	bool tira_frente();		
		bool tira_atras();		
		bool apaga(unsigned int pos);		
		T retorna(unsigned int pos);		
		bool vazia();		
	    int tamanho();	    
	    T frente();	    
	    T atras();
		friend std::ostream& operator<< <T>( std::ostream&, lista<T> const &l);
	};

	// Construtor padrão classe lista
	template <typename T>
	lista<T>::lista(): cauda(nullptr), tam(0)  {}

	// Destrutor classe lista
	template <typename T>
	lista<T>::~lista() 
	{
		if(tam != 0)
		{
		auto atual = this->cauda->getProximo(); // primeiro elemento 
		int posAtual = 0;
		
			while ( posAtual != tam-1) { // percorre a lista até  o elemento com a posição passada como argumento
				cauda->setProximo(atual->getProximo()->getProximo()); 
				atual = atual->getProximo();
				posAtual++;
			}
			this->cauda->setProximo(nullptr);
		}
		
		tam =0;

	}

	// Retorna se a lista está ou não vázia
	template <typename T>
	bool lista<T>::vazia()
	{
		bool r = (this->tam == 0) ? true : false;
		return r; 
	}

	// Retorna o tamanho da lista, isto é, a quatidade de nós
	template <typename T>
	int lista<T>::tamanho() 
	{
		return this->tam;
	}

	//Insere um elemento no ínicio da lista, retorna true se não houve erro, caso contrário, retorna false
	template <typename T>
	bool lista<T>:: insere_frente(T conteudo)
	{
		if (this->tam == 0) 
		{
			auto  novo = make_shared<no<T>>(conteudo); //Recebo o novo conteudo e o coloco em novo
			if (!novo) return false; // Se ocorreu algum problema na alocação retorna falso 
			novo->setProximo(novo); //Como é circula, e só há elemento então ele é reflexivo, pois é o primeiro e último ao mesmo tempo
			this->cauda = novo; // a cauda apota para o último elemento
			this->tam++;
			return true;

		}
		else 
		{
			auto antigo_primeiro = this->cauda->getProximo(); //Antigo_primeiro será aquele que é apontado pelo último
			auto novo_primeiro = make_shared<no<T>>(conteudo); // novo elemento da fila
			this->cauda->setProximo(novo_primeiro); // o último aponta para o novo primeiro 
			this->cauda->getProximo()->setProximo(antigo_primeiro);// novo primeiro aponta para antigo primeiro
			this->tam++;
		}
		return true;
	}

	//Insere um elemento no final da lista, retorna true se não houve erro, caso contrário retorna false
	template <typename T>
	bool lista<T>::insere_atras(T conteudo) {
		
		if(this->tam == 0) // Se não há nada na fila
		{
			return  insere_frente(conteudo);
		}
		else 
		{

			auto penultimo = this->cauda; // penultimo aponta para o último atualmente na fila
			auto novo_ultimo  = make_shared<no<T>>(conteudo); // o novo último recebe o novo valor para a lista  
			
			novo_ultimo->setProximo(penultimo->getProximo()); // o novo último aponta para onde o penultimo apontava, no caso o primeiro 
			penultimo->setProximo(novo_ultimo); // o penultimo aponta para o novo último
			this->cauda = novo_ultimo; // cauda aponta para o novo último
			this->tam++; // acrescentasse em 1 o tamanho da fila
		}
		return true;
	}

	// Insere um elemento em uma posição passada n da lista
	template <typename T>
	bool lista<T>::insere(unsigned int pos, T conteudo) 
	{
		if (pos<0 || pos>= tam) return false;
		if (pos==0)	return  insere_frente(conteudo);

		auto atual = this->cauda->getProximo();
		int posAtual = 0;

		while (atual->getProximo() != this->cauda && posAtual < pos-1) 
		{
			atual = atual->getProximo();
			posAtual++;
		}
		
		auto novo = make_shared<no<T>>(conteudo);
		if (!novo) return false;

		novo->setProximo(atual->getProximo());
		atual->setProximo(novo);
		this->tam++;
		return true;
	}

	// Retorna o lemento em um índice passado 
	template <typename T>
	T lista<T>::retorna(unsigned int pos)
	{
		//TODO colocar uma exceção aqui tmabém 
		if (pos<0 || pos>= tam)
		{
			std::cerr << "ERRO a possição não existe na lista \n";
			exit(1);
		}

		auto atual = this->cauda->getProximo(); // primeiro elemento 
		int posAtual = 0;

		while ( posAtual != pos) 
		{ // percorre a lista até  o elemento com a posição passada como argumento 
			atual = atual->getProximo();
			posAtual++;
		}

		return atual->getValor();
	}

	// Remove o elemento que está no íncio da lista, retorna true se não houve erro, caso contrário, retorna false
	template <typename T>
	bool lista<T>::tira_frente() 
	{
		if (this->tam <= 0) //Será verdadeira quando a fila estiver vázia
		{ 
			return false;
		} 
		else if (this->tam == 1) // Será verdadeira quando há apenas um elemento na fila 
		{
			
			this->cauda->setProximo(nullptr); // A cauda aponta para o primeiro elemento, assim o primeiro elemento agora aponta para nulo
			this->cauda = nullptr; // A cauda é um ponteiro nullo
			this->tam--;
			return true;
		} 
		else
		{
			this->cauda->setProximo(this->cauda->getProximo()->getProximo()); // o novo primeiro será, aquele que é apontado pelo primeiro
			this->tam--;
			return true;
		}
	}

	// Remove o lemento que está ao final da lista,retorna true se não houve erro, caso contrário, retorna false
	template <typename T>
	bool lista<T>::tira_atras() 
	{
		if (this->cauda==nullptr ) 
			return false;// Se lista vázia 

		if (this->tam == 1 )
		{  // Se lista com apenas um elmento 
			return tira_frente();
		}

		auto atual = this->cauda->getProximo();
		while (atual->getProximo()->getProximo() != this->cauda)
		{ // depois desse larço o atual será o antepenúltimo
			atual = atual->getProximo();
		}

		atual->getProximo()->setProximo(this->cauda->getProximo()); // como atual é o antepenúltimo, atual->getProximo() será o penúltimo,  penúltimo aponta para o primeiro 
		this->cauda = atual->getProximo(); // cauda aponta para o novo penúltimo
		this->tam--;
		return true;
	}

	// Remove o elemento na posição que foi recebida como parêmetro( lembra que o índide inicia-se em 0),retorna true se não houve erro, caso contrário, retorna false
	template <typename T>
	bool lista<T>::apaga(unsigned int pos) 
	{

		//if (pos < 0) return false; 
		if (pos == 0)	return tira_frente();
		if (pos == this->tam -1 ) return tira_atras();
		if (pos > this->tam  ) return false ;

		auto atual = this->cauda->getProximo();
		int posAtual = 0;
		while (atual->getProximo()->getProximo() != this->cauda && posAtual < (pos-1)) 
		{
			atual = atual->getProximo();
			posAtual++;
		}

		atual->setProximo(atual->getProximo()->getProximo());
		this->tam--;

		return true;
	}

	template <typename T>
	std::ostream& operator<< ( std::ostream& o, lista<T> const &l) 
	{
		auto atual = l.cauda->getProximo();
		int  i =0;
		while ( i != l.tam) 
		{
			o << atual->getValor() << " ";
			atual = atual->getProximo();
			i++;
		}
		return o;
	}

	// Retorna o primeiro elemento da lista, caso vázio retorna nullptr 
	template <typename T>
	T lista<T>::frente()
	{
		
		if (this->tam <= 0) 
		{ 
			cout << "ERRO: lista vazia, o programa será finalizado \n";
			exit(1);
		} 
		else
		{
			return this->cauda->getProximo()->getValor();
		}
	}

	// Retorna o último elemento da lista, caso vázio retorna nullptr  
	template <typename T>
	T lista<T>::atras()
	{
		
		if (this->tam <= 0) 
			{ 
				cout << "ERRO lista vazia, O programa será finalizado \n";
				exit(1);
			} 
			else
			{
				return this->cauda->getValor();
			}

	}

}

#endif