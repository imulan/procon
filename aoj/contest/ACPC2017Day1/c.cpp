#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))

const int R = 10101010;

int main()
{
    int n,k;
    cin >>n >>k;
    vector<int> a(n);
    rep(i,n)
    {
        cin >>a[i];
        --a[i];
    }

    vector<int> x(n,-1);
    for(int i=n-1; i>=0; --i)
    {
        // leaf
        if(x[i]==-1) x[i] = k;

        if(a[i]>=0)
        {
            x[a[i]] = max(x[a[i]],max(0,x[i]-1));
        }
        else x[i]=R;
    }

    // rep(i,n) printf("x[%d] =%d\n", i,x[i]);

    int ans = 0;
    rep(i,n) ans += (x[i]>0);
    cout << ans << endl;
    return 0;
}
