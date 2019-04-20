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

struct SegTree{
    int n; vector<ll> dat;
    //初期化
    SegTree(int _n){
        n=1;
        while(n<_n) n*=2;
        dat=vector<ll>(2*n-1,LLONG_MAX);
    }
    //k番目(0-indexed)の値をaに変更
    void update(int k, ll a){
        k+=n-1;
        dat[k]=a;
        //更新
        while(k>0){
            k=(k-1)/2;
            dat[k]=min(dat[2*k+1],dat[2*k+2]);
        }
    }
    //内部的に投げられるクエリ
    ll _query(int a, int b, int k, int l, int r){
        if(r<=a || b<=l) return LLONG_MAX;

        if(a<=l && r<=b) return dat[k];

        ll vl=_query(a,b,2*k+1,l,(l+r)/2);
        ll vr=_query(a,b,2*k+2,(l+r)/2,r);
        return min(vl,vr);
    }
    //[a,b)
    ll query(int a, int b){
        return _query(a,b,0,0,n);
    }
};

int main(){
    int n,k;
    cin >>n >>k;
    vector<ll> a(n);
    rep(i,n) cin >>a[i];
    a.pb(0);

    SegTree t(2*n);
    rep(i,n) t.update(i,a[i]);
    t.update(n,0);

    ll ans = 0;
    int w = 0;
    int i = 0;
    while(i<n){
        // printf("now %d w %d\n",i,w);

        int l=0, r=k+1;
        while(r-l>1){
            int mid = (l+r)/2;
            if(t.query(i+1,i+mid+1) <= a[i]) r=mid;
            else l=mid;
        }

        if(r==k+1){
            ll mn = t.query(i+1,i+k+1);
            // dbg(mn);

            l=0;
            r=k+1;
            while(r-l>1){
                int mid = (l+r)/2;
                if(t.query(i+1,i+mid+1) <= mn) r=mid;
                else l=mid;
            }
            // dbg(r);

            int need = k-w;
            // dbg(need);
            w += need;
            ans += a[i]*need;

            i += r;
            w -= r;
        }
        else{
            int need = max(0,r-w);
            // dbg(need);
            w += need;
            ans += a[i]*need;

            i += r;
            w -= r;
        }

    }

    cout << ans << endl;
    return 0;
}
