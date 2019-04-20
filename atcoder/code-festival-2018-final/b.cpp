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

double logC(int n, int r){
    double ret = 0;
    rep(i,r){
        ret += log(n-i);
        ret -= log(i+1);
    }
    return ret;
}

int main(){
    int n,m;
    cin >>n >>m;
    vector<int> r(m);
    rep(i,m) cin >>r[i];

    int R = 0;
    double logp = 0;
    rep(i,m){
        logp += logC(n-R,r[i]);
        logp += -r[i]*log(m);
        R += r[i];
    }

    double V = -logp/log(10);
    int x = 0;
    while(V>x) ++x;
    cout << x << endl;
    return 0;
}
