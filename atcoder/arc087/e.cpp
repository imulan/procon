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

const ll mod1=1000000009,mod2=1000000007;

set<string> comp;
set<string> part;

vector<int> v;
void dfs(string s, int d)
{
    if(d==-1) return;

    if(comp.count(s)) return;
    if(!part.count(s))
    {
        v.pb(d);
        return;
    }

    dfs(s+'0',d-1);
    dfs(s+'1',d-1);
}

int main()
{
    int n;
    ll L;
    cin >>n >>L;
    vector<string> s(n);
    rep(i,n) cin >>s[i];

    rep(i,n)
    {
        string t = "";
        int SZ = s[i].size();
        rep(j,SZ-1)
        {
            t += s[i][j];
            part.insert(t);
        }
        comp.insert(s[i]);
    }
    part.insert("");

    dfs("",L);

    // dbg((vector<string>(all(part))));
    // dbg(v);

    int x=v.size();
    rep(i,v.size()) x+=v[i];

    string ans = "Alice";
    if(v.size()==0 || (v.size()>1 && x%2==0)) ans = "Bob";

    cout << ans << endl;
    return 0;
}
