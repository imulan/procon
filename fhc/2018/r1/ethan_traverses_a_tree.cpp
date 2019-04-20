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

const int N = 2002;
int n,k;
int a[N],b[N];

vector<int> pre,post;
void dfs(int x){
    pre.pb(x);
    if(a[x]!=-1) dfs(a[x]);
    if(b[x]!=-1) dfs(b[x]);
    post.pb(x);
}

void solve(){
    cin >>n >>k;
    rep(i,n){
        cin >>a[i] >>b[i];
        --a[i];
        --b[i];
    }

    pre.clear();
    post.clear();
    dfs(0);
    // dbg(pre);dbg(post);

    vector<vector<int>> g(n);
    rep(i,n){
        g[pre[i]].pb(post[i]);
        g[post[i]].pb(pre[i]);
    }

    int idx=0;
    vector<int> l(n,-1);
    rep(i,n){
        if(l[i]!=-1) continue;
        l[i] = idx;
        queue<int> que;
        que.push(i);
        while(!que.empty()){
            int v = que.front();
            que.pop();
            for(int nx:g[v]){
                if(l[nx]==-1){
                    l[nx]=idx;
                    que.push(nx);
                }
            }
        }
        ++idx;
        idx %= k;
    }

    bool ok = false;
    rep(i,n) ok |= (l[i]==k-1);

    if(ok) rep(i,n) printf("%d%c", l[i]+1, " \n"[i==n-1]);
    else printf("Impossible\n");
}

int main(){
    int T;
    cin >>T;
    rep(i,T){
        printf("Case #%d: ", i+1);
        solve();
    }
    return 0;
}
