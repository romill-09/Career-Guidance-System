#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QLEN 100
#define MAX_CLEN 100
#define MAX_CHOICES 2

struct node{
    char question[MAX_QLEN];
    struct node *choices[MAX_CHOICES];
};

// struct node *createNode(char question, struct node *left, struct node *right )
// {
//     struct node *n = (struct node *)malloc(sizeof(struct node));

//     if(n = NULL)
//     {
//         perror("Memory allocation failed");
//         exit(1);
//     }
    
//     n -> question = strdup(question);
//     n -> left = NULL;
//     n -> right = NULL;

//     return(n);
// }

// void freeTree(struct node *root)
// {
//     if(root == NULL) return;
//     free(root -> question);
//     freeTree(root -> left);
//     freeTree(root -> right);
//     free(root);
// }


void loadtree(char *tree, struct node **root)
{
    FILE *file = fopen("tree.txt", "r");

    if(file == NULL) 
    {
        perror("error opening file");
        exit(1);
    }

    char line[MAX_QLEN + MAX_CLEN + 10];

    if(fgets(line, sizeof(line), file) != NULL)
    {
        line[strcspn(line, "\n")] = 0;
        *root = malloc(sizeof(struct node));
        if(*root == NULL)
        {
            perror("Memory allocation failed");
            exit(1);
        }
        strncpy((*root) -> question, line, MAX_QLEN);

        for(int i = 0; i < MAX_CHOICES; ++i)
        {
            if(fgets(line, sizeof(line), file) != NULL);
            {
                line[strcspn(line, "\n")] = 0;
                (*root) -> choices[i] = (struct node*)malloc(sizeof(struct node));
                if ((*root) -> choices[i] == NULL)
                {
                    perror("Memory allocation failed");
                    exit(1);
                }
                strncpy((*root) -> choices[i] -> question, line, MAX_QLEN);
            }
        }
    }

    // while(!feof(file))
    // {
    //     char *question = strtok(line, ":");
    //     char *choice1 = strtok(NULL, ":");
    //     char *choice2 = strtok(NULL, ":");

    //     if(question && choice1 && choice2)
    //     {
    //         struct node *n = (struct node *)malloc(sizeof(struct node));
    //         if(n = NULL)
    //         {
    //             perror("Memory allocation failed");
    //             exit(1);
    //         }
            
    //         strcpy(n -> question, question);

    //         n -> choices[0] = (struct node *)malloc(sizeof(struct node));
    //         n -> choices[1] = (struct node *)malloc(sizeof(struct node));

    //         if(n -> choices[0] == NULL || n -> choices[1] == NULL)
    //         {
    //             perror("Memory allocation failed");
    //             exit(1);
    //         }

    //         int q = 4;
    //         int count = 4;

    //         while(q != 3)
    //         {
    //                 strcpy(n -> choices[0] -> question, choice1);
    //                 n -> choices[0] -> choices[0] = NULL;
    //                 n -> choices[0] -> choices[1] = NULL;
                    
    //                 strcpy(n -> choices[1] -> question, choice2);
    //                 n -> choices[1] -> choices[0] = NULL;
    //                 n -> choices[1] -> choices[1] = NULL;
                    
    //                 *root = n;
    //             q--;
    //         }
    //     }
    // }
    fclose(file);
    return 0;
}


void careeGuidance(struct node *current)
{
    if(current == NULL)
    {
        printf("Woah, you got your career choice!");
        return;
    }

    printf("%s (1 / 0) ", current -> question);

    char choice;

    if(scanf("%c", &choice) != 1)
    {
        printf("Invalid input. Please enter 1 or 0.\n");
        careerGuidance(current);
        return;
    }

    if(choice == '1' && current -> choices[0])
    {
        careerguidance(current -> choices[0]);
    }
    else if(choice == '0' && current -> choices[1])
    {
        careerGuidajnce(current -> choices[1]);
    }
    else
    {
        printf("Inavlid input, Please enter 1 or 0.\n");
        careerGuidacne(current);
    }
    
}

int main(int argc, char* argv[])
{
    if(argc != 2)
    {
        printf("Usage: %s <tree_file.txt>\n", argv[0]);
        return 1;
    }

    struct node *root = NULL;
    loadtree(argv[1], &root);

    printf("Welcome to the Career Guidance System!\n");
    printf("Choose your branch and streams as per your interests.\n");

    careerGuidance(root);

    free(root -> choices[0]);
    free(root -> choices[1]);
    free(root);

    return 0;
}