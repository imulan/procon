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
    cin >>n;
    rep(q,n)
    {
        int r,t;
        cin >>r >>t;

        vector<int> ans;

        if(r%100==0)
        {
            if(t%30==0)
            {
                //計測点上
                ans.pb((t/30)*5 + r/100);
            }
            else
            {
                //円弧の上
                ans.pb((t/30)*5 + r/100);
                ans.pb((t/30+1)*5 + r/100);
            }
        }
        else
        {
            if(t%30==0)
            {
                //線分の上
                ans.pb((t/30)*5 + r/100);
                ans.pb((t/30)*5 + r/100+1);
            }
            else
            {
                //区画の内側
                ans.pb((t/30)*5 + r/100);
                ans.pb((t/30)*5 + r/100+1);
                ans.pb((t/30+1)*5 + r/100);
                ans.pb((t/30+1)*5 + r/100+1);
            }
        }


        rep(i,ans.size())
        {
            if(i) printf(" ");
            printf("%d", ans[i]);
        }
        printf("\n");
    }
    return 0;
}
