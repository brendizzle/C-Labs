#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct bit_t {
    unsigned char n;

    struct bit_t *prev;
    struct bit_t *next;
};

struct cpu_t {
    int word_size;
    int unsign; //0 -- signed, 1 for unsigned
    //flags
    int overflow;
    int carry;
    int sign;
    int parity;
    int zero;
    struct bit_t *r1_head;
    struct bit_t *r1_tail;
    struct bit_t *r2_head;
    struct bit_t *r2_tail;
    struct bit_t *r3_head;
    struct bit_t *r3_tail;
};

void parse_string(char *s, char *r1, char *r2, char *op);
struct bit_t *create_node(unsigned char x);
void print_node(struct bit_t *bit);
void add_head(struct cpu_t *cpu, struct bit_t *node1, struct bit_t *node2, struct bit_t *node3);



void parse_string(char s[], char r1[], char r2[], char op[])
{
    char *token;
    token = strtok(s, " ");
    strncpy(r1, token, strlen(token));
    token = strtok(NULL, " ");
    strncpy(op, token, strlen(token));
    token = strtok(NULL, " ");
    strncpy(r2, token, strlen(token));
}

struct bit_t *create_node(unsigned char x)
{
    struct bit_t *node = NULL;
    node = malloc(sizeof(struct bit_t));
    node->n = x;
    node->prev = NULL;
    node->next = NULL;
    return node;
}

void print_node(struct bit_t *bit)
{
    printf("%c, Previous Address: %p, Address: %p, Next Address: %p\n", bit->n, bit->prev, bit, bit->next);
}

void add_head(struct cpu_t *cpu, struct bit_t *node1, struct bit_t *node2, struct bit_t *node3)
{
    if (cpu->r1_head == NULL) {
        cpu->r1_head = node1;
        cpu->r2_head = node2;
        cpu->r3_head = node3;
        cpu->r1_tail = node1;
        cpu->r2_tail = node2;
        cpu->r3_tail = node3;
    } else {
        node1->next = cpu->r1_head;
        node2->next = cpu->r2_head;
        node3->next = cpu->r3_head;
        cpu->r1_head->prev = node1;
        cpu->r2_head->prev = node2;
        cpu->r3_head->prev = node3;
        cpu->r1_head = node1;
        cpu->r2_head = node2;
        cpu->r3_head = node3;
    }
}


int main()
{
    struct cpu_t *cpu;
    cpu = malloc(sizeof(struct cpu_t));

    char test[20] = "1011 + 0011";
    char *token = NULL;
    char *delim = " ";
    char r1[20];
    char r2[20];
    char op[2];
    parse_string(test, r1, r2, op);
    printf("%s\n", r1);
    printf("%s\n", op);
    printf("%s\n", r2);

    struct bit_t *bit = create_node(r1[0]);
    print_node(bit);
    struct bit_t *bit2 = create_node(op[0]);
    print_node(bit2);
    struct bit_t *bit3 = create_node(r2[0]);
    print_node(bit3);
    add_head(cpu, bit, bit2, bit3);

    
    
   


    return 0;
}