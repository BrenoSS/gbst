#include "Node.hpp"
#include "Tree.hpp"
#include <iostream>

int main(int argv, char** argc)
{

	typedef gbst::Node<int>  intNode;
	typedef gbst::Tree<int> 	intTree;

	typedef gbst::Node<double>	doubleNode;
	typedef gbst::Tree<double> 	doubleTree;

	bool status;

	int values1[11] = {10, 12, 11, 9, 50, 30, 23, 7, 90, 8, 10};

	double values2[11] = {1.0, 1.2, 0.9, 5.0, 3.0, 2.3, 0.7, 9.0, 0.8, 1.0, 9.0};

	intNode* Node1 = new intNode(10);

	intNode* Node2 = new intNode(20);

	intNode* Node3 = new intNode(30);

	Node1->left = Node2;
	Node1->right = Node3;

	std::cout << Node1 << std::endl;

	std::cout << Node1->right << std::endl;

	std::cout << Node1->left << std::endl;

	intTree* Tree1 = new intTree();

	doubleTree* Tree2 = new doubleTree();

	for(int i = 0; i < 11; i++)
	{
		std::cout<<"Inserting value " << values1[i] << std::endl;
		status = Tree1->insert( values1[i] );
		std::cout<<status<<std::endl;
		if(!status)
		{
			std::cout << values1[i] << " wasn't inserted on tree"<< std::endl;
		}
	}

	// Tree1->insert( 10 );

	intNode* Tree1root = Tree1->getRoot();

	std::cout << Tree1root << std::endl;

	std::cout << Tree1root->left << std::endl;

	std::cout << Tree1root->right << std::endl;


	int valueTest = 50;

	if(Tree1->isInTree(valueTest))
	{
		std::cout << "Value " << valueTest << " is in Tree." << std::endl;
	}else{
		std::cout << "Value " << valueTest << " isn't in Tree." << std::endl;
	}

	std::cout << "Printing tree - preorder - before" << std::endl;


	Tree1->printTree( 0 );

	std::cout << "Deleting elem" << values1[1] <<std::endl;

	bool ok = Tree1->deleteElem(values1[1]);

	if(ok)
		std::cout<< "Elem " << values1[1] << " successfully deleted" << std::endl;

	std::cout << "Printing tree - preorder - after" << std::endl;


	Tree1->printTree( 0 );

	std::cout << "Deleting tree" << std::endl;

	free(Tree1);


	for(int i = 0; i < 11; i++)
	{
		std::cout<<"Inserting value " << values2[i] << std::endl;
		status = Tree2->insert( values2[i] );
		if(!status)
		{
			std::cout << values2[i] << " wasn't inserted on tree"<< std::endl;
		}
	}

	std::cout << "Printing tree - inorder" << std::endl;

	Tree2->printTree( 1 );

	double valueTest2 = 7.9;

	if(Tree2->isInTree(valueTest2))
	{
		std::cout << "Value " << valueTest2 << " is in Tree." << std::endl;
	}else{
		std::cout << "Value " << valueTest2 << " isn't in Tree." << std::endl;
	}


}