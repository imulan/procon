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

using P = pair<ll,int>;

const int N = 200002;
const int B = 1890;
const int SZ = 106;

int a[B][SZ];
ll pre[B][SZ];
ll add[B];
P S[B][SZ];

inline int QUERY(int idx, int val){
    int bid = idx/SZ;

    int ADD = val-a[bid][idx%SZ];
    for(int i=bid+1; i<B; ++i) add[i] += ADD;
    for(int i=idx%SZ+1; i<SZ; ++i) pre[bid][i] += ADD;

    a[bid][idx%SZ] = val;

    rep(i,SZ) S[bid][i] = {pre[bid][i]-a[bid][i], i};
    sort(S[bid], S[bid]+SZ);

    rep(i,B){
        int tt = lower_bound(S[i], S[i]+SZ, P(-add[i],0)) - S[i];
        if(tt<SZ && S[i][tt].fi==-add[i]){
            return i*SZ + S[i][tt].se + 1;
        }
    }
    return -1;
}

int main(){
    int n,q;
    scanf(" %d %d", &n, &q);

    ll s = 0;
    rep(i,n){
        int v;
        scanf(" %d", &v);
        a[i/SZ][i%SZ] = v;
        pre[i/SZ][i%SZ] = s;
        s += v;
    }


    // initialize
    rep(i,B){
        rep(j,SZ) S[i][j] = {pre[i][j]-a[i][j], j};
        sort(S[i], S[i]+SZ);
    }

    // query
    rep(_,q){
        int p,x;
        scanf(" %d %d", &p, &x);

        int ans = QUERY(p-1,x);
        if(ans>n) ans = -1;
        printf("%d\n", ans);
    }
    return 0;
}
