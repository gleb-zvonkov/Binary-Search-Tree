// Gleb Zvonkov
// April 8, 2021

#include "headers.h"


char doMenu ( struct node** rootpointer ){ //pass pointer to root, so pass root by refrence
    char option; //char for the options selected
    printf( "\n=============== Menu ===============\n" );   //print menu
    printf( " i: Insert       | o: In Order \n" );
    printf( " d: Delete       | t: Post Order \n" );
    printf( " p: Print        | r: Pre Order \n" );
    printf( " n: No. of Leafs | b: Balance Tree \n" );
    printf( " x: Destroy Tree | w: Print w Spacing \n" );
    printf( " s: Search       | q: Quit \n" );
    printf( "====================================\n" );
    printf( "Please enter your choice: " );
    
     scanf( " %c", &option ); //scan for user entered option
     option = tolower ( option ); //convert user entered option to lowercase
     *rootpointer = doOption(option, *rootpointer); //set root to root created after option has completed
     return option; //return option, if q is returned program is exited
}


struct node* doOption(char option, struct node* root){
    
    switch (option){  // switch for all options of menu
            
        case '#':{ //hidden case to populate the BST
            int dataAry[] = {1,2,3,4,5,6} ; //value to population
            int n = sizeof(dataAry) / sizeof(dataAry[0]); //size of array
             //n cannot be a constant
             for (int i=0; i < n; i++) //run throught array inserting each element into BST
                root = insert(root, dataAry[i]); //set to root incase root does not exist
          break;
        }

        case '!': { //hidden case to populate the BST
            int dataAry[] = {10,4,18,3,5,2,1,8,7,9,12,16,14,17,22,27,25,32} ; //value to population
            int n = sizeof(dataAry) / sizeof(dataAry[0]); //run throught array inserting each element into BST
             for (int i=0; i < n; i++) //set to root incase root does not exist
                root = insert(root, dataAry[i]); //incase root does not exist
          break;
        }
            
        case 'i':{ //insert option
            int x; //value to be inserted
            printf("\nEnter value to be inserted (insertion does not check for duplicates): ");
            scanf( " %d", &x ); //scan for user input for value to be inserted
            root = insert(root, x);  //incase root does not exist, inserted value becomes root
            printf("The value %d has been succesfully inserted\n",x);
          break;
        }

        case 'd':{ //delete option
            int x; //value to be deleted
            printf("\nEnter Value to be Deleted: ");
            scanf( " %d", &x ); //scan for user input for value to be deleted
            root=deleteNode(root, x); //set to root incase root is deleted
            printf("The Value %d has been Successfully Deleted from the BST\n", x);
          break;
        }
            
        case 'p': //print option
            print(root); //print root level by level
          break;
            
        case 'n': //number of leafs option
            printf("\nNumber of Leafs: %d \n", numLeafs(root)); //print number of leafs
          break;
            
        case 'x': //destory tree option
           deleteTree(root); //delete entire tree
            root = NULL; //set root to null
            printf("\nTree Destroyed Successfully\n");
          break;
            
        case 's':{ //search tree option
            int x; //value to be searched for
            printf("\nEnter Value to Search For: ");
            scanf( " %d", &x );  //scan for value to be search for
            if ( search(root, x) == 1) //if search return 1 then alue found
                printf("The Value %d is in the BST\n", x);
            else //otherwise value not found
                printf("The Value %d is not in the BST\n", x);
         }
          break;
            
        case 'o': // in order option
            printf("\nBegin In Order Traversal \n");
            printInorder(root); //print in order
            printf("\nEnd In Order Traversal \n");
          break;
        
        case 't': //poster order option
            printf("\nBegin Post Order Traversal \n");
            printPostorder(root); //print post order
            printf("\nEnd Post Order Traversal \n");
          break;
            
        case 'r': //pre order option
            printf("\nBegin Pre Order Traversal \n");
            printPreorder(root); //print pre order
            printf("\nEnd Pre Order Traversal \n");
          break;
            
        case 'b': //balance tree option
            root=balanceTree(root);
            printf("\nTree Balanced Successfully\n");
          break;
            
        case 'w': //print w spacing option, this option is not complete
            printf("\nOption Not Complete\n");
          break;
        
        case 'q': //quit option
            printf("\nQuitting Program \n");
            deleteTree(root); //when quitting program delted the tree so all dynamically allocated memory is freed
          break;
            
        default: //incase none of the options are entered
            printf("\nInvalid Option\n");
    }
    
    return root;
}
