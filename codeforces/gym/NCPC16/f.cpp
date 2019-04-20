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

const int N = 1000000;

int main(){
    int n,p;
    scanf(" %d %d", &n, &p);

    double ans = 1.0*p/(n+1);

    // just 1
    // i * n C p-1 / n+i C p
    double one = 2*p;
    int pp = n, qq = n+2;
    for(int i=p; i>=1; --i){
        if(i>1) one *= pp;
        one /= qq;
        --pp;
        --qq;
    }

    for(int i=2; i<=N; ++i){
        ans = max(ans, one);

        // update
        one /= n+(i+1);
        one *= n+i-(p-1);
        one /= i;
        one *= i+1;
    }
    printf("%.10f\n", ans);
    return 0;
}
