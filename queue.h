#ifndef QUEUE_H
    #define QUEUE_H

    #include "queue.c"

    queue_node* new_node(binary_node * node);
    queue *create_queue();
    void enqueue(queue *q, binary_node * node);
    queue_node *dequeue(queue *q);
    bool isempty(queue *q);
    void destory_queue(queue_node *q);

#endif