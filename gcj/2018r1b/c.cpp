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

const ll INF = 1000000000000LL;

ll solve(){
    int m;
    scanf(" %d", &m);

    vector<vector<int>> r(m,vector<int>(2));
    rep(i,m){
        rep(j,2){
            scanf(" %d", &r[i][j]);
            --r[i][j];
        }
    }

    vector<ll> g(m);
    rep(i,m) scanf(" %lld", &g[i]);

    auto check = [&](ll x){
        vector<ll> t(g);

        queue<int> que;
        que.push(0);
        vector<int> upd(m);
        while(!que.empty()){
            int now = que.front();
            que.pop();
            ++upd[now];
            if(upd[now]>m+1) break;

            ll tneed = -t[now];
            if(now==0) tneed = x-t[now];

            t[now] += tneed;
            rep(i,2){
                t[r[now][i]] -= tneed;
               if(t[r[now][i]]<0) que.push(r[now][i]);
            }
        }

        // dbg(x);
        // dbg(t);

        if(t[0]<x) return false;
        for(int i=1; i<m; ++i)if(t[i]<0) return false;
        return true;
    };

    ll L=g[0], R=INF;
    while(R-L>1){
        ll mid = (L+R)/2;
        if(check(mid)) L = mid;
        else R = mid;
    }
    return L;
}

int main(){
    int T;
    scanf(" %d", &T);
    rep(i,T) printf("Case #%d: %lld\n",i+1,solve());
    return 0;
}
