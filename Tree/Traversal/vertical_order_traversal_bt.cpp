#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	Node *left, *right;
};

// A function to create a new node
Node* newNode(int key)
{
	Node* node = new Node;
	node->data = key;
	node->left = node->right = NULL;
	return node;
}

//logic is , we will give every node, x and y value and then store it in map, and then group them by y axis value
//using multiset as on same x,y 2 node with same value can exist(eg - [3,1,4,0,2,2])
vector<vector<int>> verticalTraversal(Node* root) {
        
    map<int, map<int, multiset<int>>>nodes;
    queue<pair<Node*, pair<int, int>>> q;
    
    q.push({root, {0, 0}});
    
    while(!q.empty()){
        
        auto p = q.front();
        q.pop();
        
        Node* node = p.first;
        int x = p.second.first, y = p.second.second;
        nodes[x][y].insert(node->data);
        
        if(node->left)
            q.push({node->left, {x-1, y+1}});
        if(node->right)
            q.push({node->right, {x+1, y+1}});
        
    }
    vector<vector<int>> ans;
    //this for loop is running on map where we are grouping nodes that have same y axis value
    for (auto p : nodes) {
        vector<int> col;
        for (auto q : p.second) {
            col.insert(col.end(), q.second.begin(), q.second.end());
        }
        ans.push_back(col);
    }
    return ans;
    
    
}

// Driver program to test above functions
int main()
{
	Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->right->right = newNode(7);
	root->right->left->right = newNode(8);
	root->right->right->right = newNode(9);
	root->right->right->left = newNode(10);
	root->right->right->left->right = newNode(11);
	root->right->right->left->right->right = newNode(12);
	cout << "Vertical order traversal is \n";
	verticalTraversal(root);
    //print kr lena
	return 0;
}

time - 0(NlogN), logN for inserting in map
sc - 0(N) as we are storing all the nodes