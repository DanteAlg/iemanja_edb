//Definição e implementação da classe no, na sua vertente genérica
#ifndef NO_H
#define NO_H
#include <memory>

namespace minhasTads{

	// Declaracao antecipada da classe
	template <typename T> class no; 
	// Definicao antecipada do template para o operador de insercao
	template <typename T> std::ostream& operator<<( std::ostream&, no<T> const & );

	template <typename T>
	class no
	{
	private:
		// Elemento genérico que será usando com um no para um conteiner
		T valor;
		// Ponteiro que apontará para o próximo elemento no conteiner 
		std::shared_ptr<no<T>> proximo;
	public:		
		no();		
		no(T conteudo);		
		~no();		
		no(T num, std::shared_ptr<no> ProximoPtr);		
		T getValor();		
		std::shared_ptr<no<T>> getProximo();		
		void setProximo(std::shared_ptr<no<T>> ProximoPtr);		
		friend std::ostream& operator<< <T>(std::ostream &o, no<T> const &n);
	};

	// Construtor padrão para a classe no 
	template <typename T>
	no<T>::no() : valor(), proximo(nullptr) {}

	// Contrutor parametrizado para a classe no,recebe com parâmetro um elemento genérico do tipo T 
	template <typename T>
	no<T>::no(T conteudo) : valor(conteudo), proximo(nullptr) {}

	// Destrutor Classe no
	template <typename T>
	no<T>::~no() {}

	// Construtor parametrizado para a classe no,recebe com parâmetro um elemento genérico do tipo T
	// e um ponteiro para um objeto do tipo no
	template <typename T>
	no<T>::no(T conteudo, std::shared_ptr<no<T>> ProximoPtr) : valor(conteudo), proximo(ProximoPtr) {}

	// Retorna o valor armazenado em um no
	template <typename T>
	T no<T>::getValor()
	{
		return valor;
	}

	// Retorna um ponteiro para o elemento posterio ao objeto que o chamou 
	template <typename T>
	std::shared_ptr<no<T>> no<T>::getProximo() 
	{
		return proximo;
	}

	// Setter para quem o no está apontando
	template <typename T>
	void no<T>::setProximo(std::shared_ptr<no<T>> ProximoPtr) 
	{
		proximo = ProximoPtr;
	}

	// Sobrecarga do operador <<
	template <typename T>
	std::ostream& operator<< (std::ostream &o, no<T> const &n)
	{
		o << n.valor;
		return o;
	}

}
#endif