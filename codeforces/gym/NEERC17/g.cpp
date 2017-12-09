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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using P = pair<ll,int>;

template<class Key>
using ordered_set = __gnu_pbds::tree<Key, __gnu_pbds::null_type, less<Key>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

const int N=30000;
const ll INF = LLONG_MAX/3;
int n,r,k;
ll a[N],b[N],c[N];
ll sa[N],sb[N],sc[N];
ll x[N];

bool check(ll m)
{
    ll ct = 0;

    ordered_set<P> S,T;
    queue<P> que;
    for(int i=1; i<r; ++i)
    {
        S.insert({x[i],i});
        que.push({x[i],i});
    }
    for(int i=r; i<=n-r; ++i) T.insert({x[i],i});

    ll add_s=0, add_t=0, add_all=0;

    rep(i,n-r)
    {
        // count
        ct += S.order_of_key({m-add_s-add_all,191919});
        ct += T.order_of_key({m-add_t-add_all,191919});

        // process
        int j = i+r;

        S.insert({x[j]-add_s+add_t,j});
        que.push({x[j]-add_s+add_t,j});
        S.erase(que.front());
        que.pop();
        T.erase({x[j],j});

        add_all += a[i]-b[i];
        add_s += c[j]-b[j];
        add_t += b[j]-a[j];
    }

    return ct>=k;
}

int main()
{
    scanf(" %d %d %d", &n, &r, &k);
    rep(i,n) scanf(" %lld", &a[i]);
    rep(i,n) scanf(" %lld", &b[i]);
    rep(i,n) scanf(" %lld", &c[i]);

    sa[0]=a[0];
    sb[0]=b[0];
    sc[0]=c[0];
    for(int i=1; i<n; ++i){
        sa[i] = sa[i-1]+a[i];
        sb[i] = sb[i-1]+b[i];
        sc[i] = sc[i-1]+c[i];
    }

    fill(x,x+N,INF);
    for(int i=1; i<=n-r; ++i){
        ll v = sa[n-1];
        v -= sa[r-1];
        v += sb[r-1];
        v -= (sa[i+r-1]-sa[i-1]);
        v += (sb[i+r-1]-sb[i-1]);
        if(i<=r-1){
            v -= 2*(sb[r-1]-sb[i-1]);
            v += (sa[r-1]-sa[i-1]);
            v += (sc[r-1]-sc[i-1]);
        }

        x[i] = v;
    }

    ll L=0, R=30000000003LL;
    while(R-L>1){
        ll m=(L+R)/2;
        if(check(m)) R=m;
        else L=m;
    }
    cout << R << endl;
    return 0;
}
