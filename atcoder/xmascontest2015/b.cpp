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


int main()
{
    int n,m;
    scanf(" %d %d", &n, &m);

    set<pi> broken;
    rep(i,m)
    {
        int p,q;
        scanf(" %d %d", &p, &q);
        --p;
        --q;

        if(p>q) swap(p,q);
        broken.insert(pi(p,q));
    }

    set<int> unvis;
    for(int i=1; i<n; ++i) unvis.insert(i);

    vector<pi> e;

    queue<int> que;
    que.push(0);
    while(!que.empty())
    {
        int v=que.front();
        que.pop();

        vector<int> er;

        for(const auto& x:unvis)
        {
            pi a(v,x);
            if(v>x) a=pi(x,v);

            if(broken.find(a) == broken.end())
            {
                er.pb(x);
                que.push(x);
                e.pb(a);
            }
        }

        rep(i,er.size()) unvis.erase(er[i]);
    }

    if(e.size()==n-1)
    {
        printf("Yes\n");
        rep(i,e.size()) printf("%d %d\n", e[i].fi+1, e[i].se+1);
    }
    else printf("No\n");
    return 0;
}
