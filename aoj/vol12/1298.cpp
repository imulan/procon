#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define x first
#define y second

const int INF = 19191919;

using Point = pair<int,int>;

bool solve(int n, int m){
    vector<Point> b(n),w(m);
    rep(i,n) cin >>b[i].x >>b[i].y;
    rep(i,m) cin >>w[i].x >>w[i].y;

    rep(i,n)rep(j,m){
        int A = w[j].y - b[i].y;
        int B = b[i].x - w[j].x;
        int C = b[i].y*w[j].x - b[i].x*w[j].y;

        bool ok = true;
        vector<pair<Point,int>> on_line;

        int bp = 0, bm = 0;
        rep(k,n){
            int v = A*b[k].x + B*b[k].y + C;

            if(v>0) ++bp;
            else if(v<0) ++bm;
            else on_line.pb({b[k],0});
        }

        int wp = 0 , wm = 0;
        rep(k,m){
            int v = A*w[k].x + B*w[k].y + C;

            if(v>0) ++wp;
            else if(v<0) ++wm;
            else on_line.pb({w[k],1});
        }

        if(bp>0 && bm>0) ok = false;
        if(wp>0 && wm>0) ok = false;
        if(bp>0 && wp>0) ok = false;
        if(bm>0 && wm>0) ok = false;

        if(!ok) continue;

        sort(all(on_line));
        int sz = on_line.size();
        int ch = 0;
        rep(k,sz-1) ch += (on_line[k].second != on_line[k+1].second);

        if(ch>1) ok = false;
        if(ok) return true;
    }

    return false;
}

int main(){
    int n,m;
    while(cin >>n >>m,n) cout << (solve(n,m)?"YES":"NO") << endl;
    return 0;
}
