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

int solve()
{
    int n;
    cin >>n;
    vector<int> x(n);
    rep(i,n) cin >>x[i];
    sort(all(x));
    return x[n-1] - x[0];
}

int main()
{
    int t;
    cin >>t;
    while(t--) cout << solve() << endl;
    return 0;
}
