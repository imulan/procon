#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

typedef pair<ll,ll> pl;
typedef pair<int,int> pi;

int main()
{
    int n;
    scanf(" %d", &n);

    priority_queue<pi> qa,qb;
    rep(i,n)
    {
        int a;
        scanf(" %d", &a);
        qa.push(pi(a,i));
    }
    rep(i,n)
    {
        int b;
        scanf(" %d", &b);
        qb.push(pi(-b,i));
    }

    vector<int> ans;
    vector<bool> used(n,false);
    rep(i,n-1)
    {
        pi p;
        if(i%2)
        {
            while(1)
            {
                p = qb.top();
                qb.pop();
                if(!used[p.se])
                {
                    used[p.se] = true;
                    break;
                }
            }
        }
        else
        {
            while(1)
            {
                p = qa.top();
                qa.pop();
                if(!used[p.se])
                {
                    used[p.se] = true;
                    ans.pb(p.se);
                    break;
                }
            }
        }
    }

    // last one
    rep(i,n)if(!used[i]) ans.pb(i);

    // output
    sort(all(ans));
    printf("%d\n", n/2+1);
    rep(i,ans.size())
    {
        if(i) printf(" ");
        printf("%d", ans[i]+1);
    }
    printf("\n");
    return 0;
}
