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
    int n,k;
    cin >>n >>k;

    //0のやつだけ使える
    int use[10]={0};
    rep(i,k)
    {
        int d;
        cin >>d;
        use[d]=1;
    }

    int ans=n;
    while(1)
    {
        //printf("ans= %d\n", ans);
        bool ok=true;
        int t=ans;
        while(t>0)
        {
            if(use[t%10])
            {
                ok=false;
                break;
            }
            t/=10;
        }

        if(ok) break;
        ++ans;
    }

    cout << ans << endl;
    return 0;
}
