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

bool check(const vector<int> &g, const vector<int> &h)
{
    rep(i,h.size()) if(g[h[i]]!=i) return false;
    return true;
}

int main()
{
    int n;
    scanf(" %d", &n);
    vector<int> f(n);
    rep(i,n)
    {
        scanf(" %d", &f[i]);
        --f[i];
    }

    int m = 0;
    map<int,int> M;
    rep(i,n)
    {
        if(!M.count(f[i])) M[f[i]] = m++;
    }

    vector<int> g(n),h(m);
    rep(i,n) g[i] = M[f[i]];
    for(const auto &p:M) h[p.se] = p.fi;

    if(check(g,h))
    {
        printf("%d\n", m);
        rep(i,n) printf("%d%c", g[i]+1, (i==n-1)?'\n':' ');
        rep(i,m) printf("%d%c", h[i]+1, (i==m-1)?'\n':' ');
    }
    else printf("-1\n");
    return 0;
}
