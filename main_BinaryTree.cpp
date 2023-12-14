//Sean Denes
//Assignment 4, part 2: create a binary tree and use in-order traversal to display using stack
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

//nodes in the binary tree
struct BinaryNode
{
    int data;
    struct BinaryNode* left; //points to left child
    struct BinaryNode* right; //points to right child
};
//nodes in the stack to be used to pdisplay in order
struct stackList
{
    int data;
    struct stackList* next;
};
//function to create a binary tree with 7 elements
void createTree();
//function uses stack to display each elemetn in-order
void inOrderDisplay();
//creates a new node for the tree
BinaryNode *getNode(int data);
//creates a new node for the stack
stackList *getNode2(int data);
//initialize global start pointer for tree
BinaryNode* start = NULL;
//initialize global start pointer for stack
stackList* startL = NULL;
//first node in tree
BinaryNode* root = getNode(4);
//first node in stack
stackList* first = getNode2(4);
//adds element to stack
void push(int data);
//removes from stack and displays
void pop(int data);
 

int main()
{
    //make the tree
    createTree();
    //pass tree through the stack for display
    inOrderDisplay();
    return 0;
}

void createTree()
{
    //start pointer points to the location of the root
    start = root;
    //create a tree
    start->left = getNode(2);
    start->left->left = getNode(1);
    start->left->right = getNode(3);
    start->right = getNode(6);
    start->right->left = getNode(5);
    start->right->right = getNode(7);
    /*
     
     looks like:
     
               4
             /    \
            2      6
           / \    / \
          1   3  5   7
     
     */

}
//create empty stack
void inOrderDisplay()
{
    //start points to the first element in the stack
    startL = first;
    //add the elements into the stack in the order which the must be displayed
    //startL->next= getNode2(2);
    //startL->next->next= getNode2(1);
    push(4);
    push(2);
    push(1);
    pop(1);
    pop(2);
    //startL->next->next = getNode2(3);
    push(3);
    pop(3);
    pop(4);
    //startL = getNode2(6);
    //startL->next = getNode2(5);
    pop(5);
    pop(6);
    //startL = getNode2(7);
    push(7);
    pop(7);

    
}
//gets a new node for the tree
BinaryNode *getNode(int data)
{
    BinaryNode *newnode;
    newnode = (BinaryNode*)malloc(sizeof(BinaryNode));
    newnode->data = data;
    newnode->left = NULL ;
    newnode->right = NULL ;
    return newnode;
}
//gets a newnode for the stack
stackList *getNode2(int data)
{
    stackList *newnode;
    newnode = (stackList*)malloc(sizeof(stackList));
    newnode->data = data;
    newnode->next = NULL ;
    return newnode;
}

//puts the info from binary tree into the stack
void push(int data)
{
    stackList* newnode = getNode2(data);
    stackList* temp = startL;
    while(temp->next)
    {
        temp = temp->next;
    }
    temp->next = newnode;
}

//pops info out of stack and displays
void pop(int data)
{
    stackList* temp = startL;
    while(temp->next)
    {
        temp = temp->next;
    }
    temp->next= NULL;
    cout<<data<<"\n";
}
