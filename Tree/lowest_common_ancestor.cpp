
TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q) {

    if(root == NULL || root == p || root == q)
       return root;

    TreeNode* left = lca(root->left, p, q);
    TreeNode* right = lca(root->right, p, q);

    if(left == NULL)   
       return right;

    else if(right == NULL)   
       return left;

    else
       return root;   

}

Naive approch will be to first find path from root to node(print_root_to_node.cpp) for both p and q. Then traverse for both and find where they are not common
and print it.

eg  -  p = 3, 5, 6
       q = 3, 5, 2, 4

it break continuity at 2, so 5 is answer       