#include<bits/stdc++.h>
#define ll long long
#define M 1000000007
#define x first
#define y second
using namespace std;

template <typename T,typename U>                                                   
pair<T,U> operator+(const pair<T,U> & l,const pair<T,U> & r)
{   
    return {l.first+r.first,l.second+r.second};                                    
}  

const ll N=200005;
ll pw(ll a,ll p,ll mod)
{
    ll result=1;
    while(p>0)
    {
        if(p&1)
        result=(1LL*a*result)%mod;
        a=(1LL*a*a)%mod;
        p>>=1;
    }
    return result;
}

ll fact[200005];
ll invfact[200005];

void init()
{
    ll p=M;
    fact[0]=1;
    ll i;
    
    for(i=1;i<N;i++)
    {
        fact[i]=1LL*i*fact[i-1]%p;
    }
    i--;
    invfact[i]=pw(fact[i],p-2,p);
    
    for(i--;i>=0;i--)
    {
        invfact[i]=1LL*invfact[i+1]*(i+1)%p;
    }
}

ll ncr(ll n,ll r)
{
    if(r>n||n<0||r<0)
      return 0;
    
    return 1LL*fact[n]*invfact[r]%M*invfact[n-r]%M;
}

ll ncrr(int n,int r)
{
    if(r>n||n<0||r<0)
      return 0;
    
    return 1ll*n*(n-1)/2;

}

void solve()
{
    int n;
    cin>>n;
    vector<ll> v;
    for(int i=0;i<n;i++)
    {
        ll a;
        cin>>a;
        v.push_back(a);
    }

    sort(v.begin(),v.end());

    int lptr=0;
    int rptr=0;
    vector<int> visited(n+1,0);
    ll sum=0;

    while(true)
    {
        while(rptr<v.size()  and v[rptr]-v[lptr]<=2)
        {
            if(!visited[rptr])
            {
                sum+=(1ll*ncrr(rptr-lptr,2));
                visited[rptr]=1;
            }
            rptr+=1;

        }

            if(rptr==v.size())
            break;

            lptr+=1;

            if(lptr>rptr)
            {
                rptr=lptr;
            }

    }

    cout<<sum<<endl;
    return;

}

signed main()
{
   ios_base::sync_with_stdio(false);
    cin.tie(NULL);
     
     init();
    int t=1;
    cin>>t;
    while(t--)
    {
    solve();
    }


    return 0;
}