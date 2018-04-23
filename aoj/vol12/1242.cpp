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

const int N = 4010;
int Y[N];

const int P = 2002;

int main(){
    int n;
    while(scanf(" %d", &n),n){
        vector<int> x(n),y(n);
        rep(i,n){
            scanf(" %d %d", &x[i], &y[i]);
            x[i] += P;
            y[i] += P;
        }

        int ans = 0;
        rep(i,N){

            vector<pair<pair<double,double>,int>> l;
            rep(j,n){
                int p = j, q = (j+1)%n;

                if(min(x[p],x[q])<=i && i+1<=max(x[p],x[q])){
                    double m = (double)(y[p]-y[q])/(x[p]-x[q]);
                    double b = y[p] - m*x[p];

                    double iy = m*i+b;
                    if(x[p] == i) iy = y[p];
                    if(x[q] == i) iy = y[q];

                    double iiy = m*(i+1)+b;
                    if(x[p] == i+1) iiy = y[p];
                    if(x[q] == i+1) iiy = y[q];

                    l.pb({ {min(iy, iiy), max(iy, iiy)}, j});
                }
            }

            sort(all(l));
            int L = l.size();
            assert(L%2==0);

            if(L==0) continue;

            // printf(" ---- i %d\n", i-P);
            fill(Y,Y+N,0);
            for(int j=0; j<L; j+=2){
                // lower
                int idx = l[j].se;
                int mx = x[idx]-x[(idx+1)%n], my = y[idx]-y[(idx+1)%n];
                if(mx<0){
                    mx *= -1;
                    my *= -1;
                }
                int ly = min( (my*(i-x[idx])+y[idx]*mx)/mx, (my*(i+1-x[idx])+y[idx]*mx)/mx );

                // upper
                idx = l[j+1].se;
                mx = x[idx]-x[(idx+1)%n];
                my = y[idx]-y[(idx+1)%n];
                if(mx<0){
                    mx *= -1;
                    my *= -1;
                }
                int ry = max( (my*(i-x[idx])+y[idx]*mx +mx-1)/mx, (my*(i+1-x[idx])+y[idx]*mx +mx-1)/mx );

                // printf(" %d %d\n", ly-P, ry-P);

                ++Y[ly];
                --Y[ry];
            }

            rep(j,N-1) Y[j+1] += Y[j];
            rep(j,N) ans += (Y[j]!=0);
        }
        printf("%d\n", ans);
    }
    return 0;
}
