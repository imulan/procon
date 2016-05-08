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
    int t;
    cin >>t;
    rep(T,t)
    {
        int b;
        ll m;
        cin >>b >>m;

        int ans[50][50]={0};

        rep(i,b-1)for(int j=i+1; j<b-1; ++j) ans[i][j]=1;

        ll pw[50];
        pw[0]=1;
        rep(i,50-1) pw[i+1]=pw[i]*2;

        for(int i=b-2; i>0; --i)
        {
            ll sub=pw[i-1];
            if(m-sub>=0)
            {
                ans[i][b-1]=1;
                m-=sub;
            }
        }

        if(m==1){
            ans[0][b-1]=1;
            --m;
        }

        bool valid=(m==0);


        printf("Case #%d: ",T+1);
        if(valid)
        {
            cout << "POSSIBLE" << endl;
            rep(i,b)
            {
                rep(j,b) printf("%d", ans[i][j]);
                printf("\n");
            }
        }
        else cout << "IMPOSSIBLE" << endl;

    }
    return 0;
}
