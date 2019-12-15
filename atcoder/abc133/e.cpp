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

const ll mod = 1e9+7;

int main(){
    int n;
    ll k;
    cin >>n >>k;

    vector<vector<int>> G(n);
    rep(i,n-1){
        int a,b;
        cin >>a >>b;
        --a;
        --b;
        G[a].pb(b);
        G[b].pb(a);
    }

    rep(i,n){
        if(G[i].size() > k){
            cout << 0 << "\n";
            return 0;
        }
    }

    ll ans = k;
    vector<int> par(n,-1);
    queue<int> que({0});
    while(!que.empty()){
        int now = que.front();
        que.pop();
        ll m = k-2;
        if(now == 0) m = k-1;

        for(int e:G[now])if(e != par[now]){
            (ans *= m) %= mod;
            --m;
            par[e] = now;
            que.push(e);
        }
    }

    cout << ans << "\n";
    return 0;
}
