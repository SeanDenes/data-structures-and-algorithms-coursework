#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

void selectionSort (int a[], int n);

int main(){
    int n = 0 ;
    cout<<"Enter lenght of list"<<endl;
    cin>>n ;
    int a[n];
    cout<<"Enter each element of unsorted list one at a time:"<<endl;
    for(int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    cout<<"Unsorted list: "<<endl;
    for(int i = 0; i<n; i++)
    {
        cout<<a[i]<<endl;
    }
    selectionSort(a,n);
    cout<<"Sorted list:"<<endl;
    for(int i = 0; i<n; i++)
    {
        cout<<a[i]<<endl;
    }
    
    return 0;
}

//selection sort, decreasing
void selectionSort (int a[], int n)
{
    int maxIndex = 0;
    for(int i = 0 ; i < (n-2); i++)
    {
        maxIndex = i;
        for(int j=(i+1);j<(n-1);j++)
        {
            if(a[j] > a[maxIndex])
            {
                maxIndex = j;
            }
        }
        int temp = a[i];
        a[i] = a[maxIndex];
        a[maxIndex] = temp ;
    }
}



