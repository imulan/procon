#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()

typedef complex<double> Point;
typedef vector<Point> VP;
const double EPS = 1e-5;

#define X real()
#define Y imag()

double dot(Point a,Point b){
    return a.X*b.X+a.Y*b.Y;
}

double cross(Point a,Point b){
    return a.X*b.Y-a.Y*b.X;
}

int ccw(Point a,Point b,Point c){
    b -= a;
    c -= a;
    if(cross(b,c) > EPS) return +1;
    if(cross(b,c) <-EPS) return -1;
    if(dot(b,c)   <-EPS) return +2;
    if(norm(b) < norm(c)) return -2;
    return 0;
}

bool isecSP(Point a1,Point a2,Point b){
    return !ccw(a1,a2,b);
}


Point proj(Point a1,Point a2,Point p){
    return a1+dot(a2-a1,p-a1)/norm(a2-a1)*(a2-a1);
}

double distSP(Point a1,Point a2,Point p){
    Point r = proj(a1,a2,p);
    if(isecSP(a1,a2,r)) return abs(r-p);
    return min(abs(a1-p),abs(a2-p));
}

const int N=1<<16;
int dp[N] = {};

int main()
{
    int n;
    cin >>n;

    vector<int> r(n);
    VP s(n),t(n);

    rep(i,n)
    {
        cin >>r[i];

        int x,y;
        cin >>x >>y;
        s[i] = Point(x,y);

        cin >>x >>y;
        t[i] = Point(x,y);
    }

    dp[0] = 1;
    rep(mask,1<<n)
    {
        if(!dp[mask]) continue;

        // 次に動かすコイン
        rep(i,n)if(!(mask>>i&1))
        {
            // それ以外のコインとの衝突判定
            bool valid = true;
            rep(j,n)if(i!=j)
            {
                Point c = s[j];
                if(mask>>j&1) c = t[j];

                double D = distSP(s[i], t[i], c);
                // printf(" %d %d : %f\n", i,j,D);

                if(r[i]+r[j] >= D) valid = false;
            }

            if(valid)
            {
                int nmask = mask | (1<<i);
                dp[nmask] = 1;
            }
        }
    }

    int ans = 0;
    rep(i,N)if(dp[i]) ans = max(ans, __builtin_popcount(i));
    cout << ans << endl;
    return 0;
}
