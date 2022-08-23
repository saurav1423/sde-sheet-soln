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
	static bool identicalTrees(node* r1, node* r2)
    {
    	if(r1 == NULL && r2 == NULL)
               return true;
            if(r1 == NULL || r2 == NULL)  
               return false;
            
        return r1->data == r2->data && identicalTrees(r1->left, r2->left) && identicalTrees(r1->right, r2->right);   
    }
};


/* Driver code*/
int main()
{   
	node *root1 = new node(1);
	node *root2 = new node(1);
	root1->left = new node(2);
	root1->right = new node(3);
	root1->left->left = new node(4);
	root1->left->right = new node(5);

	root2->left = new node(2);
	root2->right = new node(3);
	root2->left->left = new node(4);
	root2->left->right = new node(5);

	if(node::identicalTrees(root1, root2))
		cout << "Both tree are identical.";
	else
		cout << "Trees are not identical.";

return 0;
}
