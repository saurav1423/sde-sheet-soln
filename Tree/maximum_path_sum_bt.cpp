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
	static int findMaxSum(node* root, int &ans){
        if(root == NULL)
          return 0;
        int lh = findMaxSum(root->left, ans);
        int rh = findMaxSum(root->right, ans);
        
        int max1 = max(max(lh,rh)+root->data, root->data);
        int max2 = max(max1, root->data+lh+rh);
        
        ans = max(ans, max2);
        
        return max1;
    }
};


/* Driver code*/
int main()
{   
	node *root = new node(10);
	root->left	 = new node(2);
	root->right	 = new node(10);
	root->left->left = new node(20);
	root->left->right = new node(1);
	root->right->right = new node(-25);
	root->right->right->left = new node(3);
	root->right->right->right = new node(4);
	int ans = INT_MIN;
	node::findMaxSum(root, ans);
	cout<<ans;
	return 0;
}
