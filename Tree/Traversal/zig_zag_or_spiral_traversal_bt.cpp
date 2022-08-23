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
	static vector<int> zigZagTraversal(node* root)
    {
        bool leftToRight = true;
        queue<node*> q;
        vector<int> ans;
        if(root == NULL)
            return ans;
        q.push(root);
        while(!q.empty()){
            
            int k = q.size();
            vector<int> temp(k, -1);
            for(int i=0; i<k; i++){
                node* tempNode = q.front();
                q.pop();
                int index = (leftToRight)?i:(k-i-1);
                temp[index] = tempNode->data;
                if(tempNode->left)
                    q.push(tempNode->left);
                if(tempNode->right)
                    q.push(tempNode->right);
            }
            for(int i=0; i<temp.size(); i++)
                ans.push_back(temp[i]);
            leftToRight = !leftToRight;     
            
        }
        
        return ans;
    }
};


/* Driver code*/
int main()
{
		// vector to store the traversal order.
	vector<int> v;

	// create tree
	node* root = new node(1);
	root->left = new node(2);
	root->right = new node(3);
	root->left->left = new node(7);
	root->left->right = new node(6);
	root->right->left = new node(5);
	root->right->right = new node(4);
	cout << "ZigZag Order traversal of binary tree is \n";

	v = node::zigZagTraversal(root);

	for (int i = 0; i < v.size(); i++) { // to print the order
		cout << v[i] << " ";
	}

	return 0;
}

