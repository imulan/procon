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

const string OK = "Yes", NG = "No";

string solve()
{
    int n;
    cin >>n;
    vector<int> a(n);
    rep(i,n) cin >>a[i];

    sort(all(a));

    if(a[n-1]-a[0]>=2) return NG;

    if(a[0]==1)
    {
        for(int i=1; i<n; ++i)if(a[1]!=a[i]) return NG;
        return OK;
    }

    if(a[0] == a[n-1])
    {
        if(a[0]<=n/2 || a[0]==n-1) return OK;
        return NG;
    }
    else
    {
        int x = a[0], y = a[n-1];

        int X=0,Y=0;
        rep(i,n)
        {
            if(a[i]==x) ++X;
            else ++Y;
        }

        if(y==n-1)
        {
            if(Y==2) return OK;
            return NG;
        }

        int need = y+1+(x-X);

        if(X<=x && Y>=2 && need<=n) return OK;
        return NG;
    }
}

int main()
{
    cout << solve() << endl;
    return 0;
}
