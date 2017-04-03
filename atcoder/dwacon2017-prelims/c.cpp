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
    vector<int> a(n);
    rep(i,n) scanf(" %d", &a[i]);

    vector<int> idx[5];
    rep(i,n) idx[a[i]].pb(i);
    int nx[5]={};

    int ans=0;
    vector<bool> r(n,false);
    rep(i,n)
    {
        if(r[i]) continue;

        ++ans;
        r[i]=true;
        ++nx[a[i]];
        int s=a[i];

        int j=3;
        while(j>=1)
        {
            if(s+j>4 || nx[j]==idx[j].size())
            {
                --j;
                continue;
            }

            s+=j;
            r[idx[j][nx[j]++]]=true;
        }
    }

    printf("%d\n", ans);
    return 0;
}
