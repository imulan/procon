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

using pi = pair<int,int>;

int literal(const string &s)
{
    int m = 1;
    string t = s;
    if(s[0]=='~')
    {
        t = s.substr(1);
        m = -1;
    }
    return m*atoi(t.c_str());
}

pi clause(const string &s)
{
    int S = s.size();
    string t = s.substr(1,S-2);

    int idx = 0;
    while(t[idx]!='v') ++idx;

    string x = t.substr(0,idx), y = t.substr(idx+1);
    return pi(literal(x),literal(y));
}

vector<pi> cnf(const string &s)
{
    vector<pi> ret;
    int S = s.size();

    int st = 0;
    while(st<S)
    {
        int idx = st;
        while(idx<S && s[idx]!='^') ++idx;

        string t = s.substr(st,idx-st);
        ret.pb(clause(t));
        st = idx+1;
    }
    return ret;
}

int ans = 11;

int n,m;
vector<pi> v;

void dfs(int d, const vector<bool> &tf)
{
    bool fail = false;
    rep(i,m)
    {
        int a = v[i].fi, b = v[i].se;
        bool ok = false;

        if(a>0) ok |= tf[a];
        else ok |= !tf[-a];
        if(b>0) ok |= tf[b];
        else ok |= !tf[-b];

        if(!ok)
        {
            fail = true;

            vector<bool> t(tf);
            t[abs(a)] = !t[abs(a)];
            if(d<10) dfs(d+1,t);

            t = tf;
            t[abs(b)] = !t[abs(b)];
            if(d<10) dfs(d+1,t);

            break;
        }
    }

    if(!fail) ans = min(ans,d);
}

int main()
{
    string s,a;
    cin >>n >>m >>s >>a;

    v = cnf(s);
    vector<bool> tf(n+1);
    rep(i,n) tf[i+1] = (a[i]=='T');

    dfs(0,tf);

    if(ans>10) cout << "TOO LARGE" << endl;
    else cout << ans << endl;
    return 0;
}
