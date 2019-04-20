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

const string OK = "yes", NG = "no";

string solve()
{
    int n;
    cin >>n;
    vector<int> a(n);
    rep(i,n) cin >>a[i];

    vector<int> rev_a(a);
    reverse(all(rev_a));

    if(a[0]!=1 || a[n-1]!=1) return NG;
    rep(i,n)if(a[i]>7) return NG;
    rep(i,n)if(a[i]!=rev_a[i]) return NG;

    // 一番左の7の一番右の7を見つける
    int sl = 0;
    while(sl<n && a[sl]!=7) ++sl;
    int sr = n-1;
    while(sr>=0 && a[sr]!=7) --sr;

    if(sl>sr) return NG;
    for(int i=sl; i<=sr; ++i)if(a[i]!=7) return NG;

    for(int i=0; i<sl; ++i)
    {
        if(a[i+1]-a[i]!=0 && a[i+1]-a[i]!=1) return NG;
    }
    for(int i=sr; i<n-1; ++i)
    {
        if(a[i+1]-a[i]!=0 && a[i+1]-a[i]!=-1) return NG;
    }

    return OK;
}

int main()
{
    int T;
    cin >>T;
    while(T--) cout << solve() << endl;
    return 0;
}
