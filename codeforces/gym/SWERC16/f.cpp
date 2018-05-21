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

struct SumSegTree{
    int n; vector<ll> dat;
    //初期化
    SumSegTree(int _n){
        n=1;
        while(n<_n) n*=2;
        dat=vector<ll>(2*n-1,0);
    }
    //k番目(0-indexed)の値をaに変更
    void update(int k, ll a){
        k+=n-1;
        dat[k]=a;
        //更新
        while(k>0){
            k=(k-1)/2;
            dat[k] = dat[2*k+1]+dat[2*k+2];
        }
    }
    //内部的に投げられるクエリ
    ll _query(int a, int b, int k, int l, int r){
        if(r<=a || b<=l) return 0;

        if(a<=l && r<=b) return dat[k];

        ll vl=_query(a,b,2*k+1,l,(l+r)/2);
        ll vr=_query(a,b,2*k+2,(l+r)/2,r);
        return vl+vr;
    }
    //[a,b)の最大値を求める
    ll query(int a, int b){
        return _query(a,b,0,0,n);
    }
};

const int N = 100010;
vector<int> G[N];
int d[N];
int L[N],R[N];

int ct = 0;
vector<int> et;
void dfs(int x){
    et.pb(x);
    L[x] = ct++;
    for(int ch:G[x]){
        d[ch] = d[x]+1;
        dfs(ch);
    }
    R[x] = ct;
}

using pi = pair<int,int>;
using P = pair<pi,int>;

int main(){
    int n;
    cin >>n;

    int root = -1;
    vector<int> m(n), r(n), t(n);
    rep(i,n){
        cin >>m[i] >>r[i] >>t[i];
        --m[i];
        if(m[i]>=0) G[m[i]].pb(i);
        else root = i;
    }
    assert(root != -1);

    d[root] = 0;
    dfs(root);
    // dbg(et);

    vector<P> v(n);
    rep(i,n) v[i] = {{r[i], d[i]}, i};
    sort(all(v));

    SumSegTree st(n);
    vector<ll> ans(n);
    rep(i,n){
        int idx = v[i].se;
        ans[idx] = st.query(L[idx], R[idx]);
        st.update(L[idx], t[idx]);
    }

    rep(i,n) cout << ans[i] << "\n";
    return 0;
}
