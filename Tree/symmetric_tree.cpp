ques-          1
             /   \
            2     2
          /  \   /  \
         3   4  4    3


it is same ques as "check_for_mirror.cpp". difference is that, there we had two tree to check, here we will pass         
root->left as one tree and root-right as other tree


bool helper(node* a, node* b) {

    if(a == NULL && b == NULL)
       return true;
    if(a == NULL || b == NULL)
       return false;

    return a->data == b->data && helper(a->left, b->right) && helper(a->right, b->left);      
}

bool isSymmetric(TreeNode* root){
    if(root == NULL)
      return true;

    return helper(root->left, root->right);  

}