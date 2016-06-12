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

//x座標に対して直線がある位置
//(y座標,窓0/カーテン1)
vector<pi> y[40001];

int main()
{
    int n;
    while(cin >>n,n)
    {
        rep(i,40001) y[i].clear();

        //window,curtain
        //(x,y)
        vector<pi> w(n),c(4);
        rep(i,n) scanf(" %d %d", &w[i].fi, &w[i].se);
        rep(i,4) scanf(" %d %d", &c[i].fi, &c[i].se);

        //第1象限だけで考えるために平行移動
        //printf("window\n");
        rep(i,n)
        {
            w[i].fi+=20000;
            w[i].se+=20000;

            //printf("%d,%d\n", w[i].fi,w[i].se);
        }
        //printf("curtain\n");
        rep(i,4)
        {
            c[i].fi+=20000;
            c[i].se+=20000;

            //printf("%d,%d\n", c[i].fi,c[i].se);
        }

        //w[i]とw[i+1]がなす直線が横なら追加
        rep(i,n)
        {
            //y座標が一致するなら
            if(w[i].se==w[(i+1)%n].se)
            {
                int Y=w[i].se;
                int lx=min(w[i].fi,w[(i+1)%n].fi);
                int rx=max(w[i].fi,w[(i+1)%n].fi);

                for(int j=lx; j<rx; ++j) y[j].pb(pi(Y,0));
            }
        }

        //c[i]とc[i+1]がなす直線が横なら追加
        rep(i,4)
        {
            //y座標が一致するなら
            if(c[i].se==c[(i+1)%4].se)
            {
                int Y=c[i].se;
                int lx=min(c[i].fi,c[(i+1)%4].fi);
                int rx=max(c[i].fi,c[(i+1)%4].fi);

                //printf(" %d-%d \n",lx,rx-1);

                for(int j=lx; j<rx; ++j) y[j].pb(pi(Y,1));
            }
        }

        //各x座標での切り口に対してy座標が大きい順にソート
        rep(i,40001)
        {
            rep(j,y[i].size()) y[i][j].fi = -y[i][j].fi;
            sort(all(y[i]));
            rep(j,y[i].size()) y[i][j].fi = -y[i][j].fi;
        }

        ll ans=0;

        //各x座標iに対して
        rep(i,40001)
        {
            //窓の直線を横切った回数
            int W=0;
            //カーテンの直線を横切った回数
            int C=0;

            ll add=0;
            int tmp=0;
            for(const auto &x:y[i])
            {
                //今注目している線が窓なら
                if(x.se==0)
                {
                    if(W%2==0) tmp=x.fi;
                    else
                    {
                        //もしカーテンの中ならその直線は考慮しない
                        if(C!=1) add+=tmp-x.fi;
                    }

                    ++W;
                }
                else
                {
                    //カーテンに入って行く時
                    if(C==0)
                    {
                        //今までに窓を観た個数が奇数ならそことの差を足す
                        if(W%2==1) add+=tmp-x.fi;
                    }
                    else
                    {
                        //今までに窓観た個数が奇数ならtmpを更新
                        if(W%2==1) tmp=x.fi;
                    }

                    ++C;
                }
            }

            ans+=add;
            //printf("i=%d, add= %d\n", i,add);
        }

        cout << ans << endl;

    }
    return 0;
}
