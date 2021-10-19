#include<iostream>
using namespace std;
int sol(int inp){
    if(inp<4) return 0;
    return sol(inp-2) + (inp/2 - 1);
}
int main(){
    int t;
    cin>>t;
    int b[t];
    for(int i=0;i<t;++i) cin>>b[i];
    for(int i=0;i<t;++i) cout << sol(b[i]) << endl;
    return 0; 
}
