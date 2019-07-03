#ifndef NODE_HPP
#define NODE_HPP

#include <cstddef>
#include <iostream>


//gbt - generic binary tree
namespace gbst
{
	template <class T> class Node
	{
	private:
		T storedValue;
	
	public:

		Node<T>* left;
		Node<T>* right;

		Node()	{}
		Node(T value)
		{
			storedValue = value;
			left = NULL;
			right = NULL;
		}

		const T getStoredValue()	{ return storedValue; }

		void setStoredValue( T newValue )	{ storedValue = newValue; }

		std::ostream& print( std::ostream& out )	{ return out << storedValue; }
	};

	template< class T > std::ostream& operator<<( std::ostream& out, Node<T> t ) { return t.print( out ); }

	template< class T > std::ostream& operator<<( std::ostream& out, Node<T>* t ) { return t->print( out ); }
}


#endif