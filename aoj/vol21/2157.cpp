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

int n;
vector<int> g;

int dfs(const vector<int> &v)
{
    int d = 0;
    while(d<n && v[d]==g[d]) ++d;

    if(d==n) return 0;

    int ret = n;
    vector<int> t(v);
    int z = g[d]-v[d];

    for(int i=d; i<n; ++i)
    {
        t[i] = (t[i]+z+10)%10;
        ret = min(ret,dfs(t)+(z!=0));
    }

    return ret;
}

int main()
{
    while(cin >>n,n)
    {
        string a,b;
        cin >>a >>b;

        vector<int> s(n);
        g.resize(n);

        rep(i,n)
        {
            s[i] = a[i]-'0';
            g[i] = b[i]-'0';
        }

        cout << dfs(s) << endl;
    }
    return 0;
}
