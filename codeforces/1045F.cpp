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

bool solve(){
    int n;
    scanf(" %d", &n);

    vector<int> a(n),b(n);
    rep(i,n) scanf(" %d %d", &a[i], &b[i]);

    set<pi> X[2],Y[2];
    rep(i,2){
        X[i].insert({2,2});
        Y[i].insert({2,2});
    }

    rep(i,n){
        X[a[i]%2].insert({-b[i],-a[i]});
        Y[b[i]%2].insert({-a[i],-b[i]});
    }

    rep(i,n){
        int oa = a[i]%2, ob = b[i]%2;
        X[oa].erase({-b[i],-a[i]});
        Y[ob].erase({-a[i],-b[i]});

        // y -> -INF
        auto itr_odd = Y[1].begin();
        auto itr_even = Y[0].begin();
        if(itr_odd->fi < itr_even->fi) return true;

        // y -> INF
        if(itr_odd->fi > itr_even->fi){
            if(abs(itr_even->se)%2 == 1) return true;
        }

        // x -> -INF
        itr_odd = X[1].begin();
        itr_even = X[0].begin();
        if(itr_odd->fi < itr_even->fi) return true;

        // x -> INF
        if(itr_odd->fi > itr_even->fi){
            if(abs(itr_even->se)%2 == 1) return true;
        }

        X[oa].insert({-b[i],-a[i]});
        Y[ob].insert({-a[i],-b[i]});
    }

    return false;
}

int main(){
    cout << (solve()?"Ani":"Borna") << endl;
    return 0;
}
