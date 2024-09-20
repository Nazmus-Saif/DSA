#include <iostream>
using namespace std;

// Define the structure of a node in the Splay Tree
struct Node {
    int key;      // Key value of the node
    Node* left;   // Pointer to the left child
    Node* right;  // Pointer to the right child
    
    // Constructor to initialize the node
    Node(int key) : key(key), left(nullptr), right(nullptr) {}
};

// Function to perform a right rotation
Node* rightRotate(Node* x) {
    Node* y = x->left;
    x->left = y->right;
    y->right = x;
    return y;
}

// Function to perform a left rotation
Node* leftRotate(Node* x) {
    Node* y = x->right;
    x->right = y->left;
    y->left = x;
    return y;
}

// Function to splay the tree
Node* splay(Node* root, int key) {
    // If the tree is empty or the key is already the root, return the root
    if (!root || root->key == key) return root;

    // If the key to be splayed is in the left subtree
    if (root->key > key) {
        // If the left subtree is empty, return the root
        if (!root->left) return root;

        // Zig-Zig (Left Left)
        if (root->left->key > key) {
            // Recursively splay the left-left grandchild
            root->left->left = splay(root->left->left, key);
            // Perform a right rotation
            root = rightRotate(root);
        }
        // Zig-Zag (Left Right)
        else if (root->left->key < key) {
            // Recursively splay the left-right grandchild
            root->left->right = splay(root->left->right, key);
            // If the left-right grandchild is not null, perform a left rotation
            if (root->left->right) root->left = leftRotate(root->left);
        }
        // Perform a right rotation if the left child is not null
        return (root->left) ? rightRotate(root) : root;
    }
    // If the key to be splayed is in the right subtree
    else {
        // If the right subtree is empty, return the root
        if (!root->right) return root;

        // Zag-Zig (Right Left)
        if (root->right->key > key) {
            // Recursively splay the right-left grandchild
            root->right->left = splay(root->right->left, key);
            // If the right-left grandchild is not null, perform a right rotation
            if (root->right->left) root->right = rightRotate(root->right);
        }
        // Zag-Zag (Right Right)
        else if (root->right->key < key) {
            // Recursively splay the right-right grandchild
            root->right->right = splay(root->right->right, key);
            // Perform a left rotation
            root = leftRotate(root);
        }
        // Perform a left rotation if the right child is not null
        return (root->right) ? leftRotate(root) : root;
    }
}

// Function to insert a node in the Splay Tree
Node* insert(Node* root, int key) {
    if (!root) return new Node(key);

    root = splay(root, key);

    if (root->key == key) return root;

    Node* newNode = new Node(key);
    if (root->key > key) {
        newNode->right = root;
        newNode->left = root->left;
        root->left = nullptr;
    } else {
        newNode->left = root;
        newNode->right = root->right;
        root->right = nullptr;
    }
    return newNode;
}

// Function to delete a node from the Splay Tree
Node* deleteNode(Node* root, int key) {
    // If the tree is empty, return null
    if (!root) return nullptr;

    // Splay the tree with the key
    root = splay(root, key);

    // If the key is not found, return the root
    if (root->key != key) return root;

    Node* temp;
    // If the left child is null
    if (!root->left) {
        // Store the root node
        temp = root;
        // Make the right child the new root
        root = root->right;
    }
    // If the left child is not null
    else {
        // Store the root node
        temp = root;
        // Splay the left subtree with the key
        root = splay(root->left, key);
        // Make the right child of the original root the right child of the new root
        root->right = temp->right;
    }
    // Delete the old root
    delete temp;
    // Return the new root
    return root;
}

// Function to search a node in the Splay Tree
Node* search(Node* root, int key) {
    return splay(root, key);
}

// Function for in-order traversal of the Splay Tree
void inOrderTraversal(Node* root) {
    if (root) {
        inOrderTraversal(root->left);
        cout << root->key << " ";
        inOrderTraversal(root->right);
    }
}

int main() {
    Node* root = nullptr;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    cout << "Inorder traversal of the modified Splay tree is \n";
    inOrderTraversal(root);
    cout << endl;

    root = deleteNode(root, 20);
    cout << "Inorder traversal after deletion of 20 \n";
    inOrderTraversal(root);
    cout << endl;

    root = search(root, 30);
    cout << "Inorder traversal after searching for 30 \n";
    inOrderTraversal(root);
    cout << endl;

    return 0;
}