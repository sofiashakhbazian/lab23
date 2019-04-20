#include <stdlib.h> 
#include <stdio.h>
#include <stdbool.h>
#include "binary_tree.h"

// A linked list node to store a queue entry 
typedef struct _queue_node { 
    binary_node * tree_node;
    struct _queue_node *next; 
} queue_node;

// The queue, front stores the front node of LL and rear stores ths 
// last node of LL 
typedef struct _queue { 
    struct _queue_node *front, *rear;
} queue;

// A utility function to create a new linked list node.
queue_node* new_node(binary_node * node) {
    queue_node *temp = (queue_node*) malloc(sizeof(queue_node));
    temp->tree_node = node;
    temp->next = NULL;
    return temp;
} 
  
// A utility function to create an empty queue 
queue *create_queue() { 
    queue *q = (queue*)malloc(sizeof(queue)); 
    q->front = q->rear = NULL; 
    return q;
} 
  
// The function to add a tree_node k to q 
void enqueue(queue *q, binary_node * node) { 
    // Create a new LL node 
    queue_node *temp = new_node(node);
  
    // If queue is empty, then new node is front and rear both 
    if (q->rear == NULL) {
       q->front = q->rear = temp; 
       return;
    } 
  
    // Add the new node at the end of queue and change rear 
    q->rear->next = temp; 
    q->rear = temp;
} 
  
// Function to remove a tree_node from given queue q 
queue_node *dequeue(queue *q) { 
    // If queue is empty, return NULL. 
    if (q->front == NULL) 
       return NULL; 
  
    // Store previous front and move front one node ahead 
    queue_node *temp = q->front; 
    q->front = q->front->next; 
  
    // If front becomes NULL, then change rear also as NULL 
    if (q->front == NULL)
       q->rear = NULL;
    return temp;
}

void destory_queue(queue_node *q) {
    if (q == NULL)
        return;

    if (q->next != NULL)
        destory_queue(q->next);

    free(q);
    q = NULL;
}

bool isempty(queue *q) {
    return q->rear == NULL;
}