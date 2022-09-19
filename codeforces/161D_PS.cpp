
#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll k;
vector<ll>vec[505];
void dfs(vector<ll>adj[],ll x,ll p)
{
    vec[0][x]=1;
    for(auto i:adj[x])
    {
        if(i!=p)
        {
            dfs(adj,i,x);
            for(ll j=0;j<=k;j++)
            {
                vec[j+1][x]+=vec[j][i];
            }
        }
    }
}

void dfs2(vector<ll>adj[],ll x,ll p)
{
    for(auto i:adj[x])
    {
        if(i!=p)
        {
            for(ll j=k;j>=0;j--)
            {
                vec[j+1][i]+=vec[j][x];
                if(j!=0)
                    vec[j+1][i]-=vec[j-1][i];
            }
            dfs2(adj,i,x);
        }
    }
}

void solve()
{
    ll n;cin>>n>>k;
    vector<ll>adj[n];
    for(ll i=0;i<n-1;i++)
    {
        ll a,b;cin>>a>>b;
        a-=1;
        b-=1;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(ll i=0;i<505;i++)vec[i].assign(n,0);

    dfs(adj,0,-1);
    dfs2(adj,0,-1);

    // for(ll i=0;i<=10;i++)
    // {
    //   for(ll j=0;j<n;j++)
    //   {
    //     cout<<vec[i][j]<<" ";
    //   }
    //   cout<<endl;
    // }
    ll ans=0;
    for(ll i=0;i<n;i++)ans+=vec[k][i];
    cout<<ans/2<<endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    int T=1;
    // cin>>T;
    // cin.ignore(); must be there when using getline(cin, s)
    while(T--)
    {
        solve();
    }
    return 0;}
