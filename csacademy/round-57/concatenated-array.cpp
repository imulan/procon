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

ll calc(const string &s)
{
    int n = s.size();
    ll ret = 0;

    ll st = -1;
    rep(i,n)
    {
        if(s[i]=='0')
        {
            ret = max(ret,i-st);
        }
        else
        {
            st = i;
        }
    }

    return ret;
}

ll solve()
{
    int n,k;
    string s;
    cin >>n >>k >>s;

    bool all_zero = true;
    rep(i,n) all_zero &= (s[i]=='0');

    if(all_zero) return (ll)n*k;

    ll ans = calc(s);

    int pre = 0;
    while(s[pre]=='0') ++pre;
    int suf = n-1;
    while(s[suf]=='0') --suf;

    if(k>1) ans = max(ans, (ll)pre+(n-1-suf));

    return ans;
}

int main()
{
    cout << solve() << endl;
    return 0;
}
