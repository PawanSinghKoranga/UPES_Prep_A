#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool is_prime[100005];

int main()
{   
    ll n;
    cin>>n;
    n=n+1;
    for(ll i=2;i<=n;i++)
    {
        is_prime[i]=true;
    }

    for(ll i=2;i<=n;i++)
    {
        if(!is_prime[i])
        continue;

        for(ll num=i*2;num<=n;num+=i)
        {
            is_prime[num]=false;
        }
    }
    
    if(n==2)
    {
        cout<<"1";
        cout<<endl<<"1";

        return 0;
    }
    else
    if(n==3)
    {
        cout<<"1";
        cout<<endl<<"1 1";

        return 0;
    }
    else
    {
        cout<<"2"<<endl;
        for(ll i=2;i<=n;i++)
        {
            if(is_prime[i])
            cout<<"1 ";
            else
            cout<<"2 ";
        }
        cout<<endl;
    
    }
    

}