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
        int n;
        scanf(" %d", &n);
        vector<int> p(n);
        rep(i,n) scanf(" %d", &p[i]);

        int sum=0;
        rep(i,n) sum+=p[i];

        vector<string> ans;

        if(sum%2==1)
        {
            int f=0;
            int m=0;
            rep(i,n)
            {
                if(m<p[i])
                {
                    m=p[i];
                    f=i;
                }
            }

            --p[f];
            --sum;

            char c=f+'A';
            string r=" ";
            r[0]=c;
            ans.pb(r);
        }



        while(sum>0)
        {
            string ret="";
            int f=0;
            int m=0;
            rep(i,n)
            {
                if(m<p[i])
                {
                    m=p[i];
                    f=i;
                }
            }
            --p[f];
            --sum;

            char c=f+'A';
            ret=ret+c;

            int s=0;
            m=0;
            rep(i,n)
            {
                if(m<p[i])
                {
                    m=p[i];
                    s=i;
                }
            }
            --p[s];
            --sum;

            c=s+'A';
            ret=ret+c;

            ans.pb(ret);
        }

        printf("Case #%d:",T+1);
        rep(i,ans.size()) cout <<" "<<ans[i];
        printf("\n");
    }
    return 0;
}
