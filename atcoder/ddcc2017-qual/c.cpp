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

int main()
{
    int n;
    ll c;
    cin >>n >>c;
    vector<ll> x(n);
    rep(i,n) cin >>x[i];

    sort(all(x));

    int l = 0, r = n;
    while(r-l>1)
    {
        int m = (l+r)/2;
        if(2*m-1>=n)
        {
            r = m;
            continue;
        }

        bool ok = true;
        rep(i,m)
        {
            if(x[i]+x[2*m-1-i]+1>c) ok = false;
        }


        if(ok) l=m;
        else r=m;
    }

    cout << n - l << endl;
    return 0;
}
