#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

bool check(vector<int> &x)
{
    int m=x.size();

    bool alternate=true;
    rep(i,m-1) if(x[i]==x[i+1]) alternate=false;

    if(alternate) return x[0]==1;

    for(int i=m/2; i<m-1; ++i)
    {
        if(x[i]==x[i+1]) return x[i]==1;
        int j=m/2-(i-m/2);
        if(x[j]==x[j-1]) return x[j]==1;
    }

    return false;
}

int main()
{
    int n;
    scanf(" %d", &n);
    int m=2*n-1;
    vector<int> a(m);
    rep(i,m) scanf(" %d", &a[i]);

    int l=1, r=m+1;
    while(r-l>1)
    {
        int mid=(l+r)/2;
        vector<int> t(m,0);
        rep(i,m) if(a[i]>=mid) t[i]=1;
        if(check(t)) l=mid;
        else r=mid;
    }
    printf("%d\n", l);
    return 0;
}
