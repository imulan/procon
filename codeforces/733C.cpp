#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

typedef pair<int,char> P;

int main()
{
    int n;
    scanf(" %d", &n);
    vector<int> a(n);
    rep(i,n) scanf(" %d", &a[i]);
    int k;
    scanf(" %d", &k);
    vector<int> b(k);
    rep(i,k) scanf(" %d", &b[i]);

    bool valid=true;
    vector<P> ans;

    int l=0;
    int bb=0;
    int eaten=0;
    while(l<n)
    {
        int sum=0;
        int r=l;
        while(r<n && sum+a[r]<=b[bb])
        {
            sum+=a[r];
            ++r;
        }

        if(sum!=b[bb])
        {
            valid=false;
            break;
        }

        if(r-l>1)
        {
            int maxw=0;
            for(int i=l; i<r; ++i) maxw=max(maxw,a[i]);

            int ct=0;
            for(int i=l; i<r; ++i) if(a[i]==maxw) ++ct;

            int king=-1;
            if(ct==1)
            {
                for(int i=l; i<r; ++i) if(a[i]==maxw) king=i;
            }
            else
            {
                if(a[l]==maxw && a[l+1]<a[l]) king=l;
                if(a[r-1]==maxw && a[r-2]<a[r-1]) king=r-1;
                for(int i=l+1; i<r-1; ++i)
                {
                    if(a[i]==maxw)
                    {
                        if(a[i]>a[i-1] || a[i]>a[i+1]) king=i;
                    }
                }
            }

            if(king==-1)
            {
                valid=false;
                break;
            }
            else
            {
                if(king==r-1 || (king!=l && a[king]>a[king-1]))
                {
                    rep(i,king-l)
                    {
                        ans.pb(P(king+1-eaten,'L'));
                        ++eaten;
                    }
                    rep(i,r-1-king) ans.pb(P(king+1-eaten,'R'));
                    eaten+=r-1-king;
                }
                else
                {
                    rep(i,r-1-king) ans.pb(P(king+1-eaten,'R'));
                    rep(i,king-l)
                    {
                        ans.pb(P(king+1-eaten,'L'));
                        ++eaten;
                    }
                    eaten+=r-1-king;
                }
            }
        }

        l=r;
        ++bb;
        if(bb==k) break;
    }

    if(bb!=k || l!=n) valid=false;

    if(!valid) printf("NO\n");
    else
    {
        printf("YES\n");
        rep(i,ans.size()) printf("%d %c\n", ans[i].fi, ans[i].se);
    }
    return 0;
}
