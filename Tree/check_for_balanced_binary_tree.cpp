//Balanced binary tree is that tree whose, at any node, abs(lh-rh)<=1

// C++ code to implement the approach

#include <bits/stdc++.h>
using namespace std;

// Structure of a tree node
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
	static int isBalanced(node* root)
    {
    	if(root == NULL)
          return 0;
        int lh = isBalanced(root->left);
        if(lh == -1)
          return -1;  //doing this and rh == -1, to handle case when a node get -1 from both lh and rh, as its abs(lh - rh) will be 0
        int rh = isBalanced(root->right);
        if(rh == -1)    
          return -1;
        if(abs(lh - rh)>1)
          return -1;
    
        return 1 + max(lh, rh);    
    }
};

eg - [1,2,2,3,null,null,3,4,null,null,4]

// Driver code
int main()
{   
	node* root = new node(10);
	root->left = new node(5);
	root->right = new node(30);
	root->right->left = new node(15);
	root->right->right = new node(20);

	if (node::isBalanced(root))
		cout << "Balanced";
	else
		cout << "Not Balanced";
	return 0;
}


time - 0(N)