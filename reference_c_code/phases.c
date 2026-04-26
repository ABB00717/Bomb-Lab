#include "phases.h"
#include "support.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Phase 6 Nodes Initialized from Ghidra Data */
node_t node6 = {443, 6, NULL};
node_t node5 = {477, 5, &node6};
node_t node4 = {691, 4, &node5};
node_t node3 = {924, 3, &node4};
node_t node2 = {168, 2, &node3};
node_t node1 = {332, 1, &node2};

/* Secret Phase Tree Nodes Initialized from Ghidra Data */
tree_node_t n43 = {107, NULL, NULL};
tree_node_t n42 = {45, NULL, NULL};
tree_node_t n41 = {22, NULL, NULL};
tree_node_t n40 = {6, NULL, NULL};
tree_node_t n31 = {50, &n42, &n43};
tree_node_t n30 = {8, &n40, &n41};
tree_node_t n20 = {36, &n30, &n31};  // Root

void phase_1(char *input) {
    if (strings_not_equal(
            input, "Border relations with Canada have never been better.") !=
        0) {
        explode_bomb();
    }
}

void phase_2(char *input) {
    int numbers[6];
    read_six_numbers(input, numbers);
    if (numbers[0] != 1) explode_bomb();
    for (int i = 1; i < 6; i++) {
        if (numbers[i] != numbers[i - 1] * 2) explode_bomb();
    }
}

void phase_3(char *input) {
    int index, value;
    if (sscanf(input, "%d %d", &index, &value) < 2) explode_bomb();
    int expected;
    switch (index) {
        case 0:
            expected = 207;
            break;
        case 1:
            expected = 311;
            break;
        case 2:
            expected = 707;
            break;
        case 3:
            expected = 256;
            break;
        case 4:
            expected = 389;
            break;
        case 5:
            expected = 206;
            break;
        case 6:
            expected = 682;
            break;
        case 7:
            expected = 327;
            break;
        default:
            explode_bomb();
    }
    if (value != expected) explode_bomb();
}

static char phase_4_input[80];
void phase_4(char *input) {
    int num1, num2;
    if (sscanf(input, "%d %d", &num1, &num2) != 2 || num1 > 14) explode_bomb();
    if (func4(num1, 0, 14) != 0 || num2 != 0) explode_bomb();
    strcpy(phase_4_input, input);
}

void phase_5(char *input) {
    if (string_length(input) != 6) explode_bomb();
    char *map = "maduiersnfotvbyl";
    char result[7];
    for (int i = 0; i < 6; i++) result[i] = map[input[i] & 0xf];
    result[6] = '\0';
    if (strings_not_equal(result, "flyers") != 0) explode_bomb();
}

void phase_6(char *input) {
    int indices[6];
    node_t *reordered[6];
    read_six_numbers(input, indices);

    for (int i = 0; i < 6; i++) {
        if (indices[i] < 1 || indices[i] > 6) explode_bomb();
        for (int j = i + 1; j < 6; j++) {
            if (indices[i] == indices[j]) explode_bomb();
        }
        /* The bomb does 7 - index internally in this version */
        indices[i] = 7 - indices[i];
    }

    // Locate Nodes Based on (transformed) Indices
    for (int i = 0; i < 6; i++) {
        node_t *curr = &node1;
        for (int j = 1; j < indices[i]; j++) {
            curr = curr->next;
        }
        reordered[i] = curr;
    }

    // Re-link the List
    for (int i = 0; i < 5; i++) {
        reordered[i]->next = reordered[i + 1];
    }
    reordered[5]->next = NULL;

    // Check if Sorted Descending
    node_t *check = reordered[0];
    for (int i = 0; i < 5; i++) {
        if (check->value < check->next->value) {
            explode_bomb();
        }
        check = check->next;
    }
}

void secret_phase() {
    char *input = read_line();
    if (input == NULL) explode_bomb();
    int value = atoi(input);
    if (value < 1 || value > 1000) explode_bomb();
    if (fun7(&n20, value) != 2) explode_bomb();
    printf("Wow! You've defused the secret stage!\n");
}

void phase_defused() {
    if (_num_input_strings == 6) {
        int a, b;
        char buffer[80];
        if (sscanf(phase_4_input, "%d %d %s", &a, &b, buffer) == 3) {
            if (strcmp(buffer, "DrEvil") == 0) {
                printf("Curses, you've found the secret phase!\n");
                printf(
                    "But finding it and solving it are quite different...\n");
                secret_phase();
            }
        }
        printf("Congratulations! You've defused the bomb!\n");
    }
}
