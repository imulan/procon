#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()

int main()
{
    int h,w;
    cin>>h>>w;

    vector<string> v(h);
    rep(i,h) cin>>v[i];

    rep(i,h) rep(j,w) if(v[i][j]=='.') {
        if(i==0 || i==h-1){
            v[i][j] = '#';
        }
        else if(i%2==0){
            if(j!=w-2) v[i][j] ='#';
        }
        else if(i%4==1){
            if(j==0 || j==w-1) v[i][j]='#';
        } else if(i%4==3){
            if(j==w-3 || j==w-1) v[i][j]='#';
        }
    }

    int sx,sy;
    rep(i,h) rep(j,w) if(v[i][j]=='@') sx=i,sy=j;

    auto IN = [&](int p, int q){
        return p>=0 && q>=0 && p<h && q<w;
    };

    int dx[] = {0,0,-1,1}, dy[]={1,-1,0,0};
    while(v[sx][sy]!='*'){
        rep(k,4){
            int nx = sx+dx[k], ny=sy+dy[k];
            if(IN(nx,ny)){
                if(v[nx][ny]=='#'){
                    v[nx][ny] = '.';
                    sx = nx;
                    sy = ny;
                    break;
                }
                else if(v[nx][ny]=='*'){
                    sx = nx;
                    sy = ny;
                    break;
                }
            }
        }
    }


    rep(i,h) cout << v[i] << "\n";


    return 0;
}
