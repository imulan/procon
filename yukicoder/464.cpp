#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

// [i,j]が回文かどうか
int p[5000][5000]={};
// i文字目から始めるとき、j文字目までにある回文の累積和
int ct[5000][5000]={};

int main()
{
    string s;
    cin >>s;

    int S=s.size();
    rep(i,S) p[i][i]=1;
    rep(i,S-1)if(s[i]==s[i+1]) p[i][i+1]=1;

    for(int b=2; b<S; ++b)
    {
        rep(i,S-b)
        {
            if(s[i]==s[i+b] && p[i+1][i+b-1]) p[i][i+b]=1;
        }
    }

    rep(i,S)
    {
        if(p[i][i]) ct[i][i]=1;
        for(int j=i+1; j<S; ++j)
        {
            ct[i][j] = ct[i][j-1];
            if(p[i][j]) ++ct[i][j];
        }
    }

    ll ans=0;
    rep(i,S-3)for(int j=i+3; j<S; ++j)if(p[0][i] && p[j][S-1])
    {
        // printf("(%d, %d): %d\n", i,j,ct[i+1][j-2]-ct[i+1][i]);
        ans += ct[i+1][j-2]-ct[i+1][i];
    }

    printf("%lld\n", ans);
    return 0;
}
