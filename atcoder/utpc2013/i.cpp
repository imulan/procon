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

const int N = 100000;
const ll INF = LLONG_MAX/3;

vector<int> G[N];
vector<int> ew;
void dfs(int v)
{
    ew.pb(v);
    for(int c:G[v]) dfs(c);
    ew.pb(v);
}

int main()
{
    int n;
    scanf(" %d", &n);
    vector<int> a(n);
    rep(i,n) scanf(" %d", &a[i]);

    vector<bool> candidate(n,true);
    rep(i,n-1)
    {
        int s,t;
        scanf(" %d %d", &s, &t);
        G[s].pb(t);
        candidate[t] = false;
    }

    int root = 0;
    rep(i,n)if(candidate[i]) root = i;
    dfs(root);

    vector<ll> val(n,INF);
    set<int> v;

    vector<int> ct(n);
    rep(i,ew.size())
    {
        int id = ew[i];
        if(ct[id]==0)
        {
            auto itr = v.lower_bound(a[id]);
            if(itr!=v.end())
            {
                int x = *itr;
                if(abs(a[id]-x)<abs(a[id]-val[id]) || (abs(a[id]-x)==abs(a[id]-val[id]) && x<val[id])) val[id] = x;
            }
            if(itr!=v.begin())
            {
                --itr;
                int x = *itr;
                if(abs(a[id]-x)<abs(a[id]-val[id]) || (abs(a[id]-x)==abs(a[id]-val[id]) && x<val[id])) val[id] = x;
            }
        }
        else v.insert(a[id]);
        ++ct[id];
    }

    v.clear();
    reverse(all(ew));
    ct = vector<int>(n,0);
    rep(i,ew.size())
    {
        int id = ew[i];
        if(ct[id]==0)
        {
            auto itr = v.lower_bound(a[id]);
            if(itr!=v.end())
            {
                int x = *itr;
                if(abs(a[id]-x)<abs(a[id]-val[id]) || (abs(a[id]-x)==abs(a[id]-val[id]) && x<val[id])) val[id] = x;
            }
            if(itr!=v.begin())
            {
                --itr;
                int x = *itr;
                if(abs(a[id]-x)<abs(a[id]-val[id]) || (abs(a[id]-x)==abs(a[id]-val[id]) && x<val[id])) val[id] = x;
            }
        }
        else v.insert(a[id]);
        ++ct[id];
    }

    rep(i,n) printf("%lld\n", val[i]==INF?-1:val[i]);
    return 0;
}
