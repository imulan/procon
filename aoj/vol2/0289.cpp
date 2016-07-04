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
    //power of 2
    ll pw[31];
    pw[0]=1;
    for(int i=1; i<31; ++i) pw[i]=pw[i-1]*2;

    int n;
    cin >>n;
    rep(q,n)
    {
        ll s,d;
        cin >>s >>d;

        int ans=0;

        while(s<d)
        {
            int idx=30;
            while(idx>=0)
            {
                if(abs(s)%pw[idx]==0 && s+pw[idx]<=d) break;
                --idx;
            }

            s+=pw[idx];
            ++ans;

            //cout << "s = " <<s<<endl;
        }

        cout << ans << endl;
    }
    return 0;
}
