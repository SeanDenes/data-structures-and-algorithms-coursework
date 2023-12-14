//find the gcd of 2 integers 

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;
vector <int> ExEuclidian(int a, int b);

int main()
{
    vector <int> x;
    int a,b;
    cout<<"GCD calculator"<<endl;
    cout<<"enter an integer"<<endl;
    cin>>a;
    cout<<"enter another integer"<<endl;
    cin>>b;
    x = ExEuclidian(a,b);
    for(int i = 0; i < x.size(); i++)
    {
        cout<<x[i]<<" ";
    }
    return 0;
}

vector <int> ExEuclidian(int a, int b)
{
    vector <int> x;
    int s = 0;
    int old_s = 1;
    int t = 1;
    int old_t = 0;
    int r = b;
    int old_r = a;
    int temp1 = 0;
    int temp2 = 0;
    int temp3 = 0;
    while(r!=0)
    {
        int q = old_r/r ;
        
        temp1 = old_r;
        old_r = r;
        //r = old_r - q * r ;
        r = temp1 - q * r;
        
        temp2 = old_s;
        old_s = s;
        //s = old_s - q * s;
        s = temp2 - q * s;
        
        temp3 = old_t;
        old_t = t;
        //t = old_t - q * t;
        t = temp3 - q * t;
    }
    cout<<"GCD is: "<<old_r<<endl;
    cout<<"old_t:"<<old_t; 
    x.push_back(old_t);
    x.push_back(old_s);
    
    return x;
}

