/*
 a) create n nodes
 b) delete from the end
 c) insert at the beginning
 */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

struct dlinked{
    struct dlinked *left;
    int data;
    struct dlinked *right;
};
typedef struct dlinked node ;
node *start = NULL;


//prototypes
node *getNode();
void doubleL_createlist(int n);
void doubleL_delete_end();
void doubleL_insert_beg();
void display();

int main(void)
{
    int n;
    int menu  = 0 ;
    cout<<"enter an integer for size of list: ";
    cin>>n;
    doubleL_createlist(n);
    cout<<"Here is your list:"<<endl;
    display();
    cout<<endl;
    cout<<"enter 1 for delete at the end, ";
    cout<<"enter 2 for insert at the beginning ";
    cout<<"enter 3 for exit: ";
    cin>>menu;
    switch(menu)
    {
        case 1:
            doubleL_delete_end();
            break;
        case 2:
            doubleL_insert_beg();
            break;
        case 3:
            break; 
    }
    cout<<"Here is your list: "<<endl;
    display();
}

node *getNode(){
    node *newnode;
    newnode = (node*)malloc(sizeof(node));
    cout<<"\n enter data: ";
    cin>>newnode->data ;
    newnode->left = NULL ;
    newnode->right = NULL ;
    return newnode;
}

/*
 a)create n nodes
 */
void doubleL_createlist(int n)
{
    int i;
    node *newnode;
    node *temp;
    for(i = 0; i < n; i ++)
    {
        newnode = getNode();
        if(start == NULL)
        {
            start = newnode;
        }
        else
        {
            temp = start;
            while(temp->right)
            {
                temp = temp->right;
            }
            temp->right = newnode;
            temp->left = temp;
        }
    }
}

/*
 b) delete from the end
 */

void doubleL_delete_end()
{
    node *temp;
    if(start == NULL)
    {
        cout<<"\n Empty list"<<endl;
        return;
    }
    temp = start ;
    start = temp->right;
    start->left= NULL;
    free(temp);
}

/*
 c) insert at the beginning
 */
void doubleL_insert_beg()
{
    node *newnode;
    newnode = getNode();
    if(start == NULL)
    {
        start = newnode ;
        return ;
    }
    newnode->right = start;
    start->left = newnode;
    start = newnode;
}

void display()
{
    node *temp = start;
    if(start == NULL)
    {
        cout<<"\n Empty list"<<endl;
        return;
    }
    while (temp != NULL)
    {
        cout<<temp->data;
        cout<<" ";
        temp = temp->right;
    }
    
}

