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

const int N=100000;
const int INF=123456789;

// (to,id)
vector<pi> G[N];
int a[N],b[N];
bool used[N]={};
int d[N];

int main()
{
    int n;
    scanf(" %d", &n);
    rep(i,n)
    {
        scanf(" %d %d", &a[i], &b[i]);
        --a[i];
        --b[i];
        G[a[i]].pb(pi(b[i],i));
        G[b[i]].pb(pi(a[i],i));
    }

    fill(d,d+N,INF);
    d[0]=0;
    queue<int> que;
    que.push(0);
    while(!que.empty())
    {
        int v = que.front();
        que.pop();
        for(const auto &p:G[v])
        {
            int to = p.fi, id = p.se;
            if(d[to]>d[v]+1)
            {
                d[to]=d[v]+1;
                que.push(to);
                used[id]=true;
            }
        }
    }

    int MAX = n-1;
    rep(i,n)if(!used[i]) MAX += (d[a[i]]!=d[b[i]]);

    int MIN=2;
    rep(i,n)if(G[i].size()==1) MIN=1;

    printf("%d %d\n", MIN,MAX);
    return 0;
}
