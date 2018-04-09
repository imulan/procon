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

using pi = pair<int,int>;

const int N = 1010;
vector<int> G[N];

vector<int> BFS(int start, int n){
    vector<int> d(n,N);
    d[start] = 0;
    queue<int> que;
    que.push(start);
    while(!que.empty()){
        int now = que.front();
        que.pop();
        for(int e:G[now]){
            if(d[e] > d[now]+1){
                d[e] = d[now]+1;
                que.push(e);
            }
        }
    }
    return d;
}

int main(){
    int n,m,s,t;
    cin >>n >>m >>s >>t;
    --s;
    --t;

    set<pi> E;
    rep(i,m){
        int u,v;
        cin >>u >>v;
        --u;
        --v;
        if(u>v) swap(u,v);

        G[u].pb(v);
        G[v].pb(u);
        E.insert({u,v});
    }

    vector<int> ds = BFS(s,n), dt = BFS(t,n);

    int ans = 0;
    rep(i,n)rep(j,i){
        if(E.count({j,i})) continue;

        int D = min(ds[i]+dt[j], ds[j]+dt[i])+1;
        if(D>=ds[t]) ++ans;
    }
    cout << ans << endl;
    return 0;
}
