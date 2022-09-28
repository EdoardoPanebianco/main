#ifndef DIST_KEY_H
#define DIST_KEY_H


#include <iostream>
#include <climits>
#include "bst_node.h"

using namespace std;

template <typename H>
class BST{

        BSTNode<H>* root;
        
    public:
    int count= 0;
    
    BST (){
        root=nullptr;
    }
    
    bool isEmpty (){
        return root==nullptr;
    }
    
    BSTNode<H>* getRoot(){
       return this->root;
    }
    
    void insert (H key){
        if(this->isEmpty()){
            root = new BSTNode<H>(key);
        return;
        }
        insert (root, key);
    }
    
    void insert(BSTNode<H>* ptr, H key) {
		if(ptr->left == nullptr && key <= ptr->key) {
			ptr->left = new BSTNode<H>(key);
			ptr->left->setParent(ptr);
			return;
		}
		if(ptr->right == nullptr && key > ptr->key) {
			ptr->right = new BSTNode<H>(key);
			ptr->right->parent = ptr;
			return;
		}
		else if(key <= ptr->key)
			insert(ptr->left, key);
		else
			insert(ptr->right, key);
	}
    
    void visit(BSTNode<H>* node){
        cout<<*node<<endl;
    }
    
    void inorder(BSTNode<H>* ptr){
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
    
    BSTNode<H>* min() {
		return min(root);
	}
    
    BSTNode<H>* min(BSTNode<H>* from) {
		if(isEmpty()) {
			return NULL;
		}
		
		count++;
		BSTNode<H>* ptr = from;
		while(ptr->left) {
			ptr = ptr->left;
			count++;
		}
		
		return ptr;
	}
	
	BSTNode<H>* max() {
		return max(root);
	}
	
	BSTNode<H>* max(BSTNode<H>* from) {
		if(isEmpty()) {
			throw "Empty BST!";
		}
		
		BSTNode<H>* ptr = from;
		while(ptr->right) {
			ptr = ptr->right;
		}
		
		return ptr;
	}
    
	BSTNode<H>* successor(BSTNode<H>* x) {
		if(this->isEmpty()) {
			return nullptr;
		}
		
		// 1. x ha un sottoalbero destro
		
		if(x->right) 
			return this->min(x->right);
		
		// 2. x non ha un sottoalbero destro
		// il successore di x è l'antenato più prossimo di x
		// il cui figlio sinistro è anche un antenato di x
		
		BSTNode<H>* y = x->parent;
		
		while(x != nullptr && x == y->right) {
			x = y;
			y = y->parent;
		}
		
		return y;
		
	}
    
    BSTNode<H>* search(H key) {
		return search(root, key);
	}
	
	BSTNode<H>* search(BSTNode<H>* ptr, H key) {
		if(ptr == nullptr) 
			return nullptr;
		if(ptr->key == key)
			return ptr;
		
		if(key <= ptr->key){
			return search(ptr->left, key);
		}
		else{
			return search(ptr->right, key);
		}
		
		return nullptr;
	}
    
    int findLevel(BSTNode<H>* root,H k, int level)
{
    // Base Case
    if (root == NULL)
        return -1;
 
    // If key is present at root, or in left subtree
    // or right subtree, return true;
    if (root->key == k)
        return level;
 
    int l = findLevel(root->left, k, level+1);
    return (l != -1)? l : findLevel(root->right, k, level+1);
}

	BSTNode<H> *findDistUtil(BSTNode<H>* root, int n1, int n2, int &d1,
                            int &d2, int &dist, int lvl)
	{
    // Base case
    if (root == NULL) return NULL;
 
    // If either n1 or n2 matches with root's key, report
    // the presence by returning root (Note that if a key is
    // ancestor of other, then the ancestor key becomes LCA
    if (root->key == n1)
    {
         d1 = lvl;
         return root;
    }
    if (root->key == n2)
    {
         d2 = lvl;
         return root;
    }
 
    // Look for n1 and n2 in left and right subtrees
    BSTNode<H> *left_lca  = findDistUtil(root->left, n1, n2,
                                   d1, d2, dist, lvl+1);
    BSTNode<H> *right_lca = findDistUtil(root->right, n1, n2,
                                   d1, d2, dist, lvl+1);
 
    // If both of the above calls return Non-NULL, then
    // one key is present in once subtree and other is
    // present in other. So this node is the LCA
    if (left_lca && right_lca)
    {
        dist = d1 + d2 - 2*lvl;
        return root;
    }
 
    // Otherwise check if left subtree or right subtree
    // is LCA
    return (left_lca != NULL)? left_lca: right_lca;
	}
    
    int distanzaChiavi(BSTNode<H>* root,H h, H k)
    {
    // Initialize d1 (distance of n1 from root), d2
    // (distance of n2 from root) and dist(distance
    // between n1 and n2)
    int d1 = -1, d2 = -1, dist;
    BSTNode<H> *lca = findDistUtil(root, h, k, d1, d2,
                                          dist, 1);
 
    // If both n1 and n2 were present in Binary
    // Tree, return dist
    if (d1 != -1 && d2 != -1)
        return dist;
 
    // If n1 is ancestor of n2, consider n1 as root
    // and find level of n2 in subtree rooted with n1
    if (d1 != -1)
    {
        dist = findLevel(lca, k, 0);
        return dist;
    }
 
    // If n2 is ancestor of n1, consider n2 as root
    // and find level of n1 in subtree rooted with n2
    if (d2 != -1)
    {
        dist = findLevel(lca, h, 0);
        return dist;
    }
 
    return -1;
}
    
    int distanzaChiavi(H h, H k){
    	return distanzaChiavi(root, h, k);
    }
};

#endif
