vector<int> solve(TreeNode* A, int B){

   vector<int> ans;
   if(root == NULL)
     return ans;
   getPath(A, ans, B);
   return ans;  
    
}

bool getPath(TreeNode* root, vector<int> &arr, int x){

   if(root == NULL)
      return false;
   
   arr.push_back(root->val);
   if(root->val == x)
      return true;

   if(getPath(root->left, arr, x) || getPath(root->right, arr, x))   
      return true;

   arr.pop_back();
   return false;   

}