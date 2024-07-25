#include<bits/stdc++.h>
#define ll long long
#define M 998244353
#define x first
#define y second
using namespace std;

const int N=200005;

ll pw(ll a,ll p,ll mod)
{
    ll result=1;
    while(p>0)
    {
        if(p&1)
        result=(1ll*a*result)%mod;
        a=(1ll*a*a)%mod;
        p>>=1;
    }
    return result;

}

ll fact[N],invfact[N];

void init()
{
    ll p=M;
    fact[0]=1;
    ll i;
    for(i=1;i<N;i++)
    {
       fact[i]=1ll*i*fact[i-1]%p;
    }
    i--;
    invfact[i]=pw(fact[i],p-2,p);

    for(i--;i>=0;i--)
    {
        invfact[i]=1ll*(i+1)*invfact[i+1]%p;
    }
}

ll ncr(ll n, ll r)
{
    if(r>n||n<0||r<0)
    return 0;

    return 1ll*fact[n]*invfact[r]%M*invfact[n-r]%M;
}

void solve()
{
    string s;
    cin>>s;

    vector<ll> zos;
    vector<ll> oos;

    ll preval=-1;
    ll countzero=0;
    ll countone=0;
    
    
    for(ll i=0;i<s.size();i++)
    {


        if(preval!=s[i]&&preval!=-1)
        {
            if(s[i]=='0')
            {
              oos.push_back(countone);
              countone=0;
            }

            if(s[i]=='1')
            {
                zos.push_back(countzero);
                countzero=0;
            }
        }

        if(s[i]=='0')
        countzero+=1;

        if(s[i]=='1')
        countone+=1;

        preval=s[i];
        
    }

    if(countzero)
    zos.push_back(countzero);
    
    if(countone)
    oos.push_back(countone);

    // for(auto t:zos)
    // cout<<t<<" ";
    // cout<<endl;
    // for(auto t:oos)
    // cout<<t<<" ";



    // cout<<zos.size()+oos.size()<<" ";

    ll comb=1;
    ll sp=0;

    for(auto t:zos)
    {
        if(t>1)
        {
        comb=1ll*comb*ncr(t,t-1)%M;
        sp+=(t-1);
        }
    }

    for(auto t:oos)
    {
        if(t>1)
        {
        comb=1ll*comb*ncr(t,t-1)%M;
        sp+=(t-1);
        }
    }



   
//    cout<<comb<<endl<<sp<<endl;

    comb=comb*fact[sp]%M;

    cout<<sp<<" "<<comb<<endl;

    
}


int main()
{

    // cout<<"hellow";
    init();
    int t;
    cin>>t;
    while(t>0)
    {
        solve();
        t--;
    }
    return 0;
}