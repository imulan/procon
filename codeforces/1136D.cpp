#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
#define dbg(x) cout<<#x" = "<<((x))<<endl
template<class T,class U> ostream& operator<<(ostream& o, const pair<T,U> &p){o<<"("<<p.fi<<","<<p.se<<")";return o;}
template<class T> ostream& operator<<(ostream& o, const vector<T> &v){o<<"[";for(T t:v){o<<t<<",";}o<<"]";return o;}

const int N = 300003;
set<int> G[N];

int main(){
    int n,m;
    scanf(" %d %d", &n, &m);

    vector<int> p(n);
    rep(i,n){
        scanf(" %d", &p[i]);
        --p[i];
    }

    int tg = p[n-1];
    vector<bool> use(n);
    rep(i,m){
        int u,v;
        scanf(" %d %d", &u, &v);
        --u;
        --v;
        G[u].insert(v);
        if(v == tg) use[u] = true;
    }

    int ans = 0;
    vector<int> obj;
    for(int i=n-2; i>=0; --i){
        if(use[p[i]]){
            bool ok = true;
            for(int j:obj){
                if(!G[p[i]].count(j)){
                    ok = false;
                    break;
                }
            }
            if(ok) ++ans;
            else obj.pb(p[i]);
        }
        else obj.pb(p[i]);
    }
    printf("%d\n", ans);
    return 0;
}
