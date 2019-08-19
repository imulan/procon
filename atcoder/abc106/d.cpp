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

int main(){
    int n,m,Q;
    scanf(" %d %d %d", &n, &m ,&Q);

    vector<vector<int>> L(n), R(n);
    rep(i,m){
        int l,r;
        scanf(" %d %d", &l, &r);
        --l;
        --r;
        L[l].pb(i);
        R[r].pb(i);
    }

    vector<vector<int>> ans(n,vector<int>(n));

    rep(i,n){
        vector<bool> v(m);
        int ct = 0;
        for(int j=i; j<n; ++j){
            for(int k:L[j]) v[k] = true;
            for(int k:R[j])if(v[k]) ++ct;
            ans[i][j] = ct;
        }
    }

    rep(i,Q){
        int p,q;
        scanf(" %d %d", &p, &q);
        --p;
        --q;
        printf("%d\n", ans[p][q]);
    }
    return 0;
}
