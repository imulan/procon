#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
#define dbg(x) cout<<#x" = "<<((x))<<endl
template<class T,class U> ostream& operator<<(ostream& o, const pair<T,U> &p){o<<"("<<p.fi<<","<<p.se<<")";return o;}
template<class T> ostream& operator<<(ostream& o, const vector<T> &v){o<<"[";for(T t:v){o<<t<<",";}o<<"]";return o;}

using pi = pair<int,int>;

// (x,y), (spaceship/base, ID)
using Point = pair<pi,pi>;

int main(){
    int N;
    scanf(" %d", &N);

    vector<Point> pts;
    rep(i,2){
        rep(j,N){
            int x,y;
            scanf(" %d %d", &x, &y);
            pts.pb({{x,y},{i,j}});
        }
    }
    sort(all(pts));

    vector<int> ans(N);

    queue<vector<Point>> que;
    que.push(pts);
    while(!que.empty()){
        vector<Point> p = que.front();
        que.pop();
        int n = p.size();

        // 基準点としてx座標最小の点を選ぶ
        Point b = p[0];
        rep(i,n){
            p[i].fi.fi -= b.fi.fi;
            p[i].fi.se -= b.fi.se;
        }
        b = p[0];

        // 基準点からの偏角でソート
        vector<pair<double,int>> args;
        for(int i=1; i<n; ++i){
            double rad = atan2(p[i].fi.se, p[i].fi.fi);
            args.pb({rad,i});
        }
        sort(all(args));

        // bと線を引く相手wを探す
        Point w;
        int ct = 0;
        rep(i,n-1){
            int idx = args[i].se;

            if(b.se.fi == p[idx].se.fi) ++ct;
            else --ct;

            if(ct == -1){
                // このタイミングで分割することで、この線分より上も下もbalancedが保たれる
                w = p[idx];
                break;
            }
        }

        // bのマッチング相手が決定
        if(b.se.fi == 0) ans[b.se.se] = w.se.se;
        else ans[w.se.se] = b.se.se;

        // 直線 b-w で2つの領域に分割して部分問題を解く
        // Ax+By+C=0
        int A = w.fi.se - b.fi.se;
        int B = b.fi.fi - w.fi.fi;
        int C = b.fi.se*w.fi.fi - b.fi.fi*w.fi.se;

        vector<Point> l,r;
        rep(i,n){
            int x = p[i].fi.fi, y = p[i].fi.se;
            int val = A*x + B*y + C;

            if(val>0) l.pb(p[i]);
            else if(val<0) r.pb(p[i]);
        }
        if(!l.empty()) que.push(l);
        if(!r.empty()) que.push(r);
    }

    rep(i,N) printf("%d\n", ans[i]+1);
    return 0;
}
