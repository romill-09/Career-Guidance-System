#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QLEN 100
#define MAX_CHOICES 2

struct Node {
    char question[MAX_QLEN];
    struct Node* choices[MAX_CHOICES];
};

void createDecisionTree(struct Node** root) {
    // Root Node
    *root = (struct Node*)malloc(sizeof(struct Node));
    if (*root == NULL) {
        perror("Memory allocation failed");
        exit(1);
    }
    strcpy((*root)->question, "Which Engineering Stream are you interested in?");

    // Computer Science and Engineering Path
    struct Node* computerScience = (struct Node*)malloc(sizeof(struct Node));
    if (computerScience == NULL) {
        perror("Memory allocation failed");
        exit(1);
    }
    strcpy(computerScience->question, "Do you want to pursue further studies in Computer Science?");
    computerScience->choices[0] = NULL; // No further studies
    computerScience->choices[1] = (struct Node*)malloc(sizeof(struct Node)); // Yes, further studies

    // Electrical Engineering Path
    struct Node* electricalEngineering = (struct Node*)malloc(sizeof(struct Node));
    if (electricalEngineering == NULL) {
        perror("Memory allocation failed");
        exit(1);
    }
    strcpy(electricalEngineering->question, "Do you want to pursue further studies in Electrical Engineering?");
    electricalEngineering->choices[0] = (struct Node*)malloc(sizeof(struct Node)); // No, further studies
    electricalEngineering->choices[1] = (struct Node*)malloc(sizeof(struct Node)); // Yes, further studies

    // Assigning choices
    (*root)->choices[0] = computerScience;
    (*root)->choices[1] = electricalEngineering;

    // More choices and paths can be added as needed
}

void careerGuidance(struct Node* current) {
    if (current == NULL) {
        printf("You have reached a career choice!\n");
        return;
    }

    printf("%s (1/2): ", current->question);

    char choice;
    if (scanf(" %c", &choice) == 1) {
        if (choice == '1' && current->choices[0]) {
            careerGuidance(current->choices[0]);
        } else if (choice == '2' && current->choices[1]) {
            careerGuidance(current->choices[1]);
        } else {
            printf("Invalid choice. Please enter 1 or 2.\n");
            careerGuidance(current);
        }
    } else {
        printf("Invalid input. Please enter 1 or 2.\n");
        careerGuidance(current);
    }
}

int main() {
    struct Node* root = NULL;
    createDecisionTree(&root);

    printf("Welcome to the Career Guidance System!\n");
    printf("Answer the following questions to get career suggestions.\n");

    careerGuidance(root);

    // Clean up the allocated memory
    free(root->choices[0]);
    free(root->choices[1]);
    free(root);

    return 0;
}
