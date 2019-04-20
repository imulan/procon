#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
#define dbg(x) cout<<#x" = "<<((x))<<endl;

const double PI = acos(-1);

int main(){
    double xp,yp,xd,yd;
    scanf(" %lf %lf %lf %lf", &xp, &yp, &xd, &yd);

    double dx = xp-xd, dy = yp-yd;
    double D = sqrt(dx*dx + dy*dy);

    double b = D/2;
    double a = b*7/6;
    printf("%.20f\n", PI*a*b);
    return 0;
}