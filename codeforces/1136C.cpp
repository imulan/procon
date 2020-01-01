#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
#define dbg(x) cout<<#x" = "<<((x))<<endl
template<class T,class U> ostream& operator<<(ostream& o, const pair<T,U> &p){o<<"("<<p.fi<<","<<p.se<<")";return o;}
template<class T> ostream& operator<<(ostream& o, const vector<T> &v){o<<"[";for(T t:v){o<<t<<",";}o<<"]";return o;}

using vi = vector<int>;
using mat = vector<vi>;

bool solve(){
    int h,w;
    scanf(" %d %d", &h, &w);

    auto READ = [&](){
        mat m(h, vi(w));
        rep(i,h)rep(j,w) scanf(" %d", &m[i][j]);
        return m;
    };

    vector<vi> v[2];
    rep(i,2){
        mat m = READ();
        v[i] = vector<vi>(h+w-1);

        rep(y,h)rep(x,w) v[i][x+y].pb(m[y][x]);
    }

    rep(i,h+w-1){
        rep(j,2) sort(all(v[j][i]));
        if(v[0][i] != v[1][i]) return false;
    }
    return true;
}

int main(){
    printf("%s\n", solve()?"YES":"NO");
    return 0;
}
