
               1
             /   \  
            2     5
          /        \         
         8          7 
        /            \ 
       12             6 


if we give numbering to every node, we can solve the problem. eg 1 will get 1, 2 will get 2, 5 will get 3, 8 will get 4
2 dont have right child so, we assume 5 got assigned to it, 5 dont have left child, so we assume 6 got assigned to it. Doing that way
12 will have number 8 and 6 will have number 15, ans = 15-8+1 

but, if we give numbering to every node, it will cause overflow. So we will subtract min of above level before giving.

one more thing
for any node, left node is curr_id*2+1, and right node is curr_id*2+2

int width(TreeNode* root){

   if(root == NULL)
      return 0;
    int ans = 0;
    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});

    while(!q.empty()){
        
        int size = q.size();
        int mmin = q.front().second;
        int first, last;

        for(int i=0; i<size; i++){

            int curr_id = q.front().second - mmin;
            TreeNode* node = q.front().first;
            q.pop();

            if(i == 0)
               first = curr_id;

            if(i == size-1)
               last = curr_id;

            if(node->left)      
               q.push({node->left, curr_id*2+1});

            if(node->right)      
               q.push({node->right, curr_id*2+2});
        }

        ans = max(ans, last-first+1);

    }  

   return ans;
}