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

vector<int> divisor(int x)
{
    vector<int> ret;
    for(int i=1; i*i<=x; ++i)
    {
        if(x%i==0)
        {
            ret.pb(i);
            if(i!=x/i) ret.pb(x/i);
        }
    }
    sort(all(ret));
    return ret;
}

int solve()
{
    int n;
    cin >>n;
    vector<int> s(n);
    rep(i,n) cin >>s[i];

    for(int cycle:divisor(n))
    {
        bool ok = true;
        rep(i,cycle)
        {
            for(int j=i; j<n; j+=cycle) ok &= (s[i]==s[j]);
        }
        if(ok) return n/cycle;
    }

    return 1;
}

int main()
{
    cout << solve() << endl;
    return 0;
}
