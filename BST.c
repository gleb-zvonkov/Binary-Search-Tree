// Gleb Zvonkov
// April 8, 2021

#include "headers.h"
 

struct node *newNode(int item){ //create new node
    struct node *leaf = (struct node *)malloc(sizeof(struct node)); // dynamically allocate memory for new node
    leaf->data = item; // set data
    leaf->left = leaf->right = NULL; //set both children to null
    return leaf; //return the new node
}


struct node* insert(struct node* node, int data){ //insert new node, does not check for duplicate data
    if (node == NULL) return newNode(data); // If the tree is empty, return a new node
    if (data < node->data) //   Otherwise, recur down the tree
    node->left = insert(node->left, data);
    else
    node->right = insert(node->right, data);
    return node; // return the (unchanged) node pointer
}


struct node * minValueNode(struct node* node ){ // finds minimum value from given node
    struct node* current = node;
    while (current && current->left != NULL) // loop down to find the leftmost leaf
        current = current->left;
    return current;
}


struct node* deleteNode(struct node* root, int data ){ // delete node
    if (root == NULL) return root; //if no tree then return root
    if (data < root->data) //recur down left subtree
        root->left = deleteNode(root->left, data);
    else if (data > root->data) //recure down right subtree
        root->right = deleteNode(root->right, data);
    else{
        if (root->left == NULL){   // if left subtree is empty
            struct node *temp = root->right;  //set temp to to right subtree
            free(root); //free node
            return temp;
        }
        else if (root->right == NULL){ //if right subtree is empty
            struct node *temp = root->left; //set temp to left subtree
            free(root); // free the node
            return temp;
        }
        struct node* temp = minValueNode(root->right); // find the smallest leaf to the right from this point
        root->data = temp->data; // switch the values
        root->right = deleteNode(root->right, temp->data); // delete unused node
    }
    return root;
}


void printPostorder(struct node* node ){ //post order traversal
    if (node == NULL)
        return;
    printPostorder(node->left); // first recur on left subtree
    printPostorder(node->right); // then recur on right subtree
    printf("%d ", node->data); // now deal with the node
}

void printInorder(struct node* node ){ // in order traversal
    if (node == NULL)
        return;
    printInorder(node->left); // first recur on left child
    printf("%d ", node->data); // then print the data of node
    printInorder(node->right); // now recur on right child
    
}

void printPreorder(struct node* node ){ // pre order traversal
    if (node == NULL)
        return;
    printf("%d ", node->data); //first print data of node
    printPreorder(node->left); // then recur on left sutree
    printPreorder(node->right);  // now recur on right subtree
}


int search(struct node* node, int k ){ // search for value k recursivley return 1 if found, 0 otherwise
    if (node == NULL)
        return 0;
    else if (k == node->data) //value found
        return 1;
    else if (k < node->data)
        return search (node->left, k); //recur down left subtree
    else
        return search (node->right, k); //recur down right subtree
}


int height(struct node* node){
    if (node == NULL)
        return 0;
    else {
        int lh = height(node->left); //compute height of left subtree
        int rh = height(node->right); //compute height of right subtree
        if (lh > rh)
            return (lh + 1); //if left subtree has larger height then print it
        else
            return (rh + 1); //otherwise print right subtree height
    }
}


void printLevel(struct node* root,struct node* parent, int level ){ //print given level
    if (root == NULL)
            return;
    if (level == 1){
        if (root==parent) //if only one node then
            printf("%d ", root->data); //print data
        else{ //if multiple nodes
            if(parent->left==NULL) //if left node is null print x
                printf("x ");
            printf("%d ", root->data); //print data
            if(parent->right==NULL) //if  right node is null print x
                printf("x ");
        }
    }
    else if (level > 1){ //recur throught entire tree to get every node from that level
        printLevel(root->left,root, level-1); //recur in left subtree
        printLevel(root->right,root, level-1); //recure in right subtree
        }
}


void print(struct node* root ){
    int h = height(root); //height of the BST
    int i; //variable to increment with each level
    for (i=1; i<=h; i++){ //run through all levels
            printf("\nDepth (%d) -   ",i); //print depth
            printLevel(root,root, i);  //print the level
        }
}


int numLeafs(struct node* node){ //returns number of leafs in BST
  if(node == NULL)
    return 0;
  if(node->left == NULL && node->right==NULL) //if left and right children are null, then its a leaf so return 1
    return 1;
  else
    return numLeafs(node->left)+numLeafs(node->right); //recur dow left and right subtree and aadd the leafs of each subtree
}


void deleteTree(struct node* node ){//using post order to delete all node of BST
    if (node == NULL)
        return;
    deleteTree(node->left); // first recur on left subtree
    deleteTree(node->right); // then recur on right subtree
    free(node); // free cureent node
}


void storeNodes (struct node* node, NODE** nodes,int* i ){  //store the nodes of BST in an array
    if (node==NULL)
        return;
    storeNodes(node->left,nodes,i); //recur on left subtree
    nodes[(*i)++] = node; //store node in array and increment array index
    storeNodes(node->right,nodes,i); //recur on right subtree, so the array is filled with the node in order
}


struct node* createTree(NODE **nodes, int start,int end){ //method creates a balanced new tree given inorder array of nodes
    if (start > end)
        return NULL;
    int mid = (start + end)/2;
    struct node* root = nodes[mid]; //set new root to middle element of inorder traversal
    root->left  = createTree(nodes, start, mid-1); //recur on left subtree, so left element will be set to middle element of first half of array
    root->right = createTree(nodes, mid+1, end); //recur on right subtree, so right element will be set to middle element of second half of array
    return root; //return the new root that is connected to a balance tree
}


int count(struct node* node){ //count the number of nodes in sub tree
    int c =  1; //variable for count
    if (node ==NULL)
        return 0;
    else{
        c = c+ count(node->left); //recur on left subtree
        c = c+ count(node->right); //recur on right subtree
        return c; //return the count
    }
}


struct node* balanceTree(struct node* root){ //method creates a balanced tree
    int n = count(root); //number of nodes in array
    NODE **nodes = malloc(n * sizeof(*nodes)); //dynamically allocate array of nodes of size n
    int *i =malloc(sizeof(int)) ; //allocate one integer to index array, so it can be passed by refrence
    *i = 0; //set index to 0
    storeNodes(root, nodes, i); //create array of nodes
    free(i); // free the integer used to index
    root= createTree(nodes, 0, n-1); //create the tree
    free(nodes); //free the dynamically allocated array
    return root; //return root to balanced tree
}
