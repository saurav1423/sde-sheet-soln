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

void printPreorder(Node* node)
{
	if (node == NULL)
        return;
  
    /* first print data of node */
    cout << node->data << " ";
  
    /* then recur on left subtree */
    printPreorder(node->left);
  
    /* now recur on right subtree */
    printPreorder(node->right);
}

int main()
{
	Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

	printPreorder(root);

	return 0;
}

Time Complexity: O(N) 



//iterative
vector<int> preorderTraversal(TreeNode* root) {
        
    vector<int> ans;
    stack<TreeNode*> st;
    st.push(root);
    
    if(root == NULL)
        return ans;
    
    while(!st.empty()){
        
        TreeNode* node = st.top();
        st.pop();
        ans.push_back(node->val);
        
        if(node->right)
            st.push(node->right);
        
        if(node->left)
            st.push(node->left);
        
    }
    
    return ans;
    
}

time - 0(N)
space - 0(N)