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

//座標(x,y)に合計で入るダメージ
ll dm[1002][1002]={0};

int main()
{
    int n,k;
    cin >>n >>k;

    vector<int> x(n),y(n),hp(n);
    rep(i,n)
    {
        scanf(" %d %d %d", &x[i], &y[i], &hp[i]);
        //すべて第１象限で考えるために平行移動
        x[i]+=500;
        y[i]+=500;
    }

    rep(i,k)
    {
        int ax,ay,w,h,d;
        scanf(" %d %d %d %d %d", &ax, &ay, &w, &h, &d);
        //平行移動
        ax+=500;
        ay+=500;

        int rx=min(1000,ax+w);
        int ry=min(1000,ay+h);

        dm[ax][ay]+=d;
        dm[rx+1][ay]-=d;
        dm[ax][ry+1]-=d;
        dm[rx+1][ry+1]+=d;
    }

    //x方向に足し合わせる
    rep(i,1002)
    {
        for(int j=1; j<1002; ++j) dm[j][i]+=dm[j-1][i];
    }
    //y方向に足し合わせる
    rep(i,1002)
    {
        for(int j=1; j<1002; ++j) dm[i][j]+=dm[i][j-1];
    }

    ll ans=0;
    rep(i,n)
    {
        ll rem=hp[i]-dm[x[i]][y[i]];
        if(rem>0) ans+=rem;
    }
    cout << ans << endl;
    return 0;
}
