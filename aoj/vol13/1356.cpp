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
    int n;
    cin >>n;
    vector<int> d(n);
    rep(i,n) scanf(" %d", &d[i]);

    int ans=0;
    int lim=1000;
    rep(i,lim+1)
    {
        bool found=false;

        int len=0;
        int t=i;
        while(1)
        {
            ++len;
            t/=10;
            if(t==0) break;
        }

        //start point
        rep(j,n-len+1)
        {
            int val=0;
            rep(k,len) val=val*10+d[j+k];

            if(val==i)
            {
                found=true;
                break;
            }
        }

        if(!found)
        {
            ans=i;
            break;
        }
    }

    printf("%d\n", ans);
    return 0;
}
