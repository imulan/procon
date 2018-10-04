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

#define X first
#define Y second

using P = pair<int,int>;
using L = pair<P,P>;

// 内積　dot(a,b) = |a||b|cosθ
int dot(P a, P b) {
  return a.X*b.X + a.Y*b.Y;
}

// 外積　cross(a,b) = |a||b|sinθ
int cross(P a, P b) {
  return a.X*b.Y - a.Y*b.X;
}

int norm(P a){
    return a.X*a.X + a.Y*a.Y;
}

int ccw(P a, P b, P c) {
//   b -= a;  c -= a;
    b.X -= a.X;
    b.Y -= a.Y;
    c.X -= a.X;
    c.Y -= a.Y;
  if (cross(b,c) > 0) return +1;  // counter clockwise
  if (cross(b,c) < 0) return -1;  // clockwise
  if (dot(b,c)   < 0) return +2;  // c--a--b on line
  if (norm(b) < norm(c)) return -2;  // a--b--c on line or a==b
  return 0;                          // a--c--b on line or a==c or b==c
}

// 線分と点
bool isecSP(P a1, P a2, P b) {
  return !ccw(a1, a2, b);
}

double sq(double x){
    return x*x;
}

double dist(P a, P b){
    return sqrt( sq(a.X-b.X) + sq(a.Y-b.Y) );
}

P READ(){
    int x,y;
    scanf(" %d %d", &x, &y);
    return {x,y};
}

int main(){
    int n;
    while(scanf(" %d", &n),n){
        P s = READ(), g = READ();

        vector<L> seg(n);
        rep(i,n){
            seg[i].fi = READ();
            seg[i].se = READ();
        }

        auto count_online = [&](P p){
            int ct = 0;
            rep(i,n) ct += isecSP(seg[i].fi, seg[i].se, p);
            return ct;
        };

        vector<L> street,sign;
        rep(i,n){
            if(count_online(seg[i].fi)==1 || count_online(seg[i].se)==1){
                if(count_online(seg[i].se)==1) swap(seg[i].fi, seg[i].se);
                sign.pb(seg[i]);
            }
            else street.pb(seg[i]);
        }

        int M = street.size();
        // 交差点iはどのstreet上にあるか
        map<P,set<int>> cp;
        // street i 上にある交差点
        vector<vector<P>> pts(M);

        rep(i,M)for(P pp:{street[i].fi, street[i].se}){
            rep(j,M){
                if(isecSP(street[j].fi, street[j].se, pp)){
                    cp[pp].insert(j);
                    pts[j].pb(pp);
                }
            }
        }
        rep(i,M){
            sort(all(pts[i]));
            pts[i].erase(unique(all(pts[i])), pts[i].end());
        }

        map<P,double> d;
        map<P,P> par;

        using D = pair<double, P>;
        priority_queue<D, vector<D>, greater<D>> pq;
        d[s] = 0;
        pq.push({0,s});
        while(!pq.empty()){
            D cur = pq.top();
            pq.pop();

            P now = cur.se;
            if(cur.fi > d[now]) continue;

            for(int sid:cp[now]){
                int sz = pts[sid].size();
                int idx = lower_bound(all(pts[sid]), now) - pts[sid].begin();
                for(int i:{-1,1}){
                    int nx = idx+i;
                    if(nx<0 || sz<=nx) continue;
                    P np = pts[sid][nx];

                    P vec;
                    vec.X = np.X-now.X;
                    vec.Y = np.Y-now.Y;

                    bool ok = true;
                    for(L sg:sign){
                        if(isecSP(now,np,sg.se)){
                            P sv;
                            sv.X = sg.se.X -sg.fi.X;
                            sv.Y = sg.se.Y -sg.fi.Y;

                            if(dot(vec,sv) <= 0){
                                ok = false;
                                break;
                            }
                        }
                    }
                    if(ok){
                        if(!d.count(np) || d[np] > d[now]+dist(now,np)){
                            d[np] = d[now]+dist(now,np);
                            par[np] = now;
                            pq.push({d[np],np});
                        }
                    }
                }
            }
        }

        if(!d.count(g)) printf("-1\n");
        else{
            vector<P> ans;
            ans.pb(g);

            P now = g;
            while(par.count(now)){
                now = par[now];
                ans.pb(now);
            }

            reverse(all(ans));
            for(P pp:ans) printf("%d %d\n", pp.X, pp.Y);
            printf("0\n");
        }
    }
    return 0;
}
