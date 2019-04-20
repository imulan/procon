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

const int N = 500000;
vector<int> G[N];

int main(){
    int n,m;
    scanf(" %d %d", &n, &m);

    rep(i,m){
        int a,b;
        scanf(" %d %d", &a, &b);
        --a;
        --b;
        G[a].pb(b);
        G[b].pb(a);
    }

    const int INF = 2*n;

    bool odd_loop = false;
    int ans = 0;
    vector<int> d(n,INF);
    rep(i,n){
        if(d[i]<INF) continue;
        ++ans;

        vector<int> cc;
        queue<int> que;
        d[i] = 0;
        cc.pb(i);
        que.push(i);
        while(!que.empty()){
            int v = que.front();
            que.pop();
            for(int e:G[v]){
                if(d[e] > d[v]+1){
                    d[e] = d[v]+1;
                    que.push(e);
                    cc.pb(e);
                }
            }
        }

        if(!odd_loop){
            for(int v:cc){
                for(int e:G[v]){
                    if(d[v]%2 == d[e]%2) odd_loop = true;
                }
            }
        }
    }

    if(odd_loop) --ans;
    printf("%d\n", ans);
    return 0;
}
