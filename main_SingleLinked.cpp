/*
 a) Create n nodes
 b) delete from middle
 c) insert in the middle
 */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

struct singleLinked{
    int data;
    struct singleLinked *next;
};
typedef struct singleLinked node;
node *start = NULL;

//prototypes
node *getNode();
int countnode(node *start);
void createlist(int n);
void delete_from_mid();
void insert_in_middle();
void display();

//driver
int main(void)
{
    int n;
    int menu  = 0 ;
    cout<<"enter an integer for size of list: ";
    cin>>n;
    createlist(n);
    cout<<"Here is your list:"<<endl;
    display();
    cout<<endl;
    cout<<"enter 1 delete from middle, ";
    cout<<"enter 2 for insert in the middle: ";
    cout<<"enter 3 for exit";
    cin>>menu;
    switch(menu)
    {
        case 1:
            delete_from_mid();
            break;
        case 2:
            insert_in_middle();
            break;
        case 3:
            break;
    }
    cout<<"Here is your list: "<<endl;
    display();
    return 0;
}


//creates a new node
node *getNode()
{
    node * newnode;
    newnode = (node *) malloc(sizeof(node));
    cout<<"\n enter data:";
    cin>>newnode -> data;
    newnode->next = NULL;
    return newnode;
}
//counts nodes
int countnode(node *start)
{
    if(start == NULL)
        return 0;
    else
        return (1 + countnode(start->next));
}

/*
 a) Create n nodes
*/

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

/*
 b) delete from middle
*/

void delete_from_mid()
{
    int ctr = 1 ;
    int pos, nodectr;
    node *temp, *prev;
    if(start == NULL)
    {
        cout<<"\n Empty list"<<endl;
        return;
    }
    else
    {
        cout<<"\n Enter the pposition of the node";
        cin>>pos;
        nodectr = countnode(start);
        if(pos>nodectr)
        {
            cout<<"This node does not exist"<<endl;
        }
        else if(pos > 1 && pos < nodectr)
        {
            prev = start;
            temp = prev;
            while(ctr < pos)
            {
                prev = temp;
                temp = temp->next;
                ctr++;
            }
            prev->next = temp->next;
            free(temp);
            cout<<"Node deleted"<<endl;
        }
        else
        {
            cout<<"Invalid position"<<endl;
        }
    }
}

/*
 c)insert in the middle
*/

void insert_in_middle()
{
    node *newnode, *temp, *prev;
    int pos, nodectr;
    int ctr = 1;
    newnode = getNode();
    cout<<"\n Enter position:";
    cin>>pos;
    nodectr = countnode(start);
    if(pos>1 && pos < nodectr)
    {
        prev = start;
        temp = prev;
        while(ctr < pos)
        {
            prev = temp;
            temp = temp->next;
            ctr++;
            
        }
        prev->next = newnode;
        newnode->next = temp;
    }
    else
    {
        cout<<"postion "<<pos<<" is not an intermediate position"<<endl;
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
