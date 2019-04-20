#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()

const int N=101010;
int p[N] = {};

int main()
{
    int n,h,w;
    cin >>n >>h >>w;

    rep(i,n)
    {
        int x;
        cin >>x;

        int l = i*w, r = (i+1)*w;
        if(i%2==0)
        {
            l+=x;
            r+=x;
        }
        else
        {
            l-=x;
            r-=x;
        }

        ++p[l];
        --p[r];
    }

    rep(i,N-1) p[i+1]+=p[i];

    int ans = 0;
    rep(i,n*w) ans += (p[i]==0);
    ans *= h;

    cout << ans << endl;
    return 0;
}
