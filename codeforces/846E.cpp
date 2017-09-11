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

const string ok = "YES", ng = "NO";
const ll INF = 100000000000000000LL; // 10^17

inline ll mul(ll x, ll y)
{
    // x*y>INF
    if(x>INF/y) return -1;
    return x*y;
}

string solve()
{
    int n;
    cin >>n;
    vector<ll> b(n),a(n);
    rep(i,n) cin >>b[i];
    rep(i,n) cin >>a[i];

    vector<int> x(n-1),k(n-1);
    rep(i,n-1)
    {
        cin >>x[i] >>k[i];
        --x[i];
    }

    for(int i=n-1; i>0; --i)
    {
        if(b[i]>=a[i])
        {
            // 余るので親に変えておく
            b[x[i-1]] += b[i]-a[i];
            b[i] = a[i];
        }
        else
        {
            // 足りないので親から借りる
            ll need = mul(a[i]-b[i],k[i-1]);
            if(need==-1) return ng;

            b[x[i-1]] -= need;
            if(b[x[i-1]]<-INF) return ng;

            b[i]=a[i];
        }
    }

    rep(i,n)if(b[i]<a[i]) return ng;
    return ok;
}

int main()
{
    cout << solve() << endl;
    return 0;
}
