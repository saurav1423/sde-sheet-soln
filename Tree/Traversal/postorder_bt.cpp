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

void printPostorder(struct Node* node)
{
    if (node == NULL)
        return;
  
    // first recur on left subtree
    printPostorder(node->left);
  
    // then recur on right subtree
    printPostorder(node->right);
  
    // now deal with the node
    cout << node->data << " ";
}

int main()
{
	Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

	printPostorder(root);

	return 0;
}

Time Complexity: O(N) 

//iterative
vector<int> postorderTraversal(TreeNode* root) {
        
        //left->right->root
        //root->left->right
    
    vector<int> ans;
    stack<TreeNode*> st;
    
    if(root == NULL)
        return ans;
    
    st.push(root);
    
    while(!st.empty()){
        
        TreeNode* node = st.top();
        st.pop();
        ans.push_back(node->val);
        
        if(node->left)
            st.push(node->left);
        
        if(node->right)
            st.push(node->right);
        
    }
    
    reverse(ans.begin(), ans.end());
    return ans;
    
    
}

time - 0(N)
space - 0(N)