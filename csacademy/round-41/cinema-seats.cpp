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
    string s;
    cin >>s;

    int n = s.size();

    int l = 0;
    while(s[l]=='1') ++l;
    int r = n-1;
    while(s[r]=='1') --r;

    s = s.substr(l,r-l+1);
    n = s.size();

    int st = 0;
    vector<int> x;
    int one = 0;
    rep(i,n)
    {
        if(s[i]=='1')
        {
            ++one;
            x.pb(i-st);
            st = i+1;
        }
    }
    x.pb(n-st);

    if(one == 1) return n-1;

    int X = x.size();
    int ret = 1;
    rep(i,X) ret = max(ret,x[i]);
    rep(i,X-1)
    {
        ret = max(ret,x[i]+x[i+1]+1);
    }
    return ret;
}

int main()
{
    cout << solve() << endl;
    return 0;
}
