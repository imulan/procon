#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const int N=100000;
int ct[N]={0};
int num[N+1]={0};

priority_queue<int> que[N];

int main()
{
    int n,m;
    scanf(" %d %d", &n, &m);
    vector<int> x(n);
    rep(i,n) scanf(" %d", &x[i]);
    sort(all(x));

    rep(i,n) ++ct[x[i]%m];
    rep(i,n) ++num[x[i]];

    // まず和がmの倍数のペアを作る
    int ans=0;
    if(ct[0]>=2)
    {
        ans+=ct[0]/2;
        ct[0]%=2;
    }
    if(m%2==0)
    {
        if(ct[m/2]>=2)
        {
            ans+=ct[m/2]/2;
            ct[m/2]%=2;
        }
    }
    for(int i=1; i<=(m-1)/2; ++i)
    {
        int j=m-i;
        int v=min(ct[i],ct[j]);

        ans+=v;
        ct[i]-=v;
        ct[j]-=v;
    }

    // rep(i,m) printf("ct[%d]= %d\n", i,ct[i]);

    // 余ったもので同じ整数のペアが作れるか考える
    for(int i=1; i<=N; ++i)
    {
        if(num[i]==0) continue;
        int rem = i%m;
        que[rem].push(num[i]);
    }


    rep(i,m)
    {
        if(ct[i]==0) continue;

        while(!que[i].empty())
        {
            int val=que[i].top();
            que[i].pop();

            if(val>=2)
            {
                if(ct[i]<=val)
                {
                    ans+=ct[i]/2;
                    ct[i]%=2;
                }
                else
                {
                    ans+=val/2;
                    ct[i]-=(val/2)*2;
                }
            }
        }
    }

    printf("%d\n", ans);
    return 0;
}
