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
    int n;
    scanf(" %d", &n);
    vector<int> x(n);
    rep(i,n) scanf(" %d", &x[i]);

    vector<int> sx(x);
    sort(all(sx));

    int a = sx[n/2-1], b = sx[n/2];
    rep(i,n){
        int z = b;
        if(b<=x[i]) z = a;
        printf("%d\n",z);
    }
    return 0;
}
