#include <bits/stdc++.h>
using namespace std;

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
	static vector<int> leftView(node *root)
    {
       vector<int> ans;
       node::helper(ans, root, 0);
       return ans;   
    }
    private:
    static void helper(vector<int> &ans, node* root, int level){
        if(root == NULL)
           return;
        
        if(ans.size() == level)
           ans.push_back(root->data);
        
        helper(ans, root->left, level+1);
        helper(ans, root->right, level+1);
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
	root->right->left = new node(6);
	root->right->right = new node(7);
	root->right->left->right = new node(8);
	root->right->right->right = new node(9);
	root->right->right->left = new node(10);
	root->right->right->left->right = new node(11);
	root->right->right->left->right->right = new node(12);
	cout << "left view of bt is \n";
	vector<int>ans = node::leftView(root);
	for(int v : ans){
		cout<<v<<" ";
	}
	cout<<"\n";
	return 0;
}

time - 0(N)
space - 0(N)