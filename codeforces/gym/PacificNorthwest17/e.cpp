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
    int n,X;
    double v;
    scanf(" %d %d %lf", &n, &X, &v);

    double p=0;
    rep(i,n){
        int l,r;
        double V;
        scanf(" %d %d %lf", &l, &r, &V);

        int D = r-l;
        p -= V*D;
    }

    double SIN = p/(X*v);
    if(abs(SIN)>=1) printf("Too hard\n");
    else{
        double theta = asin(SIN);
        printf("%.3f\n", X/(v*cos(theta)));
    }
    return 0;
}
