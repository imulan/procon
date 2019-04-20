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
using pp = pair<pi,int>;

const int N=1000000;
bool prime[N];
int P=0;
vector<int> p;
unordered_map<int,int> p2id;

struct BIT{
    // [1,n]
    int n; vector<ll> bit;
    // 初期化
    BIT(int _n){
        n = _n;
        bit = vector<ll>(n+1,0);
    }
    // sum of [1,i]
    ll sum(int i){
        ll s = 0;
        while(i>0){
            s += bit[i];
            i -= i & -i;
        }
        return s;
    }
    // add x in i-th element
    void add(int i, ll x){
        while(i<=n){
            bit[i] += x;
            i += i & -i;
        }
    }
};

map<int,int> factorize(int x)
{
    map<int,int> ret;
    int t=x;
    for(int i=2; i*i<=x; ++i)
    {
        while(t%i==0)
        {
            ++ret[i];
            t/=i;
        }
    }
    if(t>1) ret[t]=1;
    return ret;
}

const int PR=79000;
vector<pi> req[PR];
vector<pp> query[PR];

int main()
{
    fill(prime,prime+N,true);
    prime[0]=prime[1]=false;
    for(int i=2; i<N; ++i)
    {
        if(prime[i]) for(int j=2*i; j<N; j+=i) prime[j]=false;
    }

    rep(i,N)if(prime[i])
    {
        p.pb(i);
        p2id[i]=P++;
    }

    int n;
    scanf(" %d", &n);
    rep(i,n)
    {
        int a;
        scanf(" %d", &a);
        for(const auto &d:factorize(a)) req[p2id[d.fi]].pb(pi(i+1,d.se));
    }

    int Q;
    scanf(" %d", &Q);
    rep(i,Q)
    {
        int L,R,X,Y;
        scanf(" %d %d %d %d", &L, &R, &X, &Y);
        if(X>2)
        {
            int idx = upper_bound(all(p),X-1)-p.begin()-1;
            query[idx].pb(pp(pi(L,R),2*i));
        }
        if(Y>=2)
        {
            int idx = upper_bound(all(p),Y)-p.begin()-1;
            query[idx].pb(pp(pi(L,R),2*i+1));
        }
    }

    vector<ll> ans(2*Q);
    BIT bit(n);
    rep(i,PR)
    {
        for(const auto &r:req[i]) bit.add(r.fi,r.se);
        for(const auto &q:query[i])
        {
            int ans_idx = q.se;
            pi range = q.fi;

            ans[ans_idx] = bit.sum(range.se) - bit.sum(range.fi-1);
        }
    }

    rep(i,Q) printf("%lld\n", ans[2*i+1]-ans[2*i]);
    return 0;
}
