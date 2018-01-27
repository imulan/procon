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

const int N = 10000001;
int f(int n){
    return n*(n+1)/2;
}

int solve(){
    int n;
    cin >>n;

    vector<int> c;
    rep(i,N){
        if(f(i+1)>N) break;
        c.pb(f(i+1));
        if(c.back() == n) return 1;
    }

    int C = c.size();
    rep(i,C)rep(j,C)if(c[i]+c[j]==n) return 2;
    return 3;
}

int main(){
    cout << solve() << endl;
    return 0;
}
