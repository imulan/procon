#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
#define dbg(x) cout<<#x" = "<<((x))<<endl
template<class T,class U> ostream& operator<<(ostream& o, const pair<T,U> &p){o<<"("<<p.fi<<","<<p.se<<")";return o;}
template<class T> ostream& operator<<(ostream& o, const vector<T> &v){o<<"[";for(T t:v){o<<t<<",";}o<<"]";return o;}

const int N = 1010;

bool dp[N][N][2];
bool use[N][N][2];
int f;

bool dfs(int e, int o, int turn){
    if(use[e][o][turn]) return dp[e][o][turn];
    if(e+o==2){
        if(o==2){
            return f%2==0;
        }
        else{
            return f%2==1;
        }
    }

    bool ret;
    if(turn==0){
        ret = false;
        if(o>=2) ret |= dfs(e+1,o-2,!turn);
        if(e>=1 && o>=1) ret |= dfs(e-1,o,!turn);
        if(e>=2) ret |= dfs(e-1,o,!turn);
    }
    else{
        ret = true;
        if(o>=2) ret &= dfs(e+1,o-2,!turn);
        if(e>=1 && o>=1) ret &= dfs(e-1,o,!turn);
        if(e>=2) ret &= dfs(e-1,o,!turn);
    }

    use[e][o][turn] = true;
    return dp[e][o][turn] = ret;
}

int main(){
    int V;
    cin >>V;
    vector<string> a(V);
    rep(i,V) cin >>a[i];

    int E = 0;
    vector<vector<int>> G(V);
    rep(i,V)rep(j,V)if(a[i][j]=='Y'){
        G[i].pb(j);
        ++E;
    }
    E /= 2;

    int e = 0, o = 0;
    vector<bool> vis(V);
    rep(i,V)if(!vis[i]){
        int ct = 1;
        vis[i] = true;
        queue<int> que;
        que.push(i);
        while(!que.empty()){
            int now = que.front();
            que.pop();
            for(int nx:G[now]){
                if(!vis[nx]){
                    vis[nx] = true;
                    ++ct;
                    que.push(nx);
                }
            }
        }

        if(ct%2==0) ++e;
        else ++o;
    }

    f = V*(V-1)/2 - E;
    cout << (dfs(e,o,0)?"Taro":"Hanako") << endl;
    return 0;
}
