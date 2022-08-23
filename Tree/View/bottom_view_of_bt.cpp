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
	static vector<int> bottomView(node *root)
    {
        vector<int> ans;
        if(root == NULL)
           return ans;
        map<int, int> umap;
        queue<pair<node*, int>> q;
        q.push({root, 0});
        while(!q.empty()){
            node* temp = q.front().first;
            int line = q.front().second;
            q.pop();
            
            umap[line] = temp->data;
            
            if(temp->left)
               q.push({temp->left, line-1});
               
            if(temp->right)
               q.push({temp->right, line+1});   
        }
        
        for(auto itr: umap){
            ans.push_back(itr.second);
        }
        return ans;
    }
};

// Driver program to test above functions
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
	cout << "bottom view of bt is \n";
	vector<int>ans = node::bottomView(root);
	for(int v : ans){
		cout<<v<<" ";
	}
	cout<<"\n";
	return 0;
}

time - 0(NlogN) logN for map
space - 0(2N) one for queue, one for map