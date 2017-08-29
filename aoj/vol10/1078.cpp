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

vector<string> e(string s)
{
    int S = s.size();
    vector<string> ret;

    int st = 0;
    while(st<S)
    {
        int idx = st;
        while(idx<S && s[idx]!='|') ++idx;
        ret.pb(s.substr(st,idx-st));
        st = idx+1;
    }
    return ret;
}

int cv(char c)
{
    if('a'<=c && c<='z') return c-'a';
    return 26+c-'A';
}

bool c(string s)
{
    s = s.substr(1,s.size()-2);
    int S = s.size();

    vector<string> v;
    int st = 0;
    while(st<S)
    {
        int idx = st;
        while(idx<S && s[idx]!='&') ++idx;
        v.pb(s.substr(st,idx-st));
        st = idx+1;
    }

    bool t[52]={}, f[52]={};
    for(string a:v)
    {
        if(a[0]=='~') f[cv(a[1])] = true;
        else t[cv(a[0])] = true;
    }

    rep(i,52)if(t[i]&&f[i]) return false;
    return true;
}

string solve(string s)
{
    for(string a:e(s))if(c(a)) return "yes";
    return "no";
}

int main()
{
    string s;
    while(cin >>s,s!="#") cout << solve(s) << endl;
    return 0;
}
