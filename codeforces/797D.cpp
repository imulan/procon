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

const int N = 100000;

int n;
int v[N],l[N],r[N];
int par[N];

set<int> found;
void dfs(int now, int p, int q)
{
    // printf(" %d(v= %d) %d %d\n", now, v[now],p, q);
    if(p<=v[now] && v[now]<=q) found.insert(v[now]);
    if(l[now]>=0) dfs(l[now], p, min(q,v[now]-1));
    if(r[now]>=0) dfs(r[now], max(p,v[now]+1), q);
}

int main()
{
    fill(par,par+N,-1);

    scanf(" %d", &n);
    rep(i,n)
    {
        scanf(" %d %d %d", &v[i], &l[i], &r[i]);
        --l[i];
        --r[i];

        if(l[i]>=0) par[l[i]] = i;
        if(r[i]>=0) par[r[i]] = i;
    }

    int root = 0;
    rep(i,n)if(par[i]==-1) root=i;

    dfs(root,0,1145141919);

    int ans = n;
    rep(i,n)if(found.count(v[i])) --ans;
    printf("%d\n", ans);
    return 0;
}
