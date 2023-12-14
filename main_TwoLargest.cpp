//create a list and find the two largest numbers in the list 

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

void TwoLargest(vector <int> a);

int main(void)
{
    vector <int> a;
    int list;
    int n=0;
    int i=0;
    cout<<"enter the size of your list: "<<endl;
    cin>>n;
    cout<<"Enter a list of integers: "<<endl;
    while(i < n)
    {
        cin>>list;
        a.push_back(list);
        i++;
    }
    TwoLargest(a);
    return 0;
}



void TwoLargest(vector <int> a)
{
    int large_1 = 0;
    int large_2 = 0;
    for( int i = 1 ; i < a.size(); i++)
    {
        if (a[i] > large_1)
        {
            large_2 = large_1;
            large_1 = a[i];
        }
        else if(large_2 < a[i])
        {
            large_2 = a[i];
        }
    }
    cout<<large_1<<" "<<large_2<<endl;
}
