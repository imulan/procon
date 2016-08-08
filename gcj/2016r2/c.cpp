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
typedef pair<int, pi> ipi;

//coutierの位置と方向の関係をグリッド上に反映
ipi coutier_position(int num, int R, int C)
{
    if(num<=C) return ipi(0,pi(num-1,-1));
    num-=C;
    if(num<=R) return ipi(1,pi(C,num-1));
    num-=R;
    if(num<=C) return ipi(2,pi(C-num,R));
    num-=C;
    return ipi(3,pi(-1,R-num));
}

pi move(int x, int y, int direction)
{
    //下,左,上,右
    int dx[4]={0,-1,0,1}, dy[4]={1,0,-1,0};
    return pi(x+dx[direction], y+dy[direction]);
}

int main()
{
    int T;
    cin >>T;
    rep(t,T)
    {
        int r,c;
        cin >>r >>c;

        int NUM_PAIR = r+c;
        vector<pi> coutier(NUM_PAIR);
        vector<ipi> sorted_coutier(NUM_PAIR);
        rep(i,NUM_PAIR)
        {
            int x,y;
            scanf(" %d %d", &x, &y);
            //反時計まわりの方が早くなっている場合は入れ替える
            int dist_clockwise=0, dist_counterclockwise=0;
            if(x<y)
            {
                dist_clockwise = y-x;
                dist_counterclockwise = 2*(r+c) - dist_clockwise;
            }
            else
            {
                dist_counterclockwise = x-y;
                dist_clockwise = 2*(r+c) - dist_counterclockwise;
            }
            if(dist_clockwise < dist_counterclockwise) swap(x,y);
            coutier[i]=pi(x,y);
            sorted_coutier[i] = ipi(min(dist_clockwise, dist_counterclockwise), pi(x,y));
        }
        sort(all(sorted_coutier));
        //ソートを反映
        rep(i,NUM_PAIR) coutier[i] = sorted_coutier[i].se;

        //順番に処理
        bool valid = true;
        vector<string> ans(r, string(c,' '));
        rep(i,NUM_PAIR)
        {
            int start=coutier[i].fi, end=coutier[i].se;
            // printf("%d: %d to %d\n", i,start,end);

            ipi s=coutier_position(start, r, c);
            int dir=s.fi, x=s.se.fi, y=s.se.se;
            pi nxt=move(x,y,dir);
            x=nxt.fi; y=nxt.se;
            //グリッドから出るまで
            while(0<=y&&y<r && 0<=x&&x<c)
            {
                //まだその位置の壁が決まっていない時はできるだけ寄るように
                if(ans[y][x]==' ')
                {
                    int wall=dir&1;
                    string w="/\\";
                    ans[y][x]=w[wall];
                }
                //方向転換
                int mirror=3;
                if(ans[y][x]=='/') mirror=1;
                dir^=mirror;
                //移動
                nxt=move(x,y,dir);
                x=nxt.fi; y=nxt.se;
            }

            if(pi(x,y) != coutier_position(end,r,c).se)
            {
                valid=false;
                break;
            }
        }

        //output
        printf("Case #%d:\n", t+1);
        if(valid)
        {
            //空白は適当に埋めて良い
            rep(i,r)rep(j,c) if(ans[i][j]==' ') ans[i][j]='/';
            rep(i,r) cout << ans[i] << endl;
        }
        else printf("IMPOSSIBLE\n");
    }
    return 0;
}
