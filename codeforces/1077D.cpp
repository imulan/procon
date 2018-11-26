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
    int n,k;
    scanf(" %d %d", &n, &k);

    vector<int> s(n);
    rep(i,n) scanf(" %d", &s[i]);

    map<int,int> m;
    rep(i,n) ++m[s[i]];

    vector<int> NG(k,-1);
    auto get_t = [&](int num){
        vector<int> ret;
        for(const auto &p:m){
            int v = p.fi;
            int c = p.se;
            rep(i,c/num) ret.pb(v);
        }

        if(ret.size() >= k){
            ret.resize(k);
            return ret;
        }

        return NG;
    };

    int ok=1, ng=n+1;
    while(ng-ok>1){
        int mid = (ng+ok)/2;
        vector<int> v = get_t(mid);
        if(v[0]==-1) ng = mid;
        else ok = mid;
    }

    vector<int> t = get_t(ok);
    rep(i,k) printf("%d%c", t[i], " \n"[i==k-1]);
    return 0;
}
