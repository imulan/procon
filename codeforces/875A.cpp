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

int calc(int n)
{
    int r = n;
    while(n)
    {
        r+=n%10;
        n/=10;
    }
    return r;
}

int main()
{
    int n;
    cin >>n;

    vector<int> ans;
    for(int i=max(1,n-100); i<=n; ++i)
    {
        if(calc(i) == n) ans.pb(i);
    }

    cout << ans.size() << '\n';
    for(int i:ans) cout << i << '\n';
    return 0;
}
