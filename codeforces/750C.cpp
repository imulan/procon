#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

int main()
{
    int n;
    scanf(" %d", &n);

    vector<int> c(n),d(n);
    rep(i,n) scanf(" %d %d", &c[i], &d[i]);

    bool allDiv1=true;
    rep(i,n) if(d[i]==2) allDiv1=false;
    if(allDiv1)
    {
        printf("Infinity\n");
        return 0;
    }

    bool allDiv2=true;
    rep(i,n) if(d[i]==1) allDiv2=false;
    if(allDiv2)
    {
        vector<int> ch(n+1,0);
        rep(i,n) ch[i+1] = ch[i]+c[i];

        int M=0;
        rep(i,n) M=max(M,ch[i]);

        printf("%d\n", 1899-(M-ch[n]));
        return 0;
    }

    bool found=false;
    int ans=-123456789;

    int idx=-1;
    rep(i,n-1)
    {
        if(d[i]!=d[i+1])
        {
            idx=i;
            break;
        }
    }

    vector<int> candidate;
    if(d[idx]==1)
    {
        for(int i=1900; i<1900-c[idx]; ++i) candidate.pb(i);
    }
    else
    {
        for(int i=1900-c[idx]; i<1900; ++i) candidate.pb(i);
    }

    rep(c_idx,candidate.size())
    {
        int t=candidate[c_idx];
        bool valid=true;

        int now=t;
        for(int i=idx-1; i>=0; --i)
        {
            now-=c[i];
            if(d[i]==1)
            {
                if(now<1900) valid=false;
            }
            else
            {
                if(now>=1900) valid=false;
            }

            if(!valid) break;
        }

        if(valid)
        {
            now=t;
            for(int i=idx; i<n; ++i)
            {
                if(d[i]==1)
                {
                    if(now<1900) valid=false;
                }
                else
                {
                    if(now>=1900) valid=false;
                }

                if(!valid) break;

                now+=c[i];
            }
        }

        if(valid)
        {
            int last=t;
            for(int i=idx; i<n; ++i) last+=c[i];

            found=true;
            ans = max(ans,last);
        }
    }

    if(!found) printf("Impossible\n");
    else printf("%d\n", ans);
    return 0;
}
