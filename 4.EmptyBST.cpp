#include <iostream>
#include <queue>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
Node* insert(Node* root, int val) {
    if (root == NULL) {
        return new Node(val);
    }
    if (val < root->data) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    return root;
}
int longestPath(Node* root) {
    if (root == NULL) return 0;
    return 1 + max(longestPath(root->left), longestPath(root->right));
}
int minValue(Node* root) {
    if (root == NULL) return -1; 
    while (root->left != NULL) {
        root = root->left;
    }
    return root->data;
}
bool search(Node* root, int val) {
    if (root == NULL) {return false;}
    if (root->data == val) {return true;}
    if (val < root->data) {return search(root->left, val);}
    else {return search(root->right, val);}
}
int main() {
    Node* root = NULL;
    int n, value;
    cout << "Enter the number of nodes in BST: ";
    cin >> n;
    cout << "Enter the values to be inserted: ";
    for (int i = 0; i < n; ++i) {
        cin >> value;
        root = insert(root, value);
    }
    int newValue;
    cout << "Enter the value of new node to be inserted: ";
    cin >> newValue;
    root = insert(root, newValue);
    int longest = longestPath(root);
    cout << "Number of nodes in longest path from root: " << longest << endl;
    int minVal = minValue(root);
    cout << "Minimum value in the tree: " << minVal << endl;
    
   
    int searchValue;
    cout << "Enter the value to search: ";
    cin >> searchValue;
    if (search(root, searchValue)) {
        cout << searchValue << " found in the tree." << endl;
    } else {
        cout << searchValue << " not found in the tree." << endl;
    }
    
    return 0;
}
