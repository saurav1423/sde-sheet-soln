ques -         1                        1
            /     \                   /   \
           3       2     check       2     3
                 /  \               / \
                5    4             4   5 

bool areMirror(node* a, node* b) {

    if(a == NULL && b == NULL)
       return true;
    if(a == NULL || b == NULL)
       return false;

    return a->data == b->data && areMirror(a->left, b->right) && areMirror(a->right, b->left);      
}