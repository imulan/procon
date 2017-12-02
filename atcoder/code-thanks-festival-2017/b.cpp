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

bool p(string s)
{
    int S = s.size();
    rep(i,S)if(s[i]!=s[S-1-i]) return false;
    return true;
}

int solve(const string &s)
{
    int S = s.size();
    rep(i,S+1)
    {
        string t = s;
        string add = s.substr(0,i);
        reverse(all(add));
        t += add;
        // dbg(t);
        if(p(t)) return i;
    }
}

int main()
{
    string s;
    cin >>s;
    cout << solve(s) << endl;
    return 0;
}
