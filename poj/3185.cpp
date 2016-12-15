#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cassert>
#include <vector>
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
    vector<int> a(29);
    rep(i,20) scanf(" %d", &a[i]);

    int ans=1234;

    rep(head,2)
    {
        int tmp=0;
        vector<int> b(a);

        if(head)
        {
            ++tmp;
            b[0] = !b[0];
            b[1] = !b[1];
        }

        for(int i=1; i<=18; ++i)if(b[i-1])
        {
            ++tmp;
            for(int j=-1; j<=1; ++j) b[i+j] = !b[i+j];
        }

        if(b[19])
        {
            ++tmp;
            b[18] = !b[18];
            b[19] = !b[19];
        }

        bool zero=true;
        rep(i,20)if(b[i]) zero=false;

        if(zero) ans = min(ans,tmp);
    }

    printf("%d\n", ans);
    return 0;
}
