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

vector<int> comp(const vector<int> &a)
{
    vector<int> s(a);
    sort(all(s));
    s.erase(unique(all(s)),s.end());

    int n = a.size();
    vector<int> ret(n);
    rep(i,n) ret[i] = lower_bound(all(s),a[i])-s.begin();

    return ret;
}

const int N = 100010;
const ll INF = LLONG_MAX/3;
vector<int> pos[N];

BIT bit(N);
ll query(int l, int r)
{
    if(r<l) swap(l,r);
    return bit.sum(r)-bit.sum(l-1);
}

int main()
{
    int n;
    cin >>n;
    vector<int> a(n+1,-1);
    rep(i,n) cin >>a[i+1];

    a = comp(a);
    rep(i,n+1) pos[a[i]].pb(i);
    int M = *max_element(all(a));

    for(int i=1; i<=n; ++i) bit.add(i,1);

    ll dp[2]={};
    for(int i=1; i<=M; ++i)
    {
        for(int j:pos[i]) bit.add(j,-1);

        ll nx[2]={INF,INF};
        int p[2] = {pos[i-1].front(), pos[i-1].back()};
        int nxp[2] = {pos[i].front(), pos[i].back()};

        rep(j,2)rep(k,2)
        {
            // 移動ルート: p[j] -> nxp[k^1] -> nxp[k]
            nx[k] = min(nx[k], dp[j]+query(p[j],nxp[k^1])+query(nxp[k^1],nxp[k]));
        }

        rep(j,2) dp[j] = nx[j];
    }

    cout << min(dp[0],dp[1])+n << endl;
    return 0;
}
