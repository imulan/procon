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
using P = pair<pi,int>;

bool cmp(const pi &lh, const pi &rh){
    return lh.fi*rh.se < rh.fi*lh.se;
}

int main(){
    int h,w;
    cin >>h >>w;
    vector<string> f(h);
    rep(i,h) cin >>f[i];

    // find corners
    /*
    .. #. ## .#
    .# .. #. ##
    */
    map<string,int> mp;
    mp["...#"] = -1;
    mp["#..."] = 1;
    mp["###."] = -1;
    mp[".###"] = 1;

    auto field = [&](int y, int x){
        if(0<=y && y<h && 0<=x && x<w) return f[y][x];
        return '.';
    };

    auto corner = [&](int y, int x){
        string pat = "";
        rep(i,2)rep(j,2){
            pat += field(h-1-y+i, x-1+j);
        }

        if(mp.count(pat)) return mp[pat];
        return 0;
    };

    vector<P> c;
    vector<pi> v;
    for(int i=0; i<=h; ++i){
        for(int j=0; j<=w; ++j){
            int cc = corner(i,j);
            if(cc != 0){
                int g = __gcd(i,j);
                c.pb({{i/g, j/g}, cc});
                v.pb({i/g, j/g});
            }
        }
    }

    sort(all(v), cmp);
    v.erase(unique(all(v)), v.end());
    int V = v.size();
    map<pi,int> idx;
    rep(i,V) idx[v[i]] = i;

    vector<vector<int>> Q(V);
    for(const auto &p:c){
        Q[idx[p.fi]].pb(p.se);
    }

    int ans = 1;
    int cur = 1;
    rep(i,V){
        for(int j:Q[i]) cur += j;
        ans = max(ans, cur);
    }

    cout << ans << endl;
    return 0;
}
