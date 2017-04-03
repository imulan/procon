#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

typedef pair<int,int> pi;

int solve()
{
    int n,m;
    scanf(" %d %d", &n, &m);
    vector<int> x(n),y(n);
    rep(i,n) scanf(" %d %d", &x[i], &y[i]);

    int ret=0;
    if(n<=m)
    {
        rep(i,n) ret+=x[i];
        return ret;
    }

    if(m==1)
    {
        int sumy=0;
        rep(i,n)
        {
            ret = max(ret, sumy+x[i]);
            sumy+=y[i];
        }
        return ret;
    }

    priority_queue<int,vector<int>,greater<int>> pq;
    int t=0;
    rep(i,m-1)
    {
        pq.push(x[i]-y[i]);
        t+=x[i];
    }

    for(int i=m-1; i<n; ++i)
    {
        ret = max(ret,t+x[i]);

        int v = pq.top();
        pq.pop();
        int d = x[i]-y[i];
        if(v<d)
        {
            t-=v;
            t+=x[i];
            pq.push(d);
        }
        else
        {
            t+=y[i];
            pq.push(v);
        }
    }

    return ret;
}

int main()
{
    cout << solve() << endl;
    return 0;
}
