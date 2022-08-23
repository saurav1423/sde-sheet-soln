#include <iostream>
using namespace std;
 
// Data structure to store a binary tree node
class Node
{
    public:
        int key;
        Node *left, *right;
     
        Node(int key)
        {
            this->key = key;
            this->left = this->right = nullptr;
        }
};
 
// Function to print all nodes of a given level from left to right
bool printLevel(Node* root, int level)
{
    if (root == nullptr) {
        return false;
    }
 
    if (level == 1)
    {
        cout << root->key << " ";
 
        // return true if at least one node is present at a given level
        return true;
    }
 
    bool left = printLevel(root->left, level - 1);
    bool right = printLevel(root->right, level - 1);
 
    return left || right;
}
 
void levelOrderTraversal(Node* root)
{
    // start from level 1 — till the height of the tree
    int level = 1;
 
    // run till printLevel() returns false
    while (printLevel(root, level)) {
        level++;
    }
}
 
int main()
{
    Node* root = new Node(15);
    root->left = new Node(10);
    root->right = new Node(20);
    root->left->left = new Node(8);
    root->left->right = new Node(12);
    root->right->left = new Node(16);
    root->right->right = new Node(25);
 
    levelOrderTraversal(root);
 
    return 0;
}

time - O(N^2)

//iterative
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    queue<TreeNode*> q;
    if(root == NULL)
        return ans;
    q.push(root);
    
    while(!q.empty()){
        int k = q.size();
        vector<int> temp;
        
        for(int i=0; i<k; i++){
            TreeNode* node = q.front();
            q.pop();
            temp.push_back(node->val);
            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
        }
        ans.push_back(temp);
            
    }
    
    return ans;
    
}

time - 0(N)
space - 0(N)