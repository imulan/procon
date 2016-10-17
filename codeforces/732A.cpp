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
    int k,r;
    cin >>k >>r;

    int ans=1;
    while(1)
    {
        if(k*ans-r>=0)
        {
            if((k*ans-r)%10==0) break;
        }

        if(k*ans%10==0) break;

        ans++;
    }

    cout << ans << endl;
    return 0;
}
