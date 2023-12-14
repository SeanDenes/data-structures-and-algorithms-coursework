#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

vector <int> Binary(int k);
int ModularExpo(int a, vector <int> K, int n);

int main (void)
{
    int a = 0;
    int k = 0;
    int n = 0;
    cout<<"Enter a base:"<<endl;
    cin>>a ;
    cout<<"enter the power:"<<endl;
    cin>>k ;
    cout<<"Enter the modulus:"<<endl;
    cin>>n;
    
    vector <int> K = Binary(k);
    
    int b = ModularExpo(a, K, n);
    
    cout<<b<<endl;
    
    return 0;
}




vector <int> Binary(int k)
{
    vector <int> K;
    int temp = k;
    int i = 0;
    while(temp > 0)
    {
        K.push_back(temp % 2);
        temp = (temp - K[i])/2;
        i++;
    }
    return K;
}

int ModularExpo(int a, vector <int> K, int n)
{
    if(n == 1)
        return 0;
    int b = 1;
    if (K.empty())
        return b;
    int A = a;
    if(K[0] == 1)
    {
        b = a;
    }
    for( int i = 0; i < K.size(); i++)
    {
        A = A * A % n;
        if (K[i] == 1)
        {
            b = A * b % n;
        }
    }
    return b ;
}
