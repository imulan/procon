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

#define dbg(x) cout<<#x"="<<x<<endl
#define rep1(i,n) for(int (i)=1;(i)<=(int)(n);++(i))

int main()
{
    int n;
    while(cin >>n,n)
    {
        vector<char> c(n);
        rep(i,n) cin >>c[i];

        int ct[26]={0};
        rep(i,n) ++ct[c[i]-'A'];

        int large=0;
        rep(i,26) large=max(large,ct[i]);
        int num=0;
        rep(i,26) if(large==ct[i]) ++num;

        if(num>1)
        {
            printf("TIE\n");
            continue;
        }

        memset(ct,0,sizeof(ct));

        char ans;
        int ansnum;

        rep(i,n)
        {
            char can;

            ++ct[c[i]-'A'];

            //FIRST
            int F=0;
            rep(j,26) F=max(F,ct[j]);

            int Fnum=0;
            rep(j,26) if(F==ct[j]) ++Fnum;

            //複数人いたらダメ
            if(Fnum==1)
            {
                rep(j,26) if(F==ct[j]) can=j+'A';
            }
            else continue;

            //SECOND
            int S=0;
            rep(j,26)
            {
                if(ct[j]<F)
                {
                    S=max(S,ct[j]);
                }
            }

            int rem=n-1-i;

            /*
            printf("i=%d\n", i);
            printf("F,S %d,%d\n", F,S);
            printf("rem %d\n", rem);
            */
            
            if(F>S+rem)
            {
                ans=can;
                ansnum=i+1;
                break;
            }
        }

        printf("%c %d\n",ans,ansnum);
    }
    return 0;
}
