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

const int N = 100000, INF = 19191919;
vector<int> G[N];

int farthest(int n, int root, int &v)
{
    vector<int> d(n,INF);
    queue<int> que;

    que.push(root);
    d[root] = 0;
    while(!que.empty())
    {
        int now = que.front();
        que.pop();
        for(const auto &e:G[now])
        {
            if(d[e] > d[now]+1)
            {
                d[e] = d[now]+1;
                que.push(e);
            }
        }
    }

    int md = 0;
    rep(i,n)
    {
        assert(d[i]<INF);
        if(md<d[i])
        {
            md = d[i];
            v = i;
        }
    }
    return md;
}

int main()
{
    int n,m;
    scanf(" %d %d", &n, &m);

    rep(i,m)
    {
        int a,b;
        scanf(" %d %d", &a, &b);
        --a;
        --b;
        G[a].pb(b);
        G[b].pb(a);
    }

    int u,v;
    int d = farthest(n, 0, u);
    d = farthest(n, u, v);
    printf("%d\n", d);
    return 0;
}
