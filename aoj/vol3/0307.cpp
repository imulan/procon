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
    int n,r,t;
    cin >>n >>r >>t;
    vector<int> p(n);
    rep(i,n) scanf(" %d", &p[i]);

    //各部員の位置
    vector<int> pos(n,0);
    //出せる容器の本数
    vector<int> av(r,0);
    int ans=0;

    //最初の1秒は移動して渡すだけ
    rep(T,t)
    {
        //移動
        rep(i,n) pos[i]=(pos[i]+p[i])%r;

        //渡す
        rep(i,n)
        {
            if(av[pos[i]]==0) ++ans;
            else --av[pos[i]];
        }

        //回収
        if(T)
        {
            rep(i,n) ++av[pos[i]];
        }
    }

    cout << ans << endl;
    return 0;
}
