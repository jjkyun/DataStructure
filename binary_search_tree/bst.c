/* Binary Search Tree
 * @ Jae Kyun Kim
 */
#include <stdio.h>
#include <stdlib.h>

// Node type 
typedef struct node{
    int key;
    struct node *left, *right;
} Node; 

// Create a new node 
Node* create_node(int key){
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->key = key;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

// Insert a node in BST
// @param[in] node  bst root node
Node* insert_node(Node* node, int key){
    // If the tree is empty, create a node
    if (node == NULL) 
        return create_node(key);
    
    // If not, find the location by recursive way
    if (key < node->key)
        node->left = insert_node(node->left, key);
    else
        node->right = insert_node(node->right, key);
    
    // Return the parent node
    return node;
}

// Search a given key
Node* search_node(Node* root, int key){
    // If no tree or key is present at root
    if (root == NULL || root->key == key)
        return root;

    // Key smaller than parent key
    if (key < root->key) return search_node(root->left, key);
    
    // Key larger than parent key
    if (key > root->key)
        return search_node(root->right, key);
}

// Traverse the tree in inorder
void traverse_inorder(Node* root){
    if (root != NULL){
        // Go left until leaf node
        traverse_inorder(root->left);
        printf("%d ", root->key);
        traverse_inorder(root->right);
    }
}

Node* find_min_node(Node* node){
    Node* temp = node;
    
    while (node->left != NULL)
        node = node->left;

    return node;
}

// Delete Node with given key and return new root 
Node* delete_node(Node* root, int key){
    if (root == NULL) 
        return root;
    
    // Find the location by rescursive way 
    if (key < root->key)
        root->left = delete_node(root->left, key);
    else if (key > root->key)
        root->right = delete_node(root->right, key);

    else{
        // Node with only one child or no child
        // No left child
        if (root->left == NULL){
            // Return right child 
            Node* temp = root->right;
            return temp;
        // No right child
        } else if (root->right == NULL){
            // Return left child
            Node* temp = root->left;
            return temp;
        }
        
        // Two children exists, find inorder successor of the node
        Node* temp = find_min_node(root->right);
        
        // Copy the temp key to the parent key
        root->key = temp->key;
        // Delete the inorder successor
        root->right = delete_node(root->right, temp->key);
    }
    return root;
}

void main(){
    // Create root node
    Node* root = NULL;
    root = insert_node(root, 40);
    
    // Insert node
    insert_node(root, 20);
    insert_node(root, 80);
    insert_node(root, 30);
    insert_node(root, 50);

    // Print keys while traversing inorder
    traverse_inorder(root);
    
    printf("\nDelete node with key value 20\n");
    root = delete_node(root, 20);
    traverse_inorder(root);

    printf("\nDelete node with key value 50\n");
    root = delete_node(root, 50);
    traverse_inorder(root);
}
