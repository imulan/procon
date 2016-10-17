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

vector<int> days[100000];

int main()
{
    int n,m;
    scanf(" %d %d", &n, &m);

    rep(i,n)
    {
        int d;
        scanf(" %d", &d);
        --d;
        if(d>=0) days[d].pb(i+1);
    }

    ll for_prepare=0;
    vector<int> a(m);
    rep(i,m)
    {
        scanf(" %d", &a[i]);
        for_prepare+=a[i];
    }

    bool no_test=false;
    rep(i,m)
    {
        if(days[i].size()==0) no_test=true;
    }

    if(no_test || for_prepare>n)
    {
        printf("-1\n");
        return 0;
    }


    int l=0, r=n+1;
    while(r-l>1)
    {
        bool valid=true;
        int mid=(l+r)/2;

        vector<int> last_day(m);
        rep(i,m)
        {
            if(days[i][0]>mid)
            {
                valid=false;
                break;
            }

            int idx=upper_bound(all(days[i]),mid)-days[i].begin()-1;
            last_day[i]=days[i][idx];
        }

        if(valid)
        {
            vector<pi> p(m);
            rep(i,m) p[i]=pi(last_day[i],i);
            sort(all(p));

            // printf(" mid= %d\n", mid);
            // rep(i,m) printf("id: %d, last_day: %d\n", p[i].se, p[i].fi);

            vector<int> ta(m);
            rep(i,m) ta[i]=a[p[i].se];

            int study=0;
            int test=0;
            for(int i=1; i<=mid; ++i)
            {
                if(p[test].fi == i)
                {
                    // テストを受ける
                    if(ta[test]>0)
                    {
                        valid=false;
                        break;
                    }
                    else ++test;
                }
                else
                {
                    // 勉強する
                    if(study<m)
                    {
                        --ta[study];
                        if(ta[study]==0) ++study;
                    }
                }
            }
        }

        if(valid) r=mid;
        else l=mid;
    }

    if(r==n+1) printf("-1\n");
    else printf("%d\n", r);
    return 0;
}
