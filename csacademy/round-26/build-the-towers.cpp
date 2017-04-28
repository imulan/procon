#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

using pi = pair<int,int>;

void solve()
{
    int n;
    scanf(" %d", &n);
    vector<int> a(n);
    rep(i,n) scanf(" %d", &a[i]);

    bool adj=false;
    rep(i,n-1)if(a[i]>0 && a[i+1]>0) adj |= (a[i]==a[i+1]);
    if(adj || a[0]==3 || a[n-1]==3)
    {
        printf("-1\n");
        return;
    }

    vector<int> IDX[4];
    rep(i,n) IDX[a[i]].pb(i);

    vector<int> ans;
    vector<int> va(n,1);

    bool valid=true;

    #define IN(x) (0<=x && x<n)
    for(int v=3; v>0; --v)
    {
        for(const auto &idx:v[IDX])
        {
            int ct=0;
            if(IN(idx-1)) ct+=va[idx-1];
            if(IN(idx+1)) ct+=va[idx+1];

            if(v-ct<=1)
            {
                if(v==1)
                {
                    ans.pb(idx);
                }
                else if(v==2)
                {
                    if(IN(idx-1) && va[idx-1]) ans.pb(idx-1);
                    else if(IN(idx+1) && va[idx+1]) ans.pb(idx+1);

                    ans.pb(idx);
                }
                else
                {
                    ans.pb(idx);
                    ans.pb(idx-1);
                    ans.pb(idx+1);
                    ans.pb(idx);
                }
            }
            else
            {
                valid=false;
                break;
            }

            va[idx]=0;
        }
        if(!valid) break;
    }

    // output
    if(!valid)
    {
        printf("-1\n");
        return;
    }

    printf("%d\n", ans.size());
    rep(i,ans.size())
    {
        if(i) printf(" ");
        printf("%d", ans[i]+1);
    }
    printf("\n");
}

int main()
{
    solve();
    return 0;
}
