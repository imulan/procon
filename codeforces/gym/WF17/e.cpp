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
    int n,t;
    scanf(" %d %d", &n, &t);

    vector<int> d(n),s(n);
    rep(i,n) scanf(" %d %d", &d[i], &s[i]);

    auto check = [&](double c){
        double t_sum = 0;
        rep(i,n){
            double speed = s[i]+c;
            if(speed<=0) return false;

            t_sum += d[i]/speed;
        }
        return t_sum <= t;
    };

    double ng = -1000, ok = 20000000;
    rep(loop,80){
        double c = (ng+ok)/2;
        if(check(c)) ok = c;
        else ng = c;
    }

    printf("%.10f\n", ok);
    return 0;
}
