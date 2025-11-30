/*
Assume a linked list as given in the following figure (consider the figure just as an
example).
Write program with following methods
(a) A method to insert a new element after a given element in the linked list.
(b) A method to insert a new element at the end of the linked list.
(c) A method to print all the elements of the list.
*/

#include <stdio.h>
#include <stdlib.h>

// 1. Define the Node structure
struct Node {
    int data;
    struct Node* next;      // Points to the immediate next node
    struct Node* next_next; // Points to the node after the next (skip pointer)
};

// Helper function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->next_next = NULL;
    return newNode;
}

// Helper function to refresh the 'next_next' pointers
// This ensures the 3rd box always points to the node after the next one
void updateSkipPointers(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        if (current->next != NULL) {
            // Point to the node after the next one
            current->next_next = current->next->next;
        } else {
            // If there is no next node, there can't be a next_next
            current->next_next = NULL;
        }
        current = current->next;
    }
}

// (a) Method to insert a new element after a given element
void insertAfter(struct Node* head, int targetData, int newData) {
    struct Node* current = head;
    
    // Search for the target node
    while (current != NULL && current->data != targetData) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Element %d not found in the list.\n", targetData);
        return;
    }

    // standard insertion logic
    struct Node* newNode = createNode(newData);
    newNode->next = current->next;
    current->next = newNode;

    // Fix the structure (update the skip pointers)
    updateSkipPointers(head);
    printf("Inserted %d after %d.\n", newData, targetData);
}

// (b) Method to insert a new element at the end of the list
// Note: We need a double pointer (**head) to handle the case where the list is empty
void insertAtEnd(struct Node** head, int newData) {
    struct Node* newNode = createNode(newData);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
    
    // Fix the structure (update the skip pointers)
    updateSkipPointers(*head);
}

// (c) Method to print all elements of the list
void printList(struct Node* head) {
    struct Node* current = head;
    printf("\n--- Current List Status ---\n");
    printf("Format: [Data | Next -> Data | Skip -> Data]\n");
    
    while (current != NULL) {
        int nextVal = (current->next != NULL) ? current->next->data : 0; // 0 represents NULL for display
        int skipVal = (current->next_next != NULL) ? current->next_next->data : 0; // 0 represents X/NULL
        
        printf("[%d | Next->%d | Skip->%d] -> ", current->data, nextVal, skipVal);
        current = current->next;
    }
    printf("NULL\n---------------------------\n");
}

// Main function to test the requirements
int main() {
    struct Node* head = NULL;

    // Building the list from the example image: 1 -> 5 -> 3 -> 2 -> 21 -> 9
    insertAtEnd(&head, 1);
    insertAtEnd(&head, 5);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 21);
    insertAtEnd(&head, 9);

    printf("Initial List (matching the diagram):");
    printList(head);

    // Requirement (a): Insert a new element (e.g., 99) after a given element (e.g., 3)
    insertAfter(head, 3, 99);
    printList(head);

    // Requirement (b): Insert a new element at the end (e.g., 100)
    insertAtEnd(&head, 100);
    printList(head);

    return 0;
}