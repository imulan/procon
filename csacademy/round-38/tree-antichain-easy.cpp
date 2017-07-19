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

void solve()
{
    int n;
    scanf(" %d", &n);

    vector<vector<int>> G(n);

    rep(i,n-1)
    {
        int x,y;
        scanf(" %d %d", &x, &y);
        --x;
        --y;
        G[x].pb(y);
        G[y].pb(x);
    }

    int c = 0;
    int r = -1;
    rep(i,n)
    {
        if(c<G[i].size())
        {
            c = G[i].size();
            r = i;
        }
    }

    if(c==n-1)
    {
        printf("-1\n");
        return;
    }

    vector<int> d(n,2*n);
    d[r] = 0;
    queue<int> que;
    que.push(r);
    while(!que.empty())
    {
        int v = que.front(); que.pop();
        for(const auto &nx:G[v])
        {
            if(d[nx]>d[v]+1)
            {
                d[nx]=d[v]+1;
                que.push(nx);
            }
        }
    }

    vector<int> ans;
    set<int> o;
    ans.pb(r);
    rep(i,n)if(i!=r)
    {
        if(d[i]%2==0) ans.pb(i);
        else o.insert(i);
    }

    int ee = ans[ans.size()-1];
    for(const auto &x:G[ee])
    {
        o.erase(x);
    }

    int to = *o.begin();
    ans.pb(to);

    rep(i,n)if(i!=r)
    {
        if(d[i]%2==1 && i!=to) ans.pb(i);
    }

    assert(ans.size()==n);
    rep(i,n) printf("%d%c", ans[i]+1, (i==n-1?'\n':' '));
}

int main()
{
    int CASES;
    scanf(" %d", &CASES);
    while(CASES--) solve();
    return 0;
}
