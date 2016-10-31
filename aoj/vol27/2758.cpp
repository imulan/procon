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
    int k;
    cin >>k;
    vector<string> I(k), N(k);
    rep(i,k) cin >>I[i];
    rep(i,k) cin >>N[i];

    int res=-1;
    int pi=0, pn=0;
    rep(i,k)
    {
        // printf("Power: I.%d N.%d\n", pi,pn);

        int ai,an;
        if(I[i][0]=='m') ai=0;
        else if(I[i][0]=='t') ai=1;
        else if(I[i][0]=='k') ai=2;
        if(N[i][0]=='m') an=0;
        else if(N[i][0]=='t') an=1;
        else if(N[i][0]=='k') an=2;

        bool zero_i=false, zero_n=false;

        // printf("ai:%d, an:%d\n", ai,an);

        if(ai==0)
        {
            if(an==2 && pn==5)
            {
                res=1;
                break;
            }
        }
        else if(ai==1)
        {
            pi=min(pi+1,5);
            if(an==2 && pn>0)
            {
                res=1;
                break;
            }
        }
        else
        {
            if(an==2 && pi<pn)
            {
                res=1;
                break;
            }

            if(pi==0) zero_i=true;
        }

        if(an==0)
        {
            if(ai==2 && pi==5)
            {
                res=0;
                break;
            }
        }
        else if(an==1)
        {
            pn=min(pn+1,5);
            if(ai==2 && pi>0)
            {
                res=0;
                break;
            }
        }
        else
        {
            if(ai==2 && pn<pi)
            {
                res=0;
                break;
            }

            if(pn==0) zero_n=true;
        }

        if(zero_n || zero_i)
        {
            if(zero_n && zero_i) continue;
            if(zero_n) res=0;
            if(zero_i) res=1;
        }

        if(res!=-1) break;

        if(ai==2) pi=0;
        if(an==2) pn=0;
    }

    string ans="Hikiwake";
    if(res==0) ans="Isono";
    else if(res==1) ans="Nakajima";
    cout << ans+"-kun" << endl;
    return 0;
}
