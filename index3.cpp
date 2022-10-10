#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define ld long double
#define MAX 200010
#define MOD 1000000007
#define INF 1e15
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pi 3.14159265358979323846
#define endl "\n"
#define coutflg if(flg){cout << "YES\n";}else{cout << "NO\n";}
#define coutyes cout << "YES\n";
#define coutno cout << "NO\n";
#define flush fflush(stdout);
#define fixedprec cout << fixed << setprecision(18);

int countCompanies(int n, vector<int> from, vector<int> to, vector<int> wt){
    map<int,vector<pair<int,int>>> mp;
    int m = wt.size();
    for(int i=0;i<m;i++){
        mp[wt[i]].push_back({from[i],to[i]});
    }
    int ans = 0;
    int acnt = 0;
    for(auto it:mp){
        // cout << it.first << endl;
        // for(auto pa:it.second){
        //     cout << pa.first << " " << pa.second << endl;
        // }
        vector<int> a[n+1];
        for(auto pa:it.second){
            a[pa.first].push_back(pa.second);
            a[pa.second].push_back(pa.first);
        }
        int vis[n+1];
        memset(vis,0,sizeof(vis));
        queue<int> q;
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                q.push(i);
                vis[i] = 1;
                int maxa = i;
                int maxa2 = 0;
                int cnt = 1;
                while(!q.empty()){
                    int s = q.front();
                    q.pop();
                    for(auto x:a[s]){
                        if(!vis[x]){
                            q.push(x);
                            vis[x] = 1;
                            cnt++;
                            if(x>=maxa){
                                maxa2 = maxa;
                                maxa = x;
                            }
                            else if(x>maxa2){
                                maxa2 = x;
                            }
                        }
                    }
                }
                if(cnt>acnt && cnt>1){
                    acnt = cnt;
                    ans = maxa*maxa2;
                }
                else if(cnt==acnt){
                    ans = max(ans,maxa*maxa2);
                }
            }
        }
    }
    return ans;
}

void solve(){
    int n,m;
    cin >> n >> m;
    vector<int> from(m),to(m),wt(m);
    for(int i=0;i<m;i++){
        cin >> from[i] >> to[i] >> wt[i];
    }
    cout << countCompanies(n,from,to,wt) << endl;
}

int main(){

    #ifndef ONLINE_JUDGE
        // for getting input from input.txt
        freopen("input.txt", "r", stdin);
        // for writing output to output.txt
        // freopen("output.txt", "w", stdout);
    #endif

    fast
    ll t,q;
    q = 1;
    // cin >> q;
    for(t=1;t<=q;t++){
        // cout << "Case #" << t << ": ";
        solve();
    }
}
