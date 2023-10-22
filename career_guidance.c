#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TreeNode {
    char data[50];
    struct TreeNode* children[10];
    int num_children;
};

struct TreeNode* createNode(const char* data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    strcpy(newNode->data, data);
    newNode->num_children = 0;
    return newNode;
}

void addChild(struct TreeNode* parent, struct TreeNode* child) {
    if (parent->num_children < 10) {
        parent->children[parent->num_children] = child;
        parent->num_children++;
    }
}

void displayCareerOptions(struct TreeNode* node) {
    if (node == NULL) {
        return;
    }

    printf("Career options for %s:\n", node->data);
    for (int i = 0; i < node->num_children; i++) {
        printf("%d. %s\n", i + 1, node->children[i]->data);
    }
}

int main() {
    struct TreeNode* root = createNode("Engineering Streams");

    struct TreeNode* computer = createNode("Computer");
    struct TreeNode* electrical = createNode("Electrical");
    struct TreeNode* infoTech = createNode("Information Tech");
    struct TreeNode* mechanical = createNode("Mechanical");

    addChild(root, computer);
    addChild(root, electrical);
    addChild(root, infoTech);
    addChild(root, mechanical);

    // Adding career options as child nodes for each stream
    struct TreeNode* computerOptions = createNode("Career Options for Computer");
    addChild(computer, computerOptions);

    struct TreeNode* electricalOptions = createNode("Career Options for Electrical");
    addChild(electrical, electricalOptions);

    struct TreeNode* infoTechOptions = createNode("Career Options for Information Tech");
    addChild(infoTech, infoTechOptions);

    struct TreeNode* mechanicalOptions = createNode("Career Options for Mechanical");
    addChild(mechanical, mechanicalOptions);

    // Adding career options as child nodes for each stream
    struct TreeNode* computerOptionsList[] = {
        createNode("Internships"),
        createNode("Apprenticeship"),
        createNode("Jobs"),
        createNode("Masters"),
        createNode("Entrepreneurship"),
        createNode("MBA"),
        createNode("Exit")
    };

    for (int i = 0; i < 7; i++) {
        addChild(computerOptions, computerOptionsList[i]);
    }

    struct TreeNode* electricalOptionsList[] = {
        createNode("Internships"),
        createNode("Apprenticeship"),
        createNode("Jobs"),
        createNode("Masters"),
        createNode("Entrepreneurship"),
        createNode("MBA"),
        createNode("Exit")
    };

    for (int i = 0; i < 7; i++) {
        addChild(electricalOptions, electricalOptionsList[i]);
    }

    struct TreeNode* infoTechOptionsList[] = {
        createNode("Internships"),
        createNode("Apprenticeship"),
        createNode("Jobs"),
        createNode("Masters"),
        createNode("Entrepreneurship"),
        createNode("MBA"),
        createNode("Exit")
    };

    for (int i = 0; i < 7; i++) {
        addChild(infoTechOptions, infoTechOptionsList[i]);
    }

    struct TreeNode* mechanicalOptionsList[] = {
        createNode("Internships"),
        createNode("Apprenticeship"),
        createNode("Jobs"),
        createNode("Masters"),
        createNode("Entrepreneurship"),
        createNode("MBA"),
        createNode("Exit")
    };

    for (int i = 0; i < 7; i++) {
        addChild(mechanicalOptions, mechanicalOptionsList[i]);
    }

    int choice;

    printf("Choose an engineering stream:\n");
    printf("1. Computer\n");
    printf("2. Electrical\n");
    printf("3. Information Tech\n");
    printf("4. Mechanical\n");
    printf("5. Quit\n");
    scanf("%d", &choice);

    if (choice < 1 || choice > 4) {
        printf("Invalid choice. Exiting the program. Thank you!\n");
        free(root);
        return 0;
    }

    displayCareerOptions(root->children[choice - 1]);

    while (1) {
        printf("Choose a career option or enter 7 to quit:\n");
        printf("1. Internships\n");
        printf("2. Apprenticeships\n");
        printf("3. Jobs\n");
        printf("4. Masters\n");
        printf("5. Entrepreneurships\n");
        printf("6. MBA\n");
        printf("7. Quit\n");
        scanf("%d", &choice);

        if (choice == 7) {
            printf("Exiting the program. Thank you!\n");
            break;
        }

        if (choice < 1 || choice > root->children[0]->num_children) {
            printf("Invalid choice. Please enter a valid option.\n");
        } else {
            displayCareerOptions(root->children[choice - 1]);
        }
    }

    // Clean up memory
    free(root);
    return 0;
}
