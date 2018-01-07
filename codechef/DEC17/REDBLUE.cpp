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

struct Point{
    ll x,y;
};

__int128 sq(__int128 x){
    return x*x;
}

Point mirror(const Point p){
    if(p.y<0) return {-p.x, -p.y};
    return p;
}

bool comp(const Point &lp, const Point &rp)
{
    Point L = mirror(lp), R = mirror(rp);
    if(L.x*R.x<0) return L.x<R.x;
    else
    {
        if(L.x>=0 && R.x>=0) return sq(L.x)*(sq(R.x)+sq(R.y)) < sq(R.x)*(sq(L.x)+sq(L.y));
        else return sq(L.x)*(sq(R.x)+sq(R.y)) > sq(R.x)*(sq(L.x)+sq(L.y));
    }
}

int solve()
{
    int n,m;
    scanf(" %d %d", &n, &m);
    vector<Point> r(n),b(m);
    rep(i,n) scanf(" %lld %lld", &r[i].x, &r[i].y);
    rep(i,m) scanf(" %lld %lld", &b[i].x, &b[i].y);

    if(n==1 && m==1) return 0;

    int ans = n+m;
    rep(loop,2)
    {
        rep(i,n)
        {
            vector<Point> p,q;
            rep(j,n)if(i!=j) p.pb({r[j].x-r[i].x, r[j].y-r[i].y});
            rep(j,m) q.pb({b[j].x-r[i].x, b[j].y-r[i].y});

            sort(all(p),comp);
            sort(all(q),comp);

            int P = p.size(), Q = q.size();
            int ur=0, ub=0;
            rep(j,P) ur+=(p[j].y>=0);
            rep(j,Q) ub+=(q[j].y>=0);

            // 上の赤と下の青を残す
            ans = min(ans, n+m-(ur+1+m-ub));
            // 上の青と下の赤を残す
            ans = min(ans, n+m-(n-1-ur+1+ub));

            int idx = 0;
            rep(j,P)
            {
                while(idx<Q && comp(q[idx],p[j]))
                {
                    if(q[idx].y>=0) --ub;
                    else ++ub;
                    ++idx;
                }

                if(p[j].y>=0) --ur;
                else ++ur;

                // 上の赤と下の青を残す
                ans = min(ans, n+m-(ur+1+m-ub));
                // 上の青と下の赤を残す
                ans = min(ans, n+m-(n-1-ur+1+ub));
            }
        }
        swap(n,m);
        swap(r,b);
    }

    return ans;
}

int main()
{
    int T;
    scanf(" %d", &T);
    while(T--) printf("%d\n", solve());
    return 0;
}
