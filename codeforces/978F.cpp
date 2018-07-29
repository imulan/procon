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

const int N = 200002;
vector<int> G[N],Q[N];

int main(){
    int n,k;
    scanf(" %d %d", &n, &k);

    vector<int> r(n);
    rep(i,n) scanf(" %d", &r[i]);

    rep(i,k){
        int x,y;
        scanf(" %d %d", &x, &y);
        --x;
        --y;
        G[x].pb(y);
        G[y].pb(x);
    }

    vector<int> ur(r);
    sort(all(ur));
    ur.erase(unique(all(ur)), ur.end());
    int UR = ur.size();

    rep(i,n){
        int idx = lower_bound(all(ur), r[i]) - ur.begin();
        Q[idx].pb(i);
    }

    vector<int> ans(n);
    int ct = 0;
    rep(i,UR){
        int RANK = ur[i];
        for(int j:Q[i]){
            ans[j] = ct;
            for(int nx:G[j]){
                if(r[nx]<RANK) --ans[j];
            }
        }
        ct += Q[i].size();
    }

    rep(i,n) printf("%d%c", ans[i], " \n"[i==n-1]);
    return 0;
}
