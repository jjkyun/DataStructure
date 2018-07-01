#include <stdio.h>
#include <stdlib.h>

struct element_t{
    int data;
};

// Double Link Node Type
struct Node{
    struct element_t element;
    struct Node* next;
    struct Node* prev;
};

// Creates a new node and returns the pointer
struct Node* CreateNewNode(int data){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->element.data = data;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

// Make head node
struct Node* head_node;

// Insert node at the first place:: Change the head node
void InsertAtHead(int data){
    struct Node* new_node = CreateNewNode(data);
    // Check if there is head node
    if(head_node == NULL){
        // If not the new node is head node
        head_node = new_node;
        return;
    } else {
        // Changing the new node to head node
        head_node->prev = new_node;
        new_node->next = head_node;
        head_node = new_node;
    }
}

// Insert at the end of a list
void InsertAtTail(int data){
    // Make temp node to find 
    struct Node* temp = head_node;
    struct Node* new_node = CreateNewNode(data);
    if(head_node == NULL){
        head_node = new_node;
        return;
    }
    // Go to tail node
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = new_node;
    new_node->prev = temp;
}

void PrintList(){
    struct Node* temp = head_node;
    // Print from head to tail node
    while(temp != NULL){
        printf("%d ", temp->element.data);
        temp = temp->next;
    }
    printf("\n");
}


int main(int argc, const char *argv[])
{
    head_node = NULL;

    InsertAtHead(5);
    InsertAtHead(10);
    InsertAtHead(15);
    InsertAtTail(20);
    InsertAtTail(25);

    PrintList();

    return 0;
}
