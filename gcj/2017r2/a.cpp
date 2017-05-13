#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

int solve()
{
    int n,p;
    cin >>n >>p;

    int ct[4]={};
    rep(i,n)
    {
        int g;
        cin >>g;

        g%=p;
        if(g>0) g = p-g;
        ++ct[g];
    }

    int ret=ct[0];
    if(p==2)
    {
        if(ct[1]>0) ret += (ct[1]-1)/2+1;
    }
    else if(p==3)
    {
        int s=min(ct[1],ct[2]);
        ret+=s;

        ct[1]-=s;
        ct[2]-=s;

        if(ct[1]>0) ret += (ct[1]-1)/3+1;
        if(ct[2]>0) ret += (ct[2]-1)/3+1;
    }
    else
    {
        int s=min(ct[1],ct[3]);
        ret+=s;

        ct[1]-=s;
        ct[3]-=s;

        ret += ct[2]/2;
        ct[2] -= (ct[2]/2)*2;

        int a=max(ct[1],ct[3]);
        if(ct[2]==0)
        {
            if(a>0) ret += (a-1)/4+1;
        }
        else
        {
            ret += (2+a-1)/4+1;
        }
    }

    return ret;
}

int main()
{
    int T;
    cin >>T;
    rep(cases,T)
    {
        printf("Case #%d: %d\n", cases+1, solve());
    }
    return 0;
}
