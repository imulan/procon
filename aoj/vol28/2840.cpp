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
    string t,p;
    cin >>t >>p;

    int T = t.size(), P = p.size();

    vector<int> a,b;
    int idx = 0;
    rep(i,T)
    {
        if(idx<P && t[i] == p[idx])
        {
            a.pb(i);
            ++idx;
        }
    }

    if(a.size()!=P) return "no";

    idx = P-1;
    for(int i=T-1; i>=0; --i)
    {
        if(idx>=0 && t[i]==p[idx])
        {
            b.pb(i);
            --idx;
        }
    }
    reverse(all(b));

    rep(i,a.size())if(a[i]!=b[i]) return "no";
    return "yes";
}

int main()
{
    cout << solve() << endl;
    return 0;
}
