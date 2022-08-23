// C++ program to see if two trees are identical
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
and a pointer to right child */
class node
{
	public:
	int data;
	node* left;
	node* right;
	node (int data){
	    this->data = data;
	    left = right = NULL;
	}
	static int maxDepth(node* node)
    {
        if(node == NULL)
          return 0;
        
        int left = maxDepth(node->left);
        int right = maxDepth(node->right);
        
        return 1 + max(left, right);
    
    }
};


/* Driver code*/
int main()
{   
	node *root = new node(1);

	root->left = new node(2);
	root->right = new node(3);
	root->left->left = new node(4);
	root->left->right = new node(5);
	
	cout << "Height of tree is " << node::maxDepth(root);
	return 0;
}
