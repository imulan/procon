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

pi in(){
    int x,y;
    cin >>x >>y;
    return {x,y};
}

int main(){
    int n;
    cin >>n;

    vector<pi> r(n),b(n);
    rep(i,n) r[i] = in();
    sort(all(r));
    rep(i,n) b[i] = in();
    sort(all(b));

    int ridx = 0;
    set<int> y;
    int ans = 0;
    rep(i,n){
        int bx = b[i].fi, by = b[i].se;

        while(ridx<n && r[ridx].fi<bx){
            y.insert(r[ridx].se);
            ++ridx;
        }

        auto itr = y.lower_bound(by);
        if(itr != y.begin()){
            --itr;
            y.erase(itr);
            ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}
