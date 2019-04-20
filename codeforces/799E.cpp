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
    int n,m,k;
    scanf(" %d %d %d", &n, &m, &k);
    vector<ll> c(n);
    rep(i,n) scanf(" %lld", &c[i]);

    vector<bool> a(n),b(n);
    int num,fav;
    scanf(" %d", &num);
    while(num--){
        scanf(" %d", &fav);
        --fav;
        a[fav] = true;
    }
    scanf(" %d", &num);
    while(num--){
        scanf(" %d", &fav);
        --fav;
        b[fav] = true;
    }




    return 0;
}
