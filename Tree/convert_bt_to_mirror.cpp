ques -         1                        1
            /     \                   /   \
           3       2     ---->       2     3
                 /  \               / \
                5    4             4   5 


//recursive
void mirror(Node* node) {
        
      if(node == NULL)
      return;
      
      mirror(node->left);
      mirror(node->right);
      swap(node->left, node->right);
      
}

//iterative
void mirror(Node* node) {
        
      queue<Node*> q;
      if(node == NULL)
      return;
      q.push(node);
      while(!q.empty()){
      Node* temp = q.front();
      q.pop();
      swap(temp->left, temp->right);
      if(temp->left)
            q.push(temp->left);
      if(temp->right)
            q.push(temp->right);
      }
      
}