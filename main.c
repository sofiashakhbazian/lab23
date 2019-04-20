#include <stdio.h>
#include <stdbool.h>
#include "binary_tree.h"
#include "queue.h"

void print_tree(binary_node **node, int level);
binary_node * BFS(binary_node *root);

#define MAX 255

int main(void) {
    char cmd[MAX], arg;
    binary_node *root = NULL;

    printf("Введите команду 'h' для получения справки\n");

    do {
        // Считываем команду
        printf("> ");
        scanf("%s", cmd);

        if (cmd[0] == '+') {
            scanf(" %c", &arg);

            if (arg >= 'A' && arg <= 'Z') {
                insert_in_tree(&root, arg - 'A');
                printf("Узел %c вставлен.\n", arg);
            } else
                printf("Недопустимый символ для узла!\n");
        } else if (cmd[0] == '-') {
            scanf(" %c", &arg);

            if (arg >= 'A' && arg <= 'Z') {
                if (remove_node(&root, arg - 'A'))
                    printf("Узел %c удален.\n", arg);
                else
                    printf("Узел %c не найден.\n", arg);
            }
            else
                printf("Недопустимый символ для узла!\n");
        } else if (cmd[0] == 'p') {
            print_tree(&root, 0);
        } else if (cmd[0] == 't') {
            if (root != NULL) {
                printf("Узел на минимальной глубине: ");
                binary_node * min_depth_node = BFS(root);
                printf("%c\n", min_depth_node->_key + 'A');
            } else
                printf("Двоичное дерево пусто\n");
        } else if (cmd[0] == 'h') {
            printf("================================\n");
            printf("Список команд:\n");
            printf("+ <char> - вставить узел <char> (A, B, ..., Z) в дерево\n");
            printf("- <char> - удалить узел <char> из дерева\n");
            printf("p - распечатать дерево\n");
            printf("t - выполнить задание над деревом\n");
            printf("q - завершить программу\n");
            printf("================================\n\n");
        } else if (cmd[0] != 'q') {
            printf("Неизвестная команда.\n");
        }
    } while (cmd[0] != 'q');

    destory_tree(&root);

    return 0;
}

void print_tree(binary_node **node, const int level) {
    if (*node == NULL) {
        printf("Дерево пустое.\n");
        return;
    }

    if ((*node)->_right != NULL)
        print_tree(&(*node)->_right, level + 1);

    printf("%*s%c\n", level * 2, "", (*node)->_key + 'A');

    if ((*node)->_left != NULL)
        print_tree(&(*node)->_left, level + 1);
}

binary_node * BFS(binary_node * root) {
    queue * q = create_queue();
    if (root != NULL) {
        enqueue(q, root);
        while (!isempty(q)) {
            queue_node * q_node = dequeue(q);
            if ((q_node->tree_node->_left == NULL) && (q_node->tree_node->_left == NULL)) {
                destory_queue(q->rear);
                return q_node->tree_node;
            } 
            
            if (q_node->tree_node->_left != NULL) {
                enqueue(q, q_node->tree_node->_left);
            }
            if (q_node->tree_node->_right != NULL) {
                enqueue(q, q_node->tree_node->_right);
            }
        }
    }
    destory_queue(q->rear);
    return NULL;
}