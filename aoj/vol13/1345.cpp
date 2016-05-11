#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define pb push_back
#define fi first
#define se second

const int N=65536;
const int INF=10000000;

int main()
{
    int n,m;
    cin >>n >>m;
    vector<int> b(n),p(m);
    rep(i,n) cin >>b[i];
    rep(i,m) cin >>p[i];

    int start=0;
    rep(i,n) start+=(b[i]<<(n-i-1));

    int g1=0,g2=0;
    int ct=0;
    rep(i,m)
    {
        int b=i%2;
        rep(j,p[i])
        {
            g1+=(b<<(n-ct-1));
            g2+=((!b)<<(n-ct-1));
            ++ct;
        }
    }

    //BFS
    int dist[N];
    fill(dist,dist+N,INF);
    queue<int> que;
    que.push(start);
    dist[start]=0;
    while(!que.empty())
    {
        int v=que.front();
        que.pop();
        rep(i,n-1)
        {
            int t=v;
            int a=(t>>(n-i-1))&1;
            int b=(t>>(n-i-2))&1;

            t-=(a<<(n-i-1))+(b<<(n-i-2));
            t+=(b<<(n-i-1))+(a<<(n-i-2));


            if(dist[t]>dist[v]+1)
            {
                dist[t]=dist[v]+1;
                que.push(t);
            }
        }
    }

    printf("%d\n", min(dist[g1],dist[g2]));
    return 0;
}
