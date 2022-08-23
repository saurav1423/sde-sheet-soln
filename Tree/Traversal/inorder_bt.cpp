#include <iostream>
using namespace std;

/* A binary tree node has data, pointer to left child
and a pointer to right child */
class Node {
	public:
      int data;
	  Node *left, *right;
};

//Utility function to create a new tree node
Node* newNode(int data)
{
	Node* temp = new Node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

void printInorder(Node* node)
{
	if (node == NULL)
		return;

	/* first recur on left child */
	printInorder(node->left);

	/* then print the data of node */
	cout << node->data << " ";

	/* now recur on right child */
	printInorder(node->right);
}

int main()
{
	Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

	printInorder(root);

	return 0;
}

Time Complexity: O(n) 



//iterative
vector<int> inorderTraversal(TreeNode* root) {
        
    vector<int> ans;
    stack<TreeNode*> st;
    TreeNode* curr = root;
    
    while(true){
        if(curr){
            st.push(curr);
            curr = curr->left;   
        }else{
            if(st.empty())
                break;
            curr = st.top();
            st.pop();
            ans.push_back(curr->val);
            curr = curr->right;
        }
            
    }
    return ans;
    
    
}

time - 0(N)
space - 0(N)