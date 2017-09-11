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

const int N = 1000010;
int n;
int a[N],r[N];

int main()
{
    scanf(" %d", &n);
    rep(i,n) scanf(" %d", &a[i]);

    fill(r,r+N,-1);
    double ans = 0;
    ll s = 0;
    rep(i,n)
    {
        s += i-r[a[i]];
        ans += s;
        r[a[i]] = i;
    }

    ans*=2;
    ans-=n;
    rep(i,2) ans/=n;
    printf("%.10f\n", ans);
    return 0;
}
