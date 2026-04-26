#include <stdint.h>
#include <stdio.h>

extern int _num_input_strings;
extern FILE *infile;

/* Linked list node for phase_6 */
typedef struct node {
    int value;
    int index;
    struct node *next;
} node_t;

/* Binary tree node for secret_phase */
typedef struct tree_node {
    int value;
    struct tree_node *left;
    struct tree_node *right;
} tree_node_t;

void initialize_bomb();
char *read_line();
void explode_bomb();
int string_length(const char *str);
int strings_not_equal(const char *a, const char *b);
void read_six_numbers(char *s, int *arr);
int func4(int a, int b, int c);
int fun7(tree_node_t *node, int arg2);
void send_msg(int msg);
