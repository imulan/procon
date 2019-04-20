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

void solve()
{
    int n,q;
    scanf(" %d %d", &n, &q);
    vector<int> a(n);
    rep(i,n) scanf(" %d", &a[i]);

    rep(i,q)
    {
        int l,r;

        scanf(" %d %d", &l, &r);
        vector<int> x(a.begin()+l-1,a.begin()+r);

        scanf(" %d %d", &l, &r);
        vector<int> y(a.begin()+l-1,a.begin()+r);

        sort(all(x));
        sort(all(y));

        // dbg(x);
        // dbg(y);

        int d=0;
        rep(j,x.size()) d+=(x[j]!=y[j]);

        printf("%s\n", (d<=1)?"YES":"NO");
    }
}

int main()
{
    int T;
    scanf(" %d", &T);
    while(T--) solve();
    return 0;
}
