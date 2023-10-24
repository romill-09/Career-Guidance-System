#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct node {
    struct node * root;
    struct node * yes;
    struct node * no;
    char data[50];
    
}node;

struct node * createNode(const char * data)
{
    node * newNode = (node *) malloc(sizeof(node));
    if (newNode != NULL)
    {
        strcpy(newNode -> data , data);
        newNode -> yes = NULL;
        newNode -> no = NULL;
    }
    return newNode;
}

void addchild(node * root, const char * yesData, const char * noData)
{
    if (root -> yes == NULL && root -> no == NULL)
    {
        root -> yes = createNode(yesData);
        root -> no = createNode(noData);
    }
}


void addCareerOptions(node * root, char * Further_Studies, const char * Jobs_Certifications)
{
    //Path for Computer Engineering
    root -> yes -> yes = createNode(Further_Studies);
    root -> yes -> no = createNode("Inforamtion Technology Engineering");

    root -> yes -> yes -> yes = createNode("Masters");
    root -> yes -> yes -> no = createNode(Jobs_Certifications);

    root -> yes -> yes -> yes -> yes = createNode("MBA");
    root -> yes -> yes -> no -> yes = createNode("Data Science / Analyst");

    root -> yes -> yes -> yes -> yes -> yes = createNode("Entrepreneurship");
    root -> yes -> yes -> no -> yes -> yes = createNode("Blockchain Developer");

    root -> yes -> yes -> no -> yes -> yes -> yes = createNode("Database Administrator");
    root -> yes -> yes -> no -> yes -> no = createNode("Fullstack Developer");
    
    root -> yes -> yes -> no -> no = createNode("Private Sector");
    root -> yes -> yes -> yes -> no = createNode("Internships/Apprenticeships");

    root -> yes -> yes -> yes -> no -> no = createNode("Civil Services");


    //Path for IT Engineering
    root -> yes -> no -> yes = createNode(Further_Studies);
    root -> yes -> no -> no = createNode("Electrical Engineering");

    root -> yes -> no -> yes -> yes = createNode("Masters");
    root -> yes -> no -> yes -> no = createNode(Jobs_Certifications);

    root -> yes -> no -> yes -> yes -> yes = createNode("MBA");
    root -> yes -> no -> yes -> no -> yes = createNode("Network Administrator");

    root -> yes -> no -> yes -> yes -> yes -> yes = createNode("Entrepreneurship");
    root -> yes -> no -> yes -> no -> no = createNode("Edutech / Fintech jobs");

    root -> yes -> no -> yes -> no -> no -> yes = createNode("biotech jobs");
    root -> yes -> no -> yes -> no -> yes -> yes = createNode("E - Commerce domain"); 

    root -> yes -> no -> yes -> no -> no -> no = createNode("Artificail Inteliigence");
    root -> yes -> no -> yes -> yes -> no = createNode("Internships/Apprenticeships");

    root -> yes -> no -> yes -> yes -> no -> no = createNode("Civil Services");


    //Path for Electrical Engineering
    root -> yes -> no -> no -> yes = createNode(Further_Studies);
    root -> yes -> no -> no -> no = createNode("Mechanical Engineering");

    root -> yes -> no -> no -> yes -> yes = createNode("Masters");
    root -> yes -> no -> no -> yes -> no = createNode(Jobs_Certifications);

    root -> yes -> no -> no -> yes -> yes -> yes = createNode("MBA");
    root -> yes -> no -> no -> yes -> no -> yes = createNode("Telecomuunication domain");

    root -> yes -> no -> no -> yes -> yes -> yes -> yes = createNode("entrepreneurship");
    root -> yes -> no -> no -> yes -> no -> no = createNode("Machine Learning/ IoT");

    root -> yes -> no -> no -> yes -> no -> no -> yes = createNode("Private Sector");
    root -> yes -> no -> no -> yes -> yes -> no = createNode("Internships/Apprenticeships");

    root -> yes -> no -> no -> yes -> yes -> no -> no = createNode("Civil Services"); 


    //Path to Mechanical Engineering
    root -> yes -> no -> no -> no -> yes = createNode(Further_Studies);
    root -> yes -> no -> no -> no -> no = createNode("Please select an appropriate branch.");

    root -> yes -> no -> no -> no -> yes -> yes = createNode("Masters");
    root -> yes -> no -> no -> no -> yes -> no = createNode(Jobs_Certifications);

    root -> yes -> no -> no -> no -> yes -> yes ->yes = createNode("MBA");
    root -> yes -> no -> no -> no -> yes -> no -> yes = createNode("Automobiles");

    root -> yes -> no -> no -> no -> yes -> yes -> yes -> yes = createNode("Entreprenuerships");
    root -> yes -> no -> no -> no -> yes -> no -> no = createNode("Biomedic domain");

    root -> yes -> no -> no -> no -> yes -> no -> yes -> yes = createNode("Aerospace");
    root -> yes -> no -> no -> no -> yes -> no -> no -> no = createNode("IT Sector");

    root -> yes -> no -> no -> no -> yes -> no -> yes -> yes -> no = createNode("Robotics & Automation");
    root -> yes -> no -> no -> no -> yes -> no -> yes -> yes -> no -> no = createNode("Marine/Naval domain");

    root -> yes -> no -> no -> no -> yes -> yes -> no = createNode("Internships/Apprenticeships");
    root -> yes -> no -> no -> no -> yes -> yes -> no -> no = createNode("Civil Services");
}


void displaybranch(node * branch)
{
    if (branch == NULL)
    {
         return;
    }

    printf("Engineering branch: %s\n", branch -> data);

    displaybranch(branch -> yes);
    displaybranch(branch -> no);
}


void careerGuidance(node* current) {
    if (current == NULL) {
        printf("You have reached a career choice!\n");
        return;
    }

    while(current->data != NULL)
    {
        printf("%s (1/0): ", current->data);

        int choice;
        if (scanf("%d", &choice) == 1) {
            if (choice == 1 && current->yes) {
                careerGuidance(current->yes);
            } else if (choice == 0 && current->no) {
                careerGuidance(current->no);
            } else {
                printf("Invalid choice. Please enter 1 or 0.\n");
                careerGuidance(current);
            }
        } else {
            printf("Invalid input. Please enter 1 or 0.\n");
            careerGuidance(current);
        }
    }
}


int main()
{
    node * root = createNode("Select an Engineerng Branch");

    // Prompt the user to choose a branch
    printf("Choose an Engineering Branch:\n");
    printf("1. Computer Engineering\n");
    printf("2. Information Technology Engineering\n");
    printf("3. Electrical Engineering\n");
    printf("4. Mechanical Engineering\n");
    int branchChoice;
    scanf("%d", &branchChoice);



    addchild(root, "Computer Engineerng", "Choose yes and find best suited suggestion for your career ");

    switch (branchChoice) {
        case 1:
            addCareerOptions(root, "Further Studies in Computer Engineering", "Jobs/Certifications in Computer Engineering");
            break;
        case 2:
            addCareerOptions(root, "Further Studies in Information Technology Engineering", "Jobs/Certifications in IT Engineering");
            break;
        case 3:
            addCareerOptions(root, "Further Studies in Electrical Engineering", "Jobs/Certifications in Electrical Engineering");
            break;
        case 4:
            addCareerOptions(root, "Further Studies in Mechanical Engineering", "Jobs/Certifications in Mechanical Engineering");
            break;
        default:
            printf("Invalid choice. Exiting.\n");
            return 1;
    }

    displaybranch(root);

    printf("\nCareer Guidance:\n");
    careerGuidance(root);

    return 0;
}