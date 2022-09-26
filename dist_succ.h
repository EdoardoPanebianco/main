#ifndef DIST_SUCC_H
#define DIST_SUCC_H


#include <iostream>
#include "bst_node.h"

using namespace std;

template <typename T>
class BST{

        BSTNode<T>* root;
        
    public:
    int count= 0;
    
    BST (){
        root=nullptr;
    }
    
    bool isEmpty (){
        return root==nullptr;
    }
    
    BSTNode<T>* getRoot(){
       return this->root;
    }
    
    void insert (T key){
        if(this->isEmpty()){
            root = new BSTNode<T>(key);
        return;
        }
        insert (root, key);
    }
    
    void insert(BSTNode<T>* ptr, T key) {
		if(ptr->left == nullptr && key <= ptr->key) {
			ptr->left = new BSTNode<T>(key);
			ptr->left->setParent(ptr);
			return;
		}
		if(ptr->right == nullptr && key > ptr->key) {
			ptr->right = new BSTNode<T>(key);
			ptr->right->parent = ptr;
			return;
		}
		else if(key <= ptr->key)
			insert(ptr->left, key);
		else
			insert(ptr->right, key);
	}
    
    void visit(BSTNode<T>* node){
        cout<<*node<<endl;
    }
    
    void inorder(BSTNode<T>* ptr){
        if(ptr == nullptr){
            return;
        }
        inorder(ptr->left);
        visit(ptr);
        inorder(ptr->right);
    }
    
    void inorder() {
        inorder (root);
    }
    
    BSTNode<T>* min() {
		return min(root);
	}
    
    BSTNode<T>* min(BSTNode<T>* from) {
		if(isEmpty()) {
			return NULL;
		}
		
		count=1;
		BSTNode<T>* ptr = from;
		while(ptr->left) {
			ptr = ptr->left;
			count++;
		}
		
		return ptr;
	}
	
	BSTNode<T>* max() {
		return max(root);
	}
	
	BSTNode<T>* max(BSTNode<T>* from) {
		if(isEmpty()) {
			throw "Empty BST!";
		}
		
		BSTNode<T>* ptr = from;
		while(ptr->right) {
			ptr = ptr->right;
		}
		
		return ptr;
	}
    
   BSTNode<T>* successor(BSTNode<T>* x) {
		if(this->isEmpty()) {
			return nullptr;
		}
		if(x->key ==max()->key)
			return nullptr;
		
		// 1. x ha un sottoalbero destro
		
		if(x->right) 
			return this->min(x->right);
		
		// 2. x non ha un sottoalbero destro
		// il successore di x è l'antenato più prossimo di x
		// il cui figlio sinistro è anche un antenato di x
		
		BSTNode<T>* y = x->parent;
		count++;
		
		while(x != nullptr && x == y->right) {
			x = y;
			y = y->parent;
			count++;
		
		return y;
		}
	}
    
    BSTNode<T>* search(T key) {
		return search(root, key);
	}
	
	BSTNode<T>* search(BSTNode<T>* ptr, T key) {
		if(ptr == nullptr) 
			return nullptr;
		if(ptr->key == key)
			return ptr;
		
		if(key <= ptr->key)
			return search(ptr->left, key);
		else
			return search(ptr->right, key);
		
		return nullptr;
	}
    
    int dist_successor(T x){
        BSTNode<T>* ptr= search(x);
        if(successor(ptr) == nullptr)
            return 0;
        else count=0;
        successor(ptr);
        return count;
    }
};

#endif
