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
    int h,w,n;
    cin >>h >>w >>n;
    vector<string> f(h);
    rep(i,h) cin >>f[i];

    bool valid=false;

    //入れ替える位置を選択:(i,j)と(i,j+1)
    rep(i,h)
    {
        rep(j,w-1)
        {
            if(f[i][j]=='.' && f[i][j+1]=='.') continue;
            //printf("start %d,%d\n",i,j );

            vector<string> t(f);
            swap(t[i][j],t[i][j+1]);
            //落下が起きるかもしれない
            //落下(y座標の方向に注意)
            rep(x,w)
            {
                for(int y=h-1; y>0; --y)
                {
                    //現在注目しているy座標より上が全て空なのでもう落下の必要がない
                    bool above=true;
                    for(int z=y; z>=0; --z) above&=(t[z][x]=='.');
                    if(above)break;

                    //実際に落とす
                    if(t[y][x]=='.')
                    {
                        for(int z=y; z>0; --z) t[z][x]=t[z-1][x];
                        t[0][x]='.';
                        ++y;
                    }
                }
            }

            while(1)
            {
                bool end=true;
                vector<vector<int>> del(h,vector<int>(w,0));

                //横ライン判定
                rep(y,h)rep(x,w-n+1)
                {
                    char focus=t[y][x];
                    if(focus=='.') continue;

                    int k=0;
                    while(x+k<w && t[y][x+k]==focus) ++k;
                    //printf("k=%d, x,y=%d,%d\n", k,x,y);
                    if(k>=n)
                    {
                        end=false;
                        for(int z=x; z<x+k; ++z) del[y][z]=1;
                    }

                }

                //縦ライン判定
                rep(x,w)rep(y,h-n+1)
                {
                    char focus=t[y][x];
                    if(focus=='.') continue;

                    int k=0;
                    while(y+k<h && t[y+k][x]==focus) ++k;

                    if(k>=n)
                    {
                        end=false;
                        for(int z=y; z<y+k; ++z) del[z][x]=1;
                    }
                }

                if(end) break;

                //消去
                rep(y,h)rep(x,w) if(del[y][x]) t[y][x]='.';

                //落下(y座標の方向に注意)
                rep(x,w)
                {
                    for(int y=h-1; y>0; --y)
                    {
                        //現在注目しているy座標より上が全て空なのでもう落下の必要がない
                        bool above=true;
                        for(int z=y; z>=0; --z) above&=(t[z][x]=='.');
                        if(above)break;

                        //実際に落とす
                        if(t[y][x]=='.')
                        {
                            for(int z=y; z>0; --z) t[z][x]=t[z-1][x];
                            t[0][x]='.';
                            ++y;
                        }
                    }
                }

                /*
                printf("now\n");
                rep(y,h) cout<<t[y]<<endl;
                printf("\n");
                */
            }

            //全部消えてるか判定
            valid=true;
            rep(y,h)rep(x,w) valid&=(t[y][x]=='.');
            if(valid) break;
        }
        if(valid) break;
    }

    string ans="NO";
    if(valid) ans="YES";
    std::cout << ans << std::endl;
    return 0;
}
