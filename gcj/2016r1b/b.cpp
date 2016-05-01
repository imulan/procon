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

inline int ab(int x)
{
    return (x>0)?x:-x;
}

int main()
{
    int times;
    cin >>times;
    rep(T,times)
    {
        string a,b;
        cin >>a >>b;

        int pw[4];
        pw[0]=1;
        for(int i=1; i<=3; ++i) pw[i]=pw[i-1]*10;

        int n=a.size();

        string ax,ay;
        int dif=10000;
        int m=10000;

        rep(i,pw[n])
        {
            string x="";
            int t=i;
            rep(k,n)
            {
                char f=t%10+'0';
                x=f+x;
                t/=10;
            }

            bool valid=true;
            rep(k,n)
            {
                if(a[k]!='?' && a[k]!=x[k]) valid=false;
            }

            if(!valid) continue;

            rep(j,pw[n])
            {
                string y="";
                t=j;
                rep(k,n)
                {
                    char f=t%10+'0';
                    y=f+y;
                    t/=10;
                }

                valid=true;
                rep(k,n)
                {
                    if(b[k]!='?' && b[k]!=y[k]) valid=false;
                }

                if(!valid) continue;

                if(ab(i-j)<dif || (ab(i-j)==dif && i<m))
                {
                    dif=ab(i-j);
                    m=i;
                    ax=x;
                    ay=y;
                }
            }
        }

        printf("Case #%d: ",T+1);
        cout<<ax<<" "<<ay<<endl;
    }
    return 0;
}
