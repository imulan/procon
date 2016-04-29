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
    bool first=true;
    while(1)
    {
        //input
        int m;
        cin >>m;
        if(m==0) break;

        int x[4];
        rep(i,4) cin >>x[i];

        int sum=100;
        int u[4]={500,100,50,10};
        int ans[4]={0};

        rep(a,x[0]+1)rep(b,x[1]+1)rep(c,x[2]+1)rep(d,x[3]+1)
        {
            //printf("%d,%d,%d,%d\n",a,b,c,d);
            int p=a*10+b*50+c*100+d*500-m;
            if(p<0) continue;

            int t[4]={0};
            int u[4]={500,100,50,10};
            rep(i,4)
            {
                int ct=0;
                while(p-u[i]>=0)
                {
                    ++ct;
                    p-=u[i];
                }
                t[i]=ct;
            }

            int tsum=0;
            tsum+=t[0]+x[0]-a;
            tsum+=t[1]+x[1]-b;
            tsum+=t[2]+x[2]-c;
            tsum+=t[3]+x[3]-d;

            if(tsum<sum)
            {
                sum=tsum;
                ans[0]=d;
                ans[1]=c;
                ans[2]=b;
                ans[3]=a;
            }

        }

        if(!first) printf("\n");
        for(int i=3; i>=0; --i)
        {
            if(ans[i]>0) printf("%d %d\n",u[i],ans[i]);
        }
        first=false;
    }
    return 0;
}
