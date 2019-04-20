#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
#define dbg(x) cout<<#x" = "<<((x))<<endl;

using pi = pair<int,int>;
using P = pair<pi,int>;
using vi = vector<int>;

const vi NG(1,-1);

vi solve(){
    int n;
    scanf(" %d", &n);

    vector<P> z(n);
    rep(i,n){
        int a,b;
        scanf(" %d %d", &a, &b);
        z[i] = {{a,b},i};
    }
    sort(all(z));
    reverse(all(z));

    int m;
    scanf(" %d", &m);

    vector<P> ax(m);
    rep(i,m){
        int a,b;
        scanf(" %d %d", &a, &b);
        ax[i] = {{a,b},i};
    }
    sort(all(ax));
    reverse(all(ax));

    int midx = 0;

    set<pi> s;
    vector<int> res(n);
    rep(i,n){
        int a=z[i].fi.fi, b=z[i].fi.se, idx = z[i].se;

        while(midx<m){
            int w = ax[midx].fi.fi, c = ax[midx].fi.se, a_idx = ax[midx].se;
            if(w<a) break;

            s.insert({c,a_idx});
            ++midx;
        }

        auto itr = s.lower_bound({b,-1});
        if(itr == s.end()) return NG;

        res[idx] = (itr->se) + 1;
        s.erase(itr);
    }
    return res;
}

int main(){
    vi a = solve();
    int A = a.size();
    rep(i,A) printf("%d%c", a[i], " \n"[i==A-1]);
    return 0;
}