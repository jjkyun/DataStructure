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
    if (key <= node->key)
        node->left = insert_node(node->left, key);
    else
        node->right = insert_node(node->right, key);
    
    // Return the parent node
    return node;
}

// Search a given key
Node* search(Node* root, int key){
    // If no tree or key is present at root
    if (root == NULL || root->key == key)
        return root;

    // Key smaller than parent key
    if (key <= root->key)
        return search(root->left, key);
    
    // Key larger than parent key
    if (key > root->key)
        return search(root->right, key);
}

int main(){
    // Create root node
    Node* root = NULL;
    root = insert_node(root, 50);
    insert_node(root, 30);
    insert_node(root, 20);
   

}
