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
    string s,t;
    cin >>s >>t;

    int n = s.size();

    int a[26]={}, b[26]={};
    rep(i,n) ++a[s[i]-'a'];
    rep(i,n) ++b[t[i]-'a'];

    rep(i,26)
    {
        if(a[i]>0 && b[i]==0)
        {
            if(a[i]>=2) return "A";

            bool ok = true;
            rep(j,26)
            {
                if(b[j]>0 && a[j]==0) ok = false;
            }
            if(ok) return "A";
        }
    }
    return "B";
}

int main()
{
    int T;
    cin >>T;
    while(T--) cout << solve() << endl;
    return 0;
}
