// Gleb Zvonkov
// April 8, 2021

#include "headers.h"

int main(int argc, const char * argv[]) {

    struct node *root= NULL;  //create a empty root for the BST
    struct node **rootpointer= &root; //create a pointer to the root
    
    char option = doMenu(rootpointer); //prints the menu options
    
    while (option != 'q'){  //repeatedly prints menu options until q is entered
        option = doMenu(rootpointer);
    }
    
    printf("\nProgram Quit Succesfully \n"); //printed once loop is exited, so program is quit
    
    return 0;
}
