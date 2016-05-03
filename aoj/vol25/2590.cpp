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

typedef pair<string,string> ps;

int main()
{
    while(1)
    {
        int n,m,q;
        cin >>n >>m >>q;
        if(n==0) break;

        //now active switch
        int act[36]={0};
        //i-th bulb may be controled by j-th switch
        bool sw[1000][36];

        fill(sw[0],sw[1000],true);

        rep(Q,q)
        {
            string s,b;
            cin >>s >>b;

            //update active state
            rep(i,n)
            {
                if(s[i]=='1') act[i] = !act[i];
            }

            rep(i,m)
            {
                if(b[i]=='0')
                {
                    //not active
                    //now active switches have nothing to do with
                    rep(j,n)
                    {
                        if(act[j]) sw[i][j]=false;
                    }
                }
                else
                {
                    //active
                    //now inactive switches have nothing to do with
                    rep(j,n)
                    {
                        if(!act[j]) sw[i][j]=false;
                    }
                }
            }
        }

        //answer
        rep(i,m)
        {
            int ans=-1;
            int ct=0;

            rep(j,n)
            {
                if(sw[i][j])
                {
                    ans=j;
                    ++ct;
                }
            }

            if(ct==1)
            {
                if(ans<10) printf("%d",ans);
                else printf("%c",ans-10+'A');
            }
            else printf("?");
        }
        printf("\n");
    }
    return 0;
}
