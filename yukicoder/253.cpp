#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

int ct=0;
// int now=934751779;

int ask(int Y)
{
    ++ct;
    cout << "? " << Y << endl;
    // printf("= %d\n", now);
    // --now;
    int res;
    cin >>res;
    return res;
}

int main()
{
    int ans=-1;
    int res=ask(10);
    if(res==0)
    {
        printf("! 10\n");
        return 0;
    }

    res=ask(90);
    if(res==0) ans=90;
    else if(res==-1)
    {
        while(res!=0) res=ask(9);
        ans=9+ct-1;
    }
    else
    {
        int l=90, r=1000000000;
        while(r-l>1)
        {
            // printf("l= %d, r= %d\n", l,r);
            int m=(l+r)/2;
            res=ask(m);
            if(res==0)
            {
                ans=m+ct-1;
                break;
            }
            else if(res==-1)
            {
                --l;
                r=m;
            }
            else
            {
                --r;
                l=m-1;
            }
        }

        if(ans==-1) ans=l+ct-1;
    }

    cout << "! " << ans << endl;
    return 0;
}
