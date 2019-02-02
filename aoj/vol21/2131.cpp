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

const double EPS = 1e-9;
const double PI = acos(-1);

double f(int n, int d){
    double v = (double)n/d;
    return abs(v - PI);
}

int main(){
    double R;
    while(scanf(" %lf", &R)){
        if(R < EPS) break;

        int d = 1;
        while(1){
            int l=3*d, r=4*d;
            while(r-l>2){
                int m1 = (2*l+r)/3, m2 = (l+2*r)/3;
                if(f(m1,d) > f(m2,d)) l = m1;
                else r = m2;
            }

            int ans = -1;
            double mn = 1e9;
            for(int i=l; i<=r; ++i){
                double v = f(i,d);
                if(mn > v){
                    mn = v;
                    ans = i;
                }
            }

            if(mn < R+EPS){
                printf("%d/%d\n", ans, d);
                break;
            }
            ++d;
        }
    }
    return 0;
}
