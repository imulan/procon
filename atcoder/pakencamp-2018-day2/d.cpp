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

struct SegTree{
    int n; vector<ll> dat;
    //初期化
    SegTree(int _n){
        n=1;
        while(n<_n) n*=2;
        dat=vector<ll>(2*n-1,0);
    }

    void update(int k, ll a){
        k+=n-1;
        dat[k]=a;
        //更新
        while(k>0){
            k=(k-1)/2;
            dat[k]=dat[2*k+1]+dat[2*k+2];
        }
    }

    void add(int k, ll a){
        k+=n-1;
        dat[k]+=a;
        //更新
        while(k>0){
            k=(k-1)/2;
            dat[k]=dat[2*k+1]+dat[2*k+2];
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
    //[a,b)
    ll query(int a, int b){
        return _query(a,b,0,0,n);
    }
};

int main(){
    int n,m;
    string s;
    cin >>n >>s >>m;

    vector<char> d(m),f(m);
    rep(i,m) cin >>d[i] >>f[i];

    int q;
    cin >>q;
    vector<vector<pi>> QUERY(m);
    rep(i,q){
        int t,p;
        cin >>t >>p;
        QUERY[t-1].pb({p,i});
    }

    const int N = 464646;
    SegTree st(N);

    bool white = true;
    if(s[0]=='B') white = false;

    int lidx = 150000, ridx = 150000;
    int ss = 0;
    while(ss<n){
        int ee = ss;
        while(ee<n && s[ss]==s[ee]) ++ee;
        st.add(ridx, ee-ss);
        // dbg(ee-ss);
        ++ridx;
        ss = ee;
    }

    auto ASK = [&](int pos){
        int L = 0, R = ridx-lidx;
        while(R-L>1){
            int mid = (L+R)/2;
            int sum = st.query(lidx,lidx+mid);
            if(sum<pos) L = mid;
            else R = mid;
        }
        return (R-1)%2;
    };

    vector<char> ans(q,'B');
    rep(i,m){
        if(d[i]=='L'){
            if(white ^ (f[i]=='B')){
                st.add(lidx,1);
            }
            else{
                if(ridx-lidx == 1){
                    st.update(lidx-1,1);
                    --lidx;
                }
                else{
                    ll a = st.query(lidx,lidx+1) + 1;
                    st.add(lidx+1,a);
                    ++lidx;
                }
                white = !white;
            }
        }
        else{
            bool r_white = white;
            if( (ridx-lidx)%2==0 ) r_white = !r_white;

            if(r_white ^ (f[i]=='B')){
                st.add(ridx-1,1);
            }
            else{
                if(ridx-lidx == 1){
                    st.update(ridx,1);
                    ++ridx;
                }
                else{
                    ll a = st.query(ridx-1,ridx) + 1;
                    st.add(ridx-2,a);
                    --ridx;
                }
            }
        }

        // printf(" lidx ridx %d %d\n",lidx,ridx);

        for(const auto &pp:QUERY[i]){
            int p = pp.fi, idx = pp.se;
            int aa = ASK(p);
            if(white ^ aa) ans[idx] = 'W';
        }
    }

    rep(i,q) cout << ans[i] << "\n";
    return 0;
}
