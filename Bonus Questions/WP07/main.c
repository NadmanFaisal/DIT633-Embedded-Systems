#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/*
Values as nodes, which represents individual nodes in a 
linked llist. This will be a doubly linked list
*/
typedef struct node {
    struct node *prev;                                      // Keep track of the previous node
    struct node *next;                                      // Keep track of the next node
    long value;                                             // The value of the current node
} Node;                                                     // 'struct node' renamed to 'Node'

/*
This method creates the linked list, where the values of each 
node is a fibonacci number. This method creates a linked list 
of the length 'val', which is the arguement. 
*/
Node *createNode(long val) {
    Node *top = (Node *)malloc(sizeof(Node));               // Allocates memory for the first node
    top->next = NULL;                                       // First node's previous node is null
    top->prev = NULL;                                       // First node's next is also null
    top->value = 0;                                         // The value of the first node in a fibonacci sequence is '0'

    Node *old = top;                                        // Old node now points to the address of top node
    
    long temp = 0;                                          // Value to keep track of previous value of firstNumber
    long firstNumber = 0;                                   // The first number to find the next fibonacci number
    long secondNumber = 1;                                  // // The second number to find the next fibonacci number
    for(long i = 1; i < val; i++) {                         // Creates as many nodes as indicated by val
        if(i == 1) {                                        // If it is the second node, 
            Node *second = (Node *)malloc(sizeof(Node));    // Allocates memory for the second node
            second->prev = old;                             // Second node's previous node is the old node
            second->next = NULL;                            // Second node's next is NULL
            second->value = 1;                              // The value of the second node is always '1'
            old->next = second;                             // Old node's next is the second node now.
            old = second;                                   // Old node now will be the second node
        } else {
            Node *item = (Node *)malloc(sizeof(Node));      // Allocates memory for new node
            item->next = NULL;                              // New node's next is NULL
            item->prev = old;                               // New node's previous is the old node
            item->value = firstNumber + secondNumber;       // New node's value is now the fibonacci number
    
            temp = firstNumber;                             // Keep track of previous value of firstNumber
            firstNumber = secondNumber;                     // First number now becomes second number
            secondNumber = temp + secondNumber;             // Second number is now the new fibonacci number
    
            old->next = item;                               // Old node's next is now the newly created node
            old = item;                                     // New node now becomes the old node.
        }
    }

    return top;                                     // Returns the top node of the linked list
}

/*
Traverses through the linked list and prints the values
*/
void printList(Node *head) {                        // Takes the head as parameter
    while (head != NULL) {
        printf("Value: %ld\n", head->value);        // Prints the value of the head untill NULL is reached
        head = head->next;                          // Head is now the next head
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    long number = atol(argv[1]);                    // Takes the arguement as a long int

    Node *head = createNode(number);                // Creates the linked list, returning the top node
    printList(head);                                // The head is passed to print the linked list values

    Node *temp;                                     // Temporary Node variable to hold the previous head for freeing memory
    while(head != NULL) {
        temp = head;                                // Temp node points to the head
        head = head->next;                          // Head moves on to the next node
        free(temp);                                 // Frees the previous head
    }
    return 0;
}