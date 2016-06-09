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
    int a,b,c;
    while(cin >>a >>b >>c,a|b|c)
    {
        int n;
        cin >>n;

        //部品の種類の総数
        int m=a+b+c;
        //最初はどれも不明
        vector<int> v(m,2);

        vector<int> x(n),y(n),z(n),r(n);
        rep(i,n)
        {
            scanf(" %d %d %d %d",&x[i],&y[i],&z[i],&r[i]);
            --x[i];
            --y[i];
            --z[i];
        }

        //まず正常な動作をした組み合わせは全て正常
        rep(i,n)
        {
            if(r[i]==0) continue;

            v[x[i]]=1;
            v[y[i]]=1;
            v[z[i]]=1;
        }

        //不合格パーツに対して
        rep(t,n)rep(i,n)
        {
            if(r[i]==1) continue;
            //他の2つが正常(1)で確定していれば残りは故障(0)

            if(v[x[i]]==1 && v[y[i]]==1) v[z[i]]=0;
            if(v[y[i]]==1 && v[z[i]]==1) v[x[i]]=0;
            if(v[z[i]]==1 && v[x[i]]==1) v[y[i]]=0;
        }

        //output
        rep(i,m) printf("%d\n",v[i]);
    }
    return 0;
}
