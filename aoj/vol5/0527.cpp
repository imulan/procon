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

typedef pair<int,int> pi;

int main()
{
    int n;
    while(cin >>n,n)
    {
        vector<int> a(n);
        rep(i,n) scanf(" %d", &a[i]);

        //場がどうなっているか(b1/w0,個数)と圧縮して持つ
        vector<pi> f;
        f.pb(pi(a[0],1));
        for(int i=1; i<n; ++i)
        {
            int s=f.size();
            if(i%2==1)
            {
                //同じ色なら何も起きない
                if(f[s-1].fi==a[i]) ++f[s-1].se;
                else
                {
                    if(s==1)
                    {
                        f[s-1].fi=a[i];
                        ++f[s-1].se;
                    }
                    else
                    {//s>=2
                        //個数を保存
                        int num=f[s-1].se;
                        //この区間は取り込まれてなくなる
                        f.erase(f.begin()+s-1);
                        //取り込まれる区間と新しく置かれる石の分
                        f[s-2].se+=num+1;
                    }
                }
            }
            else
            {
                if(f[s-1].fi==a[i]) ++f[s-1].se;
                else f.pb(pi(a[i],1));
            }
        }

        //output
        int ans=0;
        rep(i,f.size()) if(f[i].fi==0) ans+=f[i].se;
        cout << ans << endl;
    }
    return 0;
}
