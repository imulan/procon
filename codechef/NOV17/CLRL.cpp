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

string solve()
{
    int n,r;
    scanf(" %d %d", &n, &r);
    vector<int> a(n);
    rep(i,n) scanf(" %d", &a[i]);

    int L = 0, R = 1145141919;
    rep(i,n)
    {
        if(!(L<=a[i] && a[i]<=R)) return "NO";
        if(i==n-1) break;

        if(a[i]>a[i+1]) R = min(R,a[i]);
        else L = max(L,a[i]);
    }

    return "YES";
}

int main()
{
    int T;
    cin >>T;
    while(T--) cout << solve() << endl;
    return 0;
}
