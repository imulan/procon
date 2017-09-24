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

void query(ll A, const vector<ll> &B)
{
    ll ans = LLONG_MAX;

    int n = B.size();
    int base = lower_bound(all(B),-A)-B.begin();
    for(int i=-1; i<=1; ++i)
    {
        int idx = base+i;
        if(0<=idx && idx<n) ans = min(ans,abs(A+B[idx]));
    }

    printf("%lld\n",ans);
}

int main()
{
    int n,m,q;
    scanf(" %d %d %d", &n, &m, &q);
    vector<ll> a(n),b(m);
    rep(i,n) scanf(" %lld", &a[i]);
    rep(i,m) scanf(" %lld", &b[i]);

    ll A = 0;
    int sgn = 1;
    rep(i,n)
    {
        A += sgn*a[i];
        sgn *= -1;
    }

    vector<ll> B(m-n+1);
    sgn = -1;
    rep(i,n)
    {
        B[0] += sgn*b[i];
        sgn *= -1;
    }

    sgn *= -1;
    ll tb = B[0];
    for(int i=1; i<=m-n; ++i)
    {
        tb += b[i-1];
        tb = -tb;
        tb += sgn*b[n+i-1];
        B[i] = tb;
    }

    sort(all(B));

    query(A,B);

    while(q--)
    {
        int l,r,x;
        scanf(" %d %d %d", &l, &r, &x);

        int d = r+1-l;
        if(d%2==1)
        {
            if(l%2==1) A += x;
            else A -= x;
        }

        query(A,B);
    }

    return 0;
}
