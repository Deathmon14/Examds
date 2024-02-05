#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the doubly linked list
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        perror("Error creating new node");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node to the left of the node with a given key
void insertLeft(Node** head, int key, int newData) {
    Node* newNode = createNode(newData);
    Node* current = *head;

    while (current != NULL) {
        if (current->data == key) {
            if (current->prev != NULL) {
                current->prev->next = newNode;
                newNode->prev = current->prev;
            } else {
                *head = newNode;
            }

            newNode->next = current;
            current->prev = newNode;

            printf("Node with data %d inserted to the left of the node with key %d.\n", newData, key);
            return;
        }
        current = current->next;
    }

    printf("Node with key %d not found.\n", key);
}

// Function to delete a node with a given data value
void deleteNode(Node** head, int data) {
    Node* current = *head;

    while (current != NULL) {
        if (current->data == data) {
            if (current->prev != NULL) {
                current->prev->next = current->next;
            } else {
                *head = current->next;
            }

            if (current->next != NULL) {
                current->next->prev = current->prev;
            }

            free(current);
            printf("Node with data %d deleted.\n", data);
            return;
        }
        current = current->next;
    }

    printf("Node with data %d not found.\n", data);
}

// Function to display the doubly linked list
void displayList(Node* head) {
    printf("Doubly Linked List: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Function to free the memory allocated for the doubly linked list
void freeList(Node* head) {
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    Node* head = NULL;
    int choice, key, newData;

    do {
        printf("\n--- Doubly Linked List Operations ---\n");
        printf("1. Insert a new node to the left of a node\n");
        printf("2. Delete a node by data value\n");
        printf("3. Display the list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key value: ");
                scanf("%d", &key);
                printf("Enter data for the new node: ");
                scanf("%d", &newData);
                insertLeft(&head, key, newData);
                break;

            case 2:
                printf("Enter data value to delete: ");
                scanf("%d", &newData);
                deleteNode(&head, newData);
                break;

            case 3:
                displayList(head);
                break;

            case 4:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 4);

    freeList(head);

    return 0;
}
