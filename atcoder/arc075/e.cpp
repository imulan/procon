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

const ll INF = 123456789012LL;

struct SumSegTree{
    int n; vector<ll> dat;
    //初期化
    SumSegTree(int _n){
        n=1;
        while(n<_n) n*=2;
        dat=vector<ll>(2*n-1,0);
    }
    //k番目(0-indexed)に+a
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

int main()
{
    int n;
    ll K;
    scanf(" %d %lld", &n, &K);

    vector<ll> a(n);
    rep(i,n)
    {
        scanf(" %lld", &a[i]);
        a[i] -= K;
    }

    // rep(i,n) printf(" a[ %d] %lld\n", i,a[i]);

    ll s=0;
    vector<ll> sum(n);
    rep(i,n)
    {
        s += a[i];
        sum[i]=s;
        // printf("sum[%d]= %lld\n", i,s);
    }

    vector<ll> sorted_sum(sum);
    sort(all(sorted_sum));
    sorted_sum.erase(unique(all(sorted_sum)),sorted_sum.end());

    map<ll,int> val2id;
    int V = 0;
    for(const auto &x:sorted_sum) val2id[x]=V++;

    SumSegTree st(V);
    rep(i,n) st.add(val2id[sum[i]],1);

    ll ans = 0;
    ll now = 0;
    rep(i,n)
    {
        int idx = lower_bound(all(sorted_sum),now)-sorted_sum.begin();
        ans += st.query(idx,V);

        now += a[i];
        st.add(val2id[sum[i]],-1);
    }

    printf("%lld\n", ans);
    return 0;
}
