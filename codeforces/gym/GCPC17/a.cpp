#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

#define X first
#define Y second
using pd = pair<double,double>;

int main(){
    int n;
    scanf(" %d", &n);

    map<int,vector<int>> pts[2];
    rep(i,n){
        int x,y,c;
        scanf(" %d %d %d", &x, &y, &c);
        --c;

        if(c<=1) pts[c][y].pb(x);
    }

    rep(col,2){
        int mul = 1;
        if(col==0) mul = -1;

        vector<pd> poly;
        for(int i:{2000,1999}) poly.pb({i*mul, -2000});

        int sx = 1999*mul;
        int ex = 1995*mul*(-1);

        for(const auto &p:pts[col]){
            double yy = p.fi;
            if(col==0){
                poly.pb({sx,yy-0.2});
                poly.pb({ex,yy-0.2});
                poly.pb({ex,yy-0.1});
            }
            else{
                poly.pb({sx,yy+0.1});
            }

            vector<int> posx = p.se;
            sort(all(posx));
            reverse(all(posx));

            for(int i:posx){
                poly.pb({i+0.1, yy+0.1*mul});
                poly.pb({i+0.1, yy-0.05*mul});
                poly.pb({i-0.1, yy-0.05*mul});
                poly.pb({i-0.1, yy+0.1*mul});
            }

            if(col==0){
                poly.pb({sx,yy-0.1});
            }
            else{
                poly.pb({ex,yy+0.1});
                poly.pb({ex,yy+0.2});
                poly.pb({sx,yy+0.2});
            }
        }

        for(int i:{1999,2000}) poly.pb({i*mul, 2000});

        printf("%d\n", poly.size());
        for(pd p:poly) printf("%.2f %.2f\n", p.X, p.Y);
    }

    return 0;
}