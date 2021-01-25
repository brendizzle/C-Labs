/* This program implements basic linked list functions */

#include <stdio.h>
#include <stdlib.h>

struct node_t {
    double x;
    struct node_t *next;
};

struct node_t *create_node(double n);
void print_node(struct node_t *node);
void print_list(struct node_t *head);
struct node_t *insert_head(struct node_t *head, struct node_t *node);
struct node_t *insert_tail(struct node_t *head, struct node_t *node);
struct node_t *insert_middle(struct node_t *head, struct node_t *node, int pos);
int count_nodes(struct node_t *head);
struct node_t *find_node(struct node_t *head, double n);
struct node_t *delete_node(struct node_t *head, double n);
void delete_list(struct node_t *head);

struct node_t *create_node(double n)
{
    struct node_t *node = NULL;
    node = malloc(sizeof(double));
    node->x = n;
    node->next = NULL;
    return node;
}

void print_node(struct node_t *node)
{
    printf("Value: %f, Address: %p, Next Address: %p\n", node->x, node, node->next);
}

void print_list(struct node_t *head)
{
    struct node_t *tmp = NULL;
    tmp = head;
    while (tmp != NULL) {
        print_node(tmp);
        tmp = tmp->next;
    }
}

struct node_t *insert_head(struct node_t *head, struct node_t *node)
{
    if (head == NULL) 
        return node;
    
    node->next = head;
    return node;
}

struct node_t *insert_tail(struct node_t *head, struct node_t *node)
{
    if (head == NULL) 
        return node;

    struct node_t *tmp = NULL;
    tmp = head;
    while (tmp->next != NULL) 
        tmp = tmp->next;
    
    tmp->next = node;
    return head;
}

struct node_t *insert_middle(struct node_t *head, struct node_t *node, int pos)
{
    int n = count_nodes(head);
    if (n < 1) 
        return node;

    struct node_t *tmp = NULL;
    tmp = head;
    int count = 1;

    if (pos == 1) {
        node = insert_head(head, node);
        return node;
    }  
    else if (pos > n) {
        node = insert_tail(head, node);
        return head;
    }  
    else {
       while (count < pos-1) {
           tmp = tmp->next;
           count++;
       } 

       node->next = tmp->next;
       tmp->next = node;
       return head;
    }
}

int count_nodes(struct node_t *head)
{
    int count = 0;
    struct node_t *tmp = NULL;
    tmp = head;

    while (tmp != NULL) {
        count++;
        tmp = tmp->next;
    }

    return count;
}

int main() 
{
    struct node_t *node = NULL;
    node = create_node(1.0);
    struct node_t *node2 = NULL;
    node2 = create_node(2.0);
    node2 = insert_head(node, node2);
    struct node_t *node3 = NULL;
    node3 = create_node(3.0);
    node2 = insert_tail(node2, node3);
    struct node_t *node4 = NULL;
    node4 = create_node(4.0);
    node2 = insert_middle(node2, node4, 2);
    print_list(node2);
    printf("%d\n", count_nodes(node2));

    return 0;
}