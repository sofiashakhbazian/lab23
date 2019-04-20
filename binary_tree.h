#ifndef BST_H
    #define BST_H

    #include "binary_tree.c"

    binary_node *insert_in_tree(binary_node **node, alphabet key);
    int remove_node(binary_node **node, alphabet key);
    void destory_tree(binary_node **node);

#endif