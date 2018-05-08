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

int main(){
    int n;
    while(cin >>n,n){
        int pw;
        scanf(" %d", &pw);

        vector<int> vw(n),pf(n),vf(n),th(n);
        rep(i,n) scanf(" %d %d %d %d", &vw[i], &pf[i], &vf[i], &th[i]);

        auto f = [&](double W){
            double cost = W*pw;
            rep(i,n){
                double F = (th[i]-W*vw[i])/vf[i];
                F = max(0.0,F);
                cost += F*pf[i];
            }
            return cost;
        };

        double l = 0, r = 10000;
        rep(_,100){
            double m1 = (2*l+r)/3, m2 = (l+2*r)/3;
            if(f(m1) > f(m2)) l = m1;
            else r = m2;
        }
        printf("%.10f\n", f(l));
    }
    return 0;
}
