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
    int n,h;
    cin >>n >>h;

    double S = h/2.0;

    vector<double> ans;
    for(int i=1; i<n; ++i){
        double T = S*i/n;
        ans.pb(sqrt(2*h*T));
    }

    int A = ans.size();
    rep(i,A) printf("%.10f%c", ans[i], " \n"[i==A-1]);
    return 0;
}
