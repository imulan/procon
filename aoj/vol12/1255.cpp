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

const double eps = 1e-6;

struct Point{
    double x,y,z;
};

struct Sphere{
    Point c;
    double r;
};

void PP(Point p){
    printf(" (%f %f %f)\n", p.x, p.y, p.z);
}

void PS(Sphere s){
    printf("  r = %f,",s.r);
    PP(s.c);
}

inline double sq(double a){
    return a*a;
}

bool is_cross(Sphere s, Sphere t){
    Point p = s.c, q = t.c;
    double dist = sqrt( sq(p.x-q.x) + sq(p.y-q.y) + sq(p.z-q.z) );
    return dist <= s.r+t.r;
}

pair<double,double> get_cross_range(Sphere s, Sphere t){
    double mz = (t.r*s.c.z + s.r*t.c.z)/(s.r+t.r);

    pair<double,double> ret;

    double l=min(s.c.z-s.r, t.c.z-t.r), r=mz;
    rep(loop,40){
        double mid = (l+r)/2;
        double SR = sq(s.r)-sq(s.c.z-mid), TR = sq(t.r)-sq(t.c.z-mid);

        if(SR<eps || TR<eps){
            l = mid;
            continue;
        }

        SR = sqrt(SR);
        TR = sqrt(TR);

        double D = sqrt( sq(s.c.x-t.c.x) + sq(s.c.y-t.c.y) );
        if(D<=SR+TR) r = mid;
        else l = mid;
    }
    ret.fi = r;

    l=mz, r=max(s.c.z+s.r, t.c.z+t.r);
    rep(loop,40){
        double mid = (l+r)/2;
        double SR = sq(s.r)-sq(s.c.z-mid), TR = sq(t.r)-sq(t.c.z-mid);

        if(SR<eps || TR<eps){
            r = mid;
            continue;
        }

        SR = sqrt(SR);
        TR = sqrt(TR);

        double D = sqrt( sq(s.c.x-t.c.x) + sq(s.c.y-t.c.y) );
        if(D<=SR+TR) l = mid;
        else r = mid;
    }
    ret.se = l;

    return ret;
}

const int N = 100;
bool g[N][N];
bool e[N];

int cc(int n){
    int ret = 0;
    vector<bool> vis(n);
    rep(i,n){
        if(!vis[i] && e[i]){
            ++ret;

            vis[i] = true;
            queue<int> que;
            que.push(i);
            while(!que.empty()){
                int now = que.front();
                que.pop();
                rep(j,n){
                    if(g[now][j] && !vis[j] && e[j]){
                        vis[j] = true;
                        que.push(j);
                    }
                }
            }
        }
    }
    return ret;
}

using pi = pair<int,int>;
using P = pair<double,pi>;

int main(){
    int n;
    while(cin >>n,n){
        rep(i,N){
            e[i] = false;
            rep(j,N) g[i][j]=false;
        }


        vector<Sphere> s(n);
        rep(i,n){
            double x,y,z,r;
            cin >>x >>y >>z >>r;
            s[i] = {{x,y,z},r};
        }

        // rep(i,n) PS(s[i]);

        vector<P> EV;
        rep(i,n){
            double Z = s[i].c.z, R = s[i].r;
            EV.pb({Z-R,{i,-1}});
            EV.pb({Z+R,{i,-1}});
        }
        rep(i,n)rep(j,i){
            if(is_cross(s[i],s[j])){
                pair<double,double> range = get_cross_range(s[i],s[j]);
                EV.pb({range.fi,{i,j}});
                EV.pb({range.se,{i,j}});
            }
        }
        sort(all(EV));

        vector<int> ans;
        int crt = 0;

        int sz = EV.size();
        int idx = 0;
        while(idx<sz){
            double now_z = EV[idx].fi;
            while(idx<sz && EV[idx].fi<now_z+eps){
                pi event = EV[idx].se;
                if(event.se == -1){
                    int v = event.fi;
                    e[v] = !e[v];
                }
                else{
                    int u = event.fi, v = event.se;
                    g[u][v] = !g[u][v];
                    g[v][u] = !g[v][u];
                }

                ++idx;
            }

            int nx = cc(n);
            // dbg(nx);

            if(nx == crt+1) ans.pb(1);
            else if(nx == crt-1) ans.pb(0);
            crt = nx;
        }

        cout << ans.size() << "\n";
        for(int i:ans) cout << i;
        cout << "\n";
    }
    return 0;
}
