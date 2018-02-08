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
using P = pair<pi,int>;

const int B = 320;
const int Q = 100000;
const int N = 100002;

ll p[N];
// p[i][-k,0,k]
int f[N][3];

// ((R,L),qid)
vector<P> query[B];
ll ans[Q];

int L=1, R=0;
int ct[3*N]={};
ll now = 0;

void pr(){
    ++R;
    now += ct[f[R][0]];
    ++ct[f[R][1]];
}

void mr(){
    --ct[f[R][1]];
    now -= ct[f[R][0]];
    --R;
}

void pl(){
    --ct[f[L-1][1]];
    now -= ct[f[L-1][2]];
    ++L;
}

void ml(){
    --L;
    now += ct[f[L-1][2]];
    ++ct[f[L-1][1]];
}

int main(){
    int n;
    ll k;
    cin >>n >>k;

    vector<ll> a(n);
    rep(i,n)
    {
        cin >>a[i];
        if(a[i]==2) a[i] = -1;
    }
    rep(i,n){
        ll t;
        cin >>t;
        a[i] *= t;
    }

    // prefix sum
    p[0]=0;
    for(int i=1; i<=n; ++i) p[i] = p[i-1]+a[i-1];

    // 座標圧縮
    vector<ll> kk({-k,0,k});
    vector<ll> uniq_p;
    rep(i,n+1){
        for(ll j:kk) uniq_p.pb(p[i]+j);
    }
    sort(all(uniq_p));
    uniq_p.erase(unique(all(uniq_p)), uniq_p.end());

    rep(i,n+1){
        rep(j,3){
            ll val = p[i]+kk[j];
            f[i][j] = lower_bound(all(uniq_p),val) - uniq_p.begin();
        }
    }

    // クエリを左端をキーにして平方分割
    int q;
    cin >>q;
    rep(i,q){
        int l,r;
        cin >>l >>r;
        query[l/B].pb({{r,l},i});
    }

    ++ct[f[0][1]];
    rep(i,B){
        sort(all(query[i]));

        for(const auto &qq:query[i]){
            int l = qq.fi.se, r = qq.fi.fi, qid = qq.se;
            while(R<r) pr();
            while(r<R) mr();
            while(L<l) pl();
            while(l<L) ml();
            ans[qid] = now;
        }
    }

    rep(i,q) cout << ans[i] << endl;
    return 0;
}
