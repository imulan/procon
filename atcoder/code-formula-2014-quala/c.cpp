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
    vector<vector<int>> a(n,vector<int>(k));
    rep(i,n)rep(j,k) cin >>a[i][j];

    vector<int> ans[50];
    int invite[1000000]={0};
    int ct=0;
    rep(j,k)
    {
        rep(i,n)
        {
            if(!invite[a[i][j]])
            {
                ans[i].pb(a[i][j]);
                invite[a[i][j]]=1;
                ++ct;

                if(ct==k) break;
            }
        }
        if(ct==k) break;
    }

    //output
    rep(i,n)
    {
        rep(j,ans[i].size())
        {
            if(j) printf(" ");
            printf("%d",ans[i][j]);
        }
        printf("\n");
    }
    return 0;
}
