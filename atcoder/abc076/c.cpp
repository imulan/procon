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

const string NG = "UNRESTORABLE";

string solve()
{
    string s,t;
    cin >>s >>t;
    int S = s.size(), T = t.size();

    string ans = "|";
    rep(i,S-T+1)
    {
        bool match = true;
        rep(j,T)if(s[i+j]!='?' && s[i+j]!=t[j]) match = false;
        if(!match) continue;

        string a = s;
        rep(j,T) a[i+j]=t[j];
        rep(j,S)if(a[j]=='?') a[j]='a';

        ans = min(ans,a);
    }

    if(ans == "|") ans = NG;
    return ans;
}

int main()
{
    cout << solve() << endl;
    return 0;
}
