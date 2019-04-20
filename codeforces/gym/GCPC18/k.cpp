#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const double EPS = 1e-8;

const int N = 60000;
bool dp[61][N];

int main(){
    int n,g;
    scanf(" %d %d", &n, &g);

    vector<int> d(n);
    rep(i,n){
        scanf(" %d", &d[i]);
        d[i] -= 10;
    }

    dp[0][0] = true;
    rep(i,n){
        for(int j=60; j>=0; --j)rep(k,N)if(dp[j][k]){
            dp[j+1][k+d[i]] = true;
        }
    }

    auto check = [&](double x){
        for(int i=1; i<=n; ++i){
            double l = 5.0*(i+1);
            double r = (10.0-x)*(i+1);

            rep(j,N)if(dp[i][j]){
                if(j+l<=g && g<=j+r) return true;
            }
        }
        return false;
    };

    double ok = -0.5, ng = 5.0;
    rep(loop,40){
        double mid = (ok+ng)/2;
        if(check(mid)) ok = mid;
        else ng = mid;
    }

    if(ok < -EPS) printf("impossible\n");
    else printf("%.10f\n", ok);
    return 0;
}

