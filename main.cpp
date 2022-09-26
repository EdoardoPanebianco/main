#include "dist_succ.h"

int main() {


	BST<int> bst;
	
	
	bst.insert(40);
	bst.insert(25);
	bst.insert(21);
	bst.insert(18);
	bst.insert(57);
	bst.insert(36);
	bst.insert(46);
	bst.insert(32);
	bst.insert(78);
	bst.insert(52);
	bst.insert(11);
	bst.insert(44);
	
	bst.inorder();
	
	std::cout << "MIN & MAX" << std::endl << *(bst.min()) << std::endl;
	std::cout << *(bst.max()) << std::endl;
	
	std::cout << "Test successore" << std::endl;
	
	std::cout << "Il successore di " << *(bst.getRoot()) << " è " << *(bst.successor(bst.getRoot())) << std::endl;
	std::cout << "Il successore di " << *(bst.search(21)) << " è " << *(bst.successor(bst.search(21))) << std::endl;
	
	std::cout << "SEARCH" << std::endl;
	std::cout << "search(18)" << (bst.search(18) ? "found" : "not found") << std::endl;
	std::cout << "search(8)" << (bst.search(8) ? "found" : "not found") << std::endl;
	
	std::cout << "la distanza del valore: 32 dal suo successore è di: "<<bst.dist_successor(32)<<" archi"<< std::endl;
	std::cout << "la distanza del valore: 40 dal suo successore è di: "<<bst.dist_successor(40)<<" archi"<< std::endl;
	

	BST<char> cbst;
	
	
	cbst.insert('N');
	cbst.insert('Y');
	cbst.insert('L');
	cbst.insert('J');
	cbst.insert('Q');
	cbst.insert('H');
	cbst.insert('E');
	cbst.insert('G');
	cbst.insert('A');
	cbst.insert('B');
	cbst.insert('C');
	cbst.insert('X');
	
	cbst.inorder();
	
	std::cout << "Test successore" << std::endl;
	
	std::cout << "Il successore di " << *(cbst.getRoot()) << " è " << *(cbst.successor(cbst.getRoot())) << std::endl;
	std::cout << "Il successore di " << *(cbst.search('Q')) << " è " << *(cbst.successor(cbst.search('Q'))) << std::endl;
	
	std::cout << "la distanza del valore: C dal suo successore è di: "<<cbst.dist_successor('C')<<"archi"<< std::endl;
	std::cout << "la distanza del valore: Q dal suo successore è di: "<<cbst.dist_successor('Q')<<"archi"<< std::endl;
	
	
}
