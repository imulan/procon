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

const double eps = 1e-9;

const int N = 200000;
int use[N];

const int D = 86400;

int main(){
    int n,L;
    while(scanf(" %d %d", &n, &L),n){
        fill(use,use+N,0);

        int min_s = N;
        rep(i,n){
            int s,t,u;
            scanf(" %d %d %d", &s, &t, &u);
            min_s = min(min_s, s);
            use[s] += u;
            use[t] -= u;
        }

        rep(i,N-1) use[i+1] += use[i];

        auto check = [&](double m){
            double x = L;

            vector<int> full(D);
            rep(i,D){
                double d = m-use[i];
                x += d;
                if(x>L){
                    x = L;
                    ++full[i];
                }
                if(x<-eps) return false;
            }

            rep(i,D){
                double d = m-use[i];
                x += d;
                if(x>L){
                    x = L;
                    if(full[i]) return true;
                }
                if(x<-eps) return false;
            }
            return false;
        };

        double l=0, r=1000000;
        rep(loop,50){
            double mid = (l+r)/2;
            if(check(mid)) r = mid;
            else l = mid;
        }
        printf("%.10f\n", r);
    }
    return 0;
}
