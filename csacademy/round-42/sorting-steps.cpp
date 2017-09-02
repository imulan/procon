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
    rep(i,n) ret[i] = lower_bound(all(s),a[i])-s.begin()+1;
    return ret;
}

int main()
{
    int n;
    cin >>n;
    vector<int> a(n);
    rep(i,n) cin >>a[i];

    a = comp(a);

    ll ans = 1;
    BIT bit(n+1);
    rep(i,n)
    {
        ans = max(ans,bit.sum(n)-bit.sum(a[i])+1);
        bit.add(a[i],1);
    }

    cout << ans << endl;
    return 0;
}
