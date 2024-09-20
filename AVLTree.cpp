#include <iostream>
using namespace std;

// Definition for an AVL tree node
struct TreeNode {
    int value;          // The value of the node
    TreeNode* left;     // Pointer to the left child
    TreeNode* right;    // Pointer to the right child
    int height;         // Height of the node

    // Constructor to initialize a new node
    TreeNode(int val) {
        value = val;
        left = NULL;
        right = NULL;
        height = 1; // New node is initially added at leaf and by definition its height is 1
    }
};

// So if we not use the Structure Constructor then we can achieve the same thing by the following function

/* TreeNode* create(int val){
    TreeNode* node = new TreeNode;
    node->value = val;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
} */

// Function to get the height of the tree
int getHeight(TreeNode* node) {
    if (node == NULL)
        return 0;
    return node->height;
}

// Function to get the balance factor of the node
int getDifference(TreeNode* node) {
    if (node == NULL)
        return 0;
    return getHeight(node->left) - getHeight(node->right);
}

// Right rotate the subtree rooted with y
TreeNode* rightRotate(TreeNode* y) {
    TreeNode* x = y->left;
    TreeNode* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

/*     1. Determine the Height of Left Child:
       height(x->left) retrieves the height of the left child of node x. If the left child is NULL, height(x->left) returns 0.

       2. Determine the Height of Right Child:
       height(x->right) retrieves the height of the right child of node x. If the right child is NULL, height(x->right) returns 0.

       3. Find the Maximum Height:
       max(height(x->left), height(x->right)) computes the maximum height between the left and right subtrees of node x.
       
       4. Add One:
       + 1 adds one to the maximum height to account for the current node x itself.
       
       5. Assign the New Height:
       x->height = ... assigns the computed height back to the node x. 
       SAME FOR ALL OTHERS */

       


    // Return new root
    return x; // Now x becomes new root
}

// Left rotate the subtree rooted with x
TreeNode* leftRotate(TreeNode* x) {
    TreeNode* y = x->right;
    TreeNode* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    // Return new root
    return y;
}

// Function to insert a node in the AVL tree
TreeNode* insert(TreeNode* node, int value) {
    // Perform the normal BST insertion
    if (node == NULL)
        return new TreeNode(value);

    if (value < node->value)
        node->left = insert(node->left, value);
    else if (value > node->value)
        node->right = insert(node->right, value);
    else // Equal values are not allowed in BST
        return node;

    // Update the height of this ancestor node as we use this in balance factor
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    // Get the balance factor of this ancestor node to check whether this node became unbalanced
    int balance = getDifference(node);

    // If this node becomes unbalanced, then there are 4 cases

    // Left Left Case
    if (balance > 1 && value < node->left->value) // left side has more node then right side so do rightRotation
        return rightRotate(node);

    // Right Right Case
    if (balance < -1 && value > node->right->value) // right side has more node then left side so do leftRotation
        return leftRotate(node);

    // Left Right Case
    if (balance > 1 && value > node->left->value) { // left side has more node & our new value is > then node left value
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && value < node->right->value) { // right side has more node & our new value is < then node right value
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    // Return the (unchanged) node pointer
    return node;
}

// Function to perform in-order traversal of the AVL tree
void inOrderTraversal(TreeNode* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);   // Traverse the left subtree
        cout << root->value << " ";     // Visit the root node
        inOrderTraversal(root->right);  // Traverse the right subtree
    }
}

// Function to perform pre-order traversal of the AVL tree
void preOrderTraversal(TreeNode* root) {
    if (root != NULL) {
        cout << root->value << " ";     // Visit the root node
        preOrderTraversal(root->left);  // Traverse the left subtree
        preOrderTraversal(root->right); // Traverse the right subtree
    }
}

// Function to perform post-order traversal of the AVL tree
void postOrderTraversal(TreeNode* root) {
    if (root != NULL) {
        postOrderTraversal(root->left);  // Traverse the left subtree
        postOrderTraversal(root->right); // Traverse the right subtree
        cout << root->value << " ";      // Visit the root node
    }
}

// Function to search for a value in the AVL tree
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

// Function to find the node with the minimum value in the AVL tree
TreeNode* minValueNode(TreeNode* node) {
    TreeNode* current = node;

    // Loop down to find the leftmost leaf
    while (current->left != NULL)
        current = current->left;

    return current;
}

// Function to delete a node from the AVL tree
TreeNode* deleteNode(TreeNode* root, int value) {
    // Perform standard BST delete
    if (root == NULL)
        return root;

    // If the value to be deleted is smaller than the root's value, then it lies in the left subtree
    if (value < root->value)
        root->left = deleteNode(root->left, value);

    // If the value to be deleted is greater than the root's value, then it lies in the right subtree
    else if (value > root->value)
        root->right = deleteNode(root->right, value);

    // If value is same as root's value, then this is the node to be deleted
    else {
        // Node with only one child or no child
        if ((root->left == NULL) || (root->right == NULL)) {
            TreeNode* temp = root->left ? root->left : root->right; // if root->left then return root->left otherwise return root->right
            // if we not use the previous line then we can use the following lines
            /* TreeNode* temp;
            if (root->left) {
                temp = root->left;
            } else {
                temp = root->right;
            } */

            // No child case
            if (temp == NULL) {
                temp = root;
                root = NULL;
            }
            else // One child case
                *root = *temp; // Copy the contents of the non-empty child

            delete temp;
        }
        else {
            // Node with two children: Get the inorder successor (smallest in the right subtree)
            TreeNode* temp = minValueNode(root->right);

            // Copy the inorder successor's data to this node
            root->value = temp->value;

            // Delete the inorder successor
            root->right = deleteNode(root->right, temp->value);
        }
    }

    // If the tree had only one node then return
    if (root == NULL)
        return root;

    // Update the height of the current node
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    // Get the balance factor of this node to check whether this node became unbalanced
    int balance = getDifference(root);

    // If this node becomes unbalanced, then there are 4 cases

    // Left Left Case
    if (balance > 1 && getDifference(root->left) >= 0)
        return rightRotate(root);

    // Left Right Case
    if (balance > 1 && getDifference(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Right Case
    if (balance < -1 && getDifference(root->right) <= 0)
        return leftRotate(root);

    // Right Left Case
    if (balance < -1 && getDifference(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// Main function
int main() {
    TreeNode* root = NULL;  // Start with an empty tree

    // Insert nodes into the AVL tree
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