#include <iostream>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int value;          // The value of the node
    TreeNode* left;     // Pointer to the left child
    TreeNode* right;    // Pointer to the right child

    // Constructor to initialize a new node
    /* TreeNode(int val) {
        value = val;
        left = NULL;
        right = NULL;
    } */
};

// So if we not use the Structure Constructor then we can achieve the same thing by the following function

TreeNode* create(int val){
    TreeNode* node = new TreeNode;
    node->value = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert a node in the binary tree
TreeNode* insert(TreeNode* root, int value) {
    // If the tree is empty, return a new node
    if (root == NULL) {
        //return new TreeNode(value);
        return create(value);
    }

    // Otherwise, insert the node in the correct position
    if (value < root->value) {
        root->left = insert(root->left, value); // Recursive Call
    } else {
        root->right = insert(root->right, value); // Recursive Call
    }

    return root;
}

// Function to perform in-order traversal of the binary tree
void inOrderTraversal(TreeNode* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);   // Traverse the left subtree
        cout << root->value << " ";     // Visit the root node
        inOrderTraversal(root->right);  // Traverse the right subtree
    }
}

// Function to perform pre-order traversal of the binary tree
void preOrderTraversal(TreeNode* root) {
    if (root != NULL) {
        cout << root->value << " ";     // Visit the root node
        preOrderTraversal(root->left);  // Traverse the left subtree
        preOrderTraversal(root->right); // Traverse the right subtree
    }
}

// Function to perform post-order traversal of the binary tree
void postOrderTraversal(TreeNode* root) {
    if (root != NULL) {
        postOrderTraversal(root->left);  // Traverse the left subtree
        postOrderTraversal(root->right); // Traverse the right subtree
        cout << root->value << " ";      // Visit the root node
    }
}

// Function to search for a value in the binary tree
TreeNode* searchElement(TreeNode* root, int value) {
    // Base cases: root is null or value is found at root
    if (root == NULL || root->value == value) {
        return root;
    }

    // Value is greater than root's value, so search in the right subtree
    if (value > root->value) {
        return searchElement(root->right, value);
    }

    // Value is smaller than root's value, so search in the left subtree
    return searchElement(root->left, value);
}

// Function to find minimum value node in a given BST
TreeNode* minValueNode(TreeNode* node) {
    TreeNode* current = node;

    // Loop down to find the leftmost leaf
    while (current != NULL && current->left != NULL) {
        current = current->left;
        // in this we look in current->left not right because The left subtree of a node contains only nodes with values less than the root’s value 
    }

    return current;
}

// Function to delete a node from the binary tree
TreeNode* deleteNode(TreeNode* root, int value) {
    // Base case: root is null
    if (root == NULL) {
        return root;
    }

    // If the value to be deleted is smaller than the root's value, then it lies in the left subtree
    if (value < root->value) {
        root->left = deleteNode(root->left, value);
    }
    // If the value to be deleted is greater than the root's value, then it lies in the right subtree
    else if (value > root->value) {
        root->right = deleteNode(root->right, value);
    }
    // If value is same as root's value, then this is the node to be deleted
    else {
        // Node with only one child or no child
        if (root->left == NULL) { // Left side has no child
            TreeNode* temp = root->right;
            delete root;
            return temp; // The right child of the current node is returned to replace the deleted node in the BST.
        } else if (root->right == NULL) { // Right side has no child
            TreeNode* temp = root->left;
            delete root;
            return temp; // The left child of the current node is returned to replace the deleted node in the BST.
        }

        // Node with two children: Get the inorder successor (smallest in the right subtree)
        TreeNode* temp = minValueNode(root->right); // The inorder successor is the node with the smallest value in the right subtree of the current node.

        // Copy the inorder successor's content to this node
        root->value = temp->value;
        // The value of the inorder successor (temp->value) is copied to the current node (root).
        // This effectively replaces the value of the node to be deleted with the value of the inorder successor.

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->value);
    }
    return root;
}

// Main function
int main() {
    TreeNode* root = NULL;  // Start with an empty tree

    // Insert nodes into the binary tree
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    // Perform in-order traversal to display the tree
    cout << "In-order traversal: ";
    inOrderTraversal(root);
    cout << endl;

    // Perform pre-order traversal to display the tree
    cout << "Pre-order traversal: ";
    preOrderTraversal(root);
    cout << endl;

    // Perform post-order traversal to display the tree
    cout << "Post-order traversal: ";
    postOrderTraversal(root);
    cout << endl;

    // Search for a value in the tree
    int searchValue = 60;
    TreeNode* searchResult = searchElement(root, searchValue);
    if (searchResult != NULL) {
        cout << "Found value " << searchValue << " in the tree." <<  endl;
    } else {
        cout << "Value " << searchValue << " not found in the tree." << endl;
    }

    // Delete a node from the tree
    int deleteValue = 30;
    root = deleteNode(root, deleteValue);
    cout << "In-order traversal after deleting " << deleteValue << ": ";
    inOrderTraversal(root);
    cout << endl;

    return 0;
}