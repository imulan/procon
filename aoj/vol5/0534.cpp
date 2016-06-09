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
    int n;
    while(cin >>n,n)
    {
        vector<int> a(n);
        rep(i,n) scanf(" %d", &a[i]);

        int ans=n;

        //色を変えるボールの位置
        rep(i,n)for(int j=1; j<=3; ++j)
        {
            if(a[i]==j) continue;

            int tmp=n;

            //色を変える
            vector<int> c(a);
            c[i]=j;

            //top,bottom
            int t=i,b=i;
            int st=t,sb=b;

            int col=j;

            //printf("i,j= %d, %d\n",i,j);
            bool first=true;
            while(1)
            {
                while(t>=0 && c[t]==col) --t;
                while(b<n && c[b]==col) ++b;

                //printf(" t=%d, st=%d, sb=%d, b=%d\n", t,st,sb,b);

                int num=(b-sb)+(st-t);
                if(first)
                {
                    num-=1;
                    first=false;
                }
                //printf(" num=%d\n",num);

                if(num>=4)
                {
                    //消える
                    tmp-=num;
                    st=t;
                    sb=b;
                }
                else break;

                if(t==-1 && b==n) break;
                else if(t==-1) col=c[b];
                else if(b==n) col=c[t];
                else
                {
                    if(c[t]==c[b]) col=c[t];
                    else break;
                }
            }

            ans=min(ans,tmp);
        }

        cout << ans << endl;
    }
    return 0;
}
