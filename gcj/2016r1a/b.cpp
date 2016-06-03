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
    int T;
    cin >>T;
    rep(t,T)
    {
        int n;
        cin >>n;

        int ct[2501]={0};
        rep(i,2*n-1)rep(j,n)
        {
            int a;
            cin >>a;
            ++ct[a];
        }

        vector<int> ans;
        rep(i,2501)
        {
            if(ct[i]%2==1) ans.pb(i);
        }

        printf("Case #%d:",t+1);
        for(const auto& x:ans) printf(" %d",x);
        printf("\n");
    }
    return 0;
}
