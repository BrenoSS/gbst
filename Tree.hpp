#ifndef TREE_HPP
#define TREE_HPP

#include "Node.hpp"
#include <iostream>
#include <cstddef>
#include <assert.h>

namespace gbst{

	template < class T > class Tree
	{
	private:

		Node<T>* root;

		Node<T>* insert( Node<T>* R, T value, bool& status );

		void printTreePreOrder( Node<T>* R );

		void printTreeInOrder( Node<T>* R );

		bool isInTree( T value, Node<T>* R );

		Node<T>* deleteElem( T value, Node<T>* R, bool& status );

		T findMinValueSubtree( Node<T>* R );

		void deleteTree( Node<T>* R );

	public:

		Tree() 	{	root = NULL; }

		Tree( T value )
		{
			root = NULL;
			insert( value );
		}

		~Tree();

		Node<T>* getRoot()	{ return root; }

		bool insert( T value );

		void printTree( int type );

		bool isInTree( T value );

		bool deleteElem( T value );

	};

	template < class T > Tree<T>::~Tree()
	{
		deleteTree( root );
		root = NULL;
	}

	template < class T > bool Tree<T>::insert( T value )
	{
		bool status = false;
		if(root == NULL)
		{
			root = insert(root, value, status);
		}else{
			insert(root, value, status);
		}
		return status;
	}


	template < class T > Node<T>* Tree<T>::insert( Node<T>* R, T value, bool& status )
	{
		if( R == NULL )
		{
			// std::cout << "INSERTING VALUE: "<< value << std::endl;
			Node<T>* node = new Node<T>( value ); //left and right are initialized as NULL in node's constructor
			status = true;
			return node;
		}

		if( R->getStoredValue() == value )
		{
			// std::cout << "Repeated value: " << value << std::endl;
			status = false;
			return R;
		}

		if( value > R->getStoredValue() )
		{
			// std::cout << "Inserting value " << value << " on the right of value " << R->getStoredValue() << std::endl;
			R->right = insert( R->right, value, status );
		}else{
			// std::cout << "Inserting value " << value << " on the left of value " << R->getStoredValue() << std::endl;
			R->left = insert( R->left, value, status );
		}

		return R;
	}


	template < class T > void Tree<T>::printTree( int type )
	{
		Node<T>* R = root;

		assert( type >=0 and type <=1 );

		if( type == 0 )
			printTreePreOrder( R );
		else
			printTreeInOrder( R );

	}

	template < class T > void Tree<T>::printTreePreOrder( Node<T>* R )
	{
		if( R!=NULL )
		{
			std::cout<< R << std::endl;
			printTreePreOrder( R->left );
			printTreePreOrder( R->right );
		}
	}

	template < class T > void Tree<T>::printTreeInOrder( Node<T>* R )
	{
		if( R!=NULL )
		{
			printTreePreOrder( R->left );
			std::cout<< R << std::endl;
			printTreePreOrder( R->right );
		}
	}

	template < class T > bool Tree<T>::isInTree( T value )
	{
		return isInTree( value, root );
	}

	template < class T > bool Tree<T>::isInTree( T value, Node<T>* R )
	{
		if( R==NULL )
			return false;
		else{
			if( R->getStoredValue() == value )
				return true;
			else{
				if( value > R->getStoredValue() )
					return isInTree( value, R->right );
				else
					return isInTree( value, R->left );
			}
		}
	}

	template < class T > T Tree<T>::findMinValueSubtree( Node<T>* R )
	{
		Node<T>* iterator = R;

		while( iterator->left!=NULL )
			iterator = iterator->left;

		return iterator->getStoredValue();
	}

	template < class T > bool Tree<T>::deleteElem( T value )
	{
		bool status;
		deleteElem( value, root, status );
		return status;
	}

	template < class T > Node<T>* Tree<T>::deleteElem( T value, Node<T>* R, bool& status )
	{
		if( R==NULL )
		{
			status = false;
			return R;
		}
		if( value > R->getStoredValue())
		{
			R->right = deleteElem( value, R->right, status);
		}else{
			if( value < R->getStoredValue() )
			{
				R->left = deleteElem( value, R->left, status);
			}else{

				if( value==R->getStoredValue() )
				{
					status = true;
					if((R->left == NULL) and (R->right == NULL))
					{
						free(R);
						return NULL;
					}else{
						if((R->left == NULL) and (R->right != NULL))
						{
							Node<T>* aux = R->right;
							free(R);
							return aux;
						}else{
							if((R->left != NULL) and (R->right == NULL))
							{
								Node<T>* aux = R->left;
								free(R);
								return aux;
							}else{ //both left and right are not null

								T minValue = findMinValueSubtree( R->right );
								R->setStoredValue( minValue );

								R->right = deleteElem( minValue, R->right, status );

							}
						}
					}
				}
			}
		}

		return R;
	}

	template < class T > void Tree<T>::deleteTree( Node<T>* R )
	{
		if( R == NULL )
			return;

		deleteTree( R->left );
		deleteTree( R->right );

		std::cout << "Deleting node " << R << std::endl;
		free(R);
	}

}

#endif