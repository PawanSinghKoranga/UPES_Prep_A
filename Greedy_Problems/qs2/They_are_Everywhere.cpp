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

void solve()
{
    int n;
    int total;
    set<char> temp;
    cin>>n;
    vector<char> ar;
    for(int i=0;i<n;i++)
    {
        char a;
        cin>>a;
        ar.push_back(a);
        temp.insert(a);
    }

    total=temp.size();
    map<char,int> count;
    set<char> st;

    int lptr=0;
    int rptr=0;

    st.insert(ar[lptr]);
    count[ar[lptr]]+=1;

    int minim=M;

    while(true)
    {

        while(rptr<ar.size() and st.size()<total)
        {
            rptr+=1;
            if(rptr<ar.size())
            {
            st.insert(ar[rptr]);
            count[ar[rptr]]+=1;
            }
        }

        if(st.size()==total)
        {
            minim=min(minim,rptr-lptr+1);
        }
        else
        if(rptr==ar.size())
        {
            rptr-=1;
            break;
        }

        count[ar[lptr]]-=1;
        if(count[ar[lptr]]==0)
        st.erase(st.find(ar[lptr]));
        lptr+=1;

        if(lptr<ar.size() and lptr>rptr)
        {
            rptr=lptr;
            st.insert(ar[rptr]);
            count[ar[rptr]]+=1;
        }
        else
        if(lptr==ar.size())
        break;


    }

    cout<<minim<<endl;

    
}

signed main()
{
   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t=1;
    while(t--)
    {
    solve();
    }


    return 0;
}