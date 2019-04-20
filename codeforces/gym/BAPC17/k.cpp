#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0; (i)<(int)n; ++(i))
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define pb push_back

const int N = 1000;
vector<int> G[N];

int main(){
    int n;
    cin >>n;
    vector<string> s(n);
    rep(i,n) cin >>s[i];

    rep(i,n)rep(j,n)if(i!=j){
        if(s[i][j]=='1'){
            G[i].pb(j);
        }
    }

    vector<bool> vis(n);
    vector<int> t;
    queue<int> que;

    vis[0]=true;
    que.push(0);
    t.pb(0);
    while(!que.empty()){
        int v = que.front();
        que.pop();
        for(int e:G[v]){
            if(!vis[e]){
                vis[e] = true;
                que.push(e);
                t.pb(e);
            }
        }
    }

    if(t.size()!=n) cout << "impossible" << endl;
    else{
        reverse(all(t));
        rep(i,n) cout << t[i] << " \n"[i==n-1];
    }
}
