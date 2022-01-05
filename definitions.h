// Gleb Zvonkov
// April 8, 2021

#ifndef definitions_h
#define definitions_h

    typedef struct node{  //node structure
     int data;  //data store in node
     struct node* right; //pointer to right child
     struct node* left;  //pointer to left child
    } NODE;
    
    struct node *newNode(int ); //creates a new node
    struct node* insert(struct node*, int ); //inserts a new node
    struct node* deleteNode(struct node*, int ); //deletes a node in BST
    void deleteTree(struct node* ); //delete entire BST

    void printPostorder(struct node* ); //print in post order
    void printInorder(struct node* ); // print in order
    void printPreorder(struct node* ); // print pre order
    void printLevel(struct node* ,struct node* , int ); //print given level of BST
    void print(struct node* ); //print level by level

    int search(struct node* , int ); //search for value in BST
    int height(struct node* );  //compute the height of the subtree
    int numLeafs(struct node* ); //print number of leafs in BST
    int count(struct node* ); //count the number of nodes in BST

    void storeNodes (struct node* , NODE** ,int* ); //store the nodes of BST in an array
    struct node* createTree(NODE ** , int ,int ); //method creates a balanced new tree given inorder array of nodes
    struct node* balanceTree(struct node* ); //balance the BST

    struct node* doOption(char, struct node*); // contains cases for all menu options each option calls a BST method
    char doMenu ( struct node** ); //prints all menu options and passes root to doOption method

    
#endif /* definitions_h */
