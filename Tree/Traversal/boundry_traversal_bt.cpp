#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
and a pointer to right child */
struct Node {
	int data;
	struct Node *left, *right;
};

// Utility function to create a new tree node
Node* newNode(int data)
{
	Node* temp = new Node;
	temp->data = data;
	temp->left = temp->right = nullptr;
	return temp;
}

bool isLeaf(Node* root){
    return !root->left && !root->right;
}

void addLeftBoundry(Node* root, vector<int> &ans){
    Node* curr = root->left;
    while(curr){
        if(!isLeaf(curr)){
            ans.push_back(curr->data);
        }
        if(curr->left)
            curr = curr->left;
        else
            curr = curr->right;
    }
}

void addLeaf(Node* root, vector<int> &ans){
    if(isLeaf(root)){
        ans.push_back(root->data);
        return;
    }
    if(root->left)
        addLeaf(root->left, ans);
    if(root->right)
        addLeaf(root->right, ans);
}

void addRightBoundry(Node* root, vector<int> &ans){
    vector<int> temp;
    Node* curr = root->right;
    while(curr){
        if(!isLeaf(curr)){
            temp.push_back(curr->data);
        }
        if(curr->right)
            curr = curr->right;
        else
            curr = curr->left;
    }
    
    for(int i=temp.size()-1; i>=0; i--)
        ans.push_back(temp[i]);
}

 vector <int> boundary(Node *root)
{
    vector<int> ans;
    if(root == NULL)
        return ans;
    if(!isLeaf(root))   
        ans.push_back(root->data);
    addLeftBoundry(root, ans);
    addLeaf(root, ans);
    addRightBoundry(root, ans);
    return ans;
}

int main()
{
	// Let us construct the tree given in the above diagram
	Node* root = newNode(20);
	root->left = newNode(8);
	root->left->left = newNode(4);
	root->left->right = newNode(12);
	root->left->right->left = newNode(10);
	root->left->right->right = newNode(14);
	root->right = newNode(22);
	root->right->right = newNode(25);

	vector<int>ans = boundary(root);
	for(int v : ans){
		cout<<v<<" ";
	}
	cout<<"\n";

	return 0;
}

//Code done by Balakrishnan R (rbkraj000)
