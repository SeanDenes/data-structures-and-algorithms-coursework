/*
 Sean Denes
 Assignment 4; Part 1
 Insert, Delete, and Display using a queue DS (FIRST IN FIRST OUT)
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <queue>
using namespace std;


struct singleLinked{
    int data;
    struct singleLinked *next;
};
typedef struct singleLinked node;
node *start = NULL;

//prototypes
node *getNode();
void createlist(int n);
void display();
void enqueue();
void dequeue();

int main()
{
    int n;
    int menu  = 0 ;
    cout<<"enter an integer for size of list: ";
    cin>>n;
    createlist(n);
    cout<<"Here is your list:"<<endl;
    display();
    cout<<endl;
    while(menu != 3)
    {
        cout<<"enter 1 for enqueue, ";
        cout<<"enter 2 for dequeue, ";
        cout<<"enter 3 for exit ";
        cin>>menu;
        switch(menu)
        {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                break;
        }
        cout<<"Here is your list: "<<endl;
        display();
        cout<<endl;
    }
    return 0;
}
//inserts a node at the end of the queue
void enqueue()
{
    node *newnode;
    node *temp;
    newnode = getNode();
    if(start == NULL)
    {
        start = newnode;
    }
    else
    {
        temp = start;
        while(temp->next)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}
//deletes the first node in the queue
void dequeue()
{
    node *temp;
    if(start == NULL)
    {
        cout<<"Queue is empty"<<endl;
        return;
    }
    else
    {
        temp = start;
        start = temp->next;
        free(temp);
        cout<<"Node Deleted"<<endl;
    }
}
//creates a new node
node *getNode()
{
    node * newnode;
    newnode = (node *) malloc(sizeof(node));
    cout<<"\n enter data: ";
    cin>>newnode -> data;
    newnode->next = NULL;
    return newnode;
}
//creates n nodes in the queue
void createlist(int n)
{
    node * newnode;
    node * temp;
    for(int i = 0 ; i < n; i++)
    {
        newnode = getNode();
        if(start == NULL)
        {
            start = newnode;
        }
        else
        {
            temp = start;
            while(temp -> next != NULL)
            {
                temp = temp->next ;
            }
            temp->next = newnode;
        }
    }
}
//display data
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
        temp = temp->next;
    }
    
}
