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
        int J,P,S,K;
        cin >>J >>P >>S >>K;

        if(S<=K)
        {
            printf("Case #%d: %d\n", t+1, J*P*S);
            rep(i,J)rep(j,P)rep(k,S) printf("%d %d %d\n", i+1, j+1, k+1);
        }
        else
        {
            int ans=J*P*K;
            printf("Case #%d: %d\n", t+1, ans);
            rep(i,J)rep(j,P)rep(k,K) printf("%d %d %d\n", i+1, j+1, (i+j+k)%S+1);
        }
    }
    return 0;
}
