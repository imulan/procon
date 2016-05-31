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
        int N,J;
        cin >>N >>J;

        printf("Case #%d:\n", t+1);

        N/=2;

        ll pw[11];
        rep(i,11) pw[i]=1;
        for(ll i=1; i<=10; ++i)
        {
            rep(j,N) pw[i]*=i;
            pw[i]+=1;
        }

        //順番に文字列をJ個生成
        rep(i,J)
        {
            string s="1";
            rep(j,N-2)
            {
                if(i>>j&1) s+="1";
                else s+="0";
            }
            s+="1";

            cout << s+s;
            for(int j=2; j<=10; ++j)
                cout << " " << pw[j];
            cout << endl;
        }
    }
    return 0;
}
