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

int main()
{
    map<int,int> sci;

    int n;
    cin >>n;
    rep(i,n)
    {
        int a;
        scanf(" %d", &a);

        if(sci.find(a)==sci.end()) sci[a]=1;
        else ++sci[a];
    }

    int m;
    cin >>m;
    vector<int> b(m),c(m);
    rep(i,m) scanf(" %d", &b[i]);
    rep(i,m) scanf(" %d", &c[i]);

    int ans=1;
    int pl=0,st=0;
    rep(i,m)
    {
        int tp=0,ts=0;
        if(sci.find(b[i])!=sci.end()) tp=sci[b[i]];
        if(sci.find(c[i])!=sci.end()) ts=sci[c[i]];

        if(pl<tp || (pl==tp && st<ts))
        {
            ans=i+1;
            pl=tp;
            st=ts;
        }
    }

    printf("%d\n", ans);
    return 0;
}
