#include "support.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 80

int _num_input_strings = 0;
/* infile is defined in bomb.c */
extern FILE *infile;

void initialize_bomb() {
    if (infile == NULL) infile = stdin;
}

char *read_line() {
    char *line = malloc(MAX_LINE);
    if (!fgets(line, MAX_LINE, infile)) {
        return NULL;
    }
    size_t len = strlen(line);
    if (len > 0 && line[len - 1] == '\n') {
        line[len - 1] = '\0';
    }
    _num_input_strings++;
    return line;
}

void explode_bomb() {
    printf("\nBOOM!!!\n");
    printf("The bomb has blown up.\n");
    exit(1);
}

int string_length(const char *str) {
    return (int)strlen(str);
}

int strings_not_equal(const char *a, const char *b) {
    return strcmp(a, b);
}

void read_six_numbers(char *s, int *arr) {
    int count = sscanf(s, "%d %d %d %d %d %d", &arr[0], &arr[1], &arr[2], &arr[3], &arr[4], &arr[5]);
    if (count < 6) {
        explode_bomb();
    }
}

int func4(int a, int b, int c) {
    int mid = (b + c) / 2;
    if (mid > a) {
        return func4(a, b, mid - 1) * 2;
    } else if (mid < a) {
        return func4(a, mid + 1, c) * 2 + 1;
    } else {
        return 0;
    }
}

int fun7(tree_node_t *node, int arg2) {
    if (node == NULL) return -1;
    if (arg2 < node->value) {
        return 2 * fun7(node->left, arg2);
    } else if (arg2 > node->value) {
        return 2 * fun7(node->right, arg2) + 1;
    } else {
        return 0;
    }
}

void send_msg(int msg) {
    /* Not implemented */
}
