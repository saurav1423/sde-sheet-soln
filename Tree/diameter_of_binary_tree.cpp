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
	static int diameterOpt(node* root, int &height)
    {
        if(root == NULL)
            return 0;
        int lh = diameterOpt(root->left, height);
        int rh = diameterOpt(root->right, height);
        
        height = max(height,(lh+rh));
        
        return 1+max(lh, rh);  
    }
};


/* Driver code*/
int main()
{   
	node* root = new node(1);
	root->left = new node(2);
	root->right = new node(3);
	root->left->left = new node(4);
	root->left->right = new node(5);
	
	int height = 0;
	// Function Call
	node::diameterOpt(root, height);
	cout<<height;

	return 0;
}
