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

using pi = pair<int,int>;

double solve(){
    int n,T;
    scanf(" %d %d", &n, &T);

    vector<int> a(n),t(n);
    rep(i,n) scanf(" %d", &a[i]);
    rep(i,n) scanf(" %d", &t[i]);

    vector<pi> w(n);
    rep(i,n) w[i] = {t[i],a[i]};
    sort(all(w));

    auto cold = [&](){
        double p = 0, q = 0;
        rep(i,n){
            p += (double)w[i].fi*w[i].se;
            q += w[i].se;
        }

        return p/q < T;
    };

    double p = 0, q = 0;

    if(cold()){
        for(int i=n-1; i>=0; --i){
            double ap = (double)w[i].fi*w[i].se;
            double aq = w[i].se;
            if( (p+ap)/(q+aq) < T){

                double l = 0, r = w[i].se;
                rep(loop,100){
                    double m = (l+r)/2;
                    double bp = m*w[i].fi;

                    if( (p+bp)/(q+m) <= T ) r = m;
                    else l = m;
                }

                q += l;
                return q;
            }
            p += ap;
            q += aq;
        }
    }
    else{
        rep(i,n){
            double ap = (double)w[i].fi*w[i].se;
            double aq = w[i].se;
            if( (p+ap)/(q+aq) > T){
                double l = 0, r = w[i].se;
                rep(loop,100){
                    double m = (l+r)/2;
                    double bp = m*w[i].fi;

                    if( (p+bp)/(q+m) <= T ) l = m;
                    else r = m;
                }

                q += l;
                return q;
            }
            p += ap;
            q += aq;
        }
    }

    return q;
}

int main(){
    printf("%.10f\n", solve());
    return 0;
}
