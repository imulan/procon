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

const int N = 500005;
ll sa[N]={};

ll v;
double f(int i){
    double ret = v*i - sa[i];
    return ret / (i+1);
}

int main(){
    int Q;
    scanf(" %d", &Q);

    int n = 0;
    while(Q--){
        int t;
        scanf(" %d", &t);
        if(t==1){
            scanf(" %lld", &v);
            ++n;
            sa[n] = sa[n-1]+v;
        }
        else{
            double ans = 0;
            if(n>1){
                int l=1, r=n-1;
                while(r-l>2){
                    int m1 = (2*l+r)/3, m2 = (l+2*r)/3;
                    if(f(m1) < f(m2)) l = m1;
                    else r = m2;
                }
                for(int i=l; i<=r; ++i) ans = max(ans, f(i));
            }
            printf("%.10f\n", ans);
        }
    }
    return 0;
}
