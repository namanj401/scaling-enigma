#include<bits/stdc++.h>
using namespace std;
typedef pair<long long int,long long int> pa;
#define pb push_back
#define  MAX 400009
#define ll long long int
#define ld long double
long long int mod=998244353;
long long int MOD=1e9+7;
long long int INF=1e18;
ld PI=3.14159265358979323846264338327950;
ll dx[]={0,1,0,-1};
ll dy[]={-1,0,1,0};
void solve()
{
    ll n,k;
    cin>>n>>k;
    ll arr[n];
    ll max=-1000000;
    ll pro;
    for(ll i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for(ll i=0;i<n;i++)
    {
        for(ll j=i+1;j<n;j++)
        {
            pro=((i+1)*(j+1))-(k*(arr[i]|arr[j]));
            if(pro>max)
            {
                max=pro;
            }
        }
    }
    cout<<max<<endl;
}
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        solve();
    }
}
