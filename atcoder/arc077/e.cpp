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

const int N = 100001;
vector<int> d[N],r[N];

int main()
{
    int n,m;
    cin >>n >>m;
    vector<int> a(n);
    rep(i,n)
    {
        cin >>a[i];
        --a[i];
    }

    ll ans = 0;
    int dec = 0;

    rep(i,n-1)
    {
        int D = a[i+1]-a[i];
        if(D<0) D = a[i+1]+m-a[i];

        if(D>1)
        {
            // dbg(a[i+1]);
            r[a[i+1]].pb(i);

            int idx = a[i+1] - D+2;
            if(idx<0) idx += m;
            // printf(" D %d idx %d\n", D,idx);

            d[idx].pb(i);
            if(idx==0 || idx>a[i+1]) ++dec;
        }

        ans += min(D,1+a[i+1]);
    }
    // dbg(ans);

    ll t = ans;

    for(const auto v:r[0])
    {
        int D = a[v+1]-a[v];
        if(D<0) D = a[v+1]+m-a[v];

        --dec;
        // dbg(D);
        t += D-1;
    }

    for(int x=1; x<m; ++x)
    {
        for(const auto &v:d[x]) ++dec;

        t -= dec;
        ans = min(ans,t);

        // printf(" x %d: dec = %d, t %lld\n", x,dec,t);

        for(const auto v:r[x])
        {
            int D = a[v+1]-a[v];
            if(D<0) D = a[v+1]+m-a[v];

            --dec;
            // dbg(D);
            t += D-1;
        }
    }

    cout << ans << endl;
    return 0;
}
