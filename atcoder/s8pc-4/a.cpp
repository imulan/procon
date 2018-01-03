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

int main()
{
    int n;
    cin >>n;
    vector<string> s(n);
    rep(i,n) cin >>s[i];
    string t;
    cin >>t;

    int l=1,r=1;

    rep(i,n)
    {
        string a=s[i], z=s[i];
        rep(j,a.size())if(a[j]=='?')
        {
            a[j]='a';
            z[j]='z';
        }

        r += (a<=t);
        l += (z<t);
    }

    vector<int> ans;
    for(int i=l; i<=r; ++i) ans.pb(i);
    int A = ans.size();
    rep(i,A) cout << ans[i] << " \n"[i==A-1];
    return 0;
}
