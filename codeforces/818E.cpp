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

using M = map<int,int>;

M factorize(int n){
    map<int,int> ret;
    int t = n;
    for(int i=2; i*i<=n; ++i){
        while(t%i==0){
            ++ret[i];
            t /= i;
        }
    }
    if(t>1) ++ret[t];

    return ret;
}

bool div(M q, M k){
    for(const auto &p:k){
        if(!q.count(p.fi) || q[p.fi] < p.se) return false;
    }
    return true;
}

int main(){
    int n,k;
    cin >>n >>k;
    vector<int> a(n);
    rep(i,n) cin >>a[i];

    M fk = factorize(k);

    vector<M> ff(n);
    rep(i,n){
        int t = a[i];
        for(const auto &p:fk){
            int d = p.fi;
            while(t%d==0){
                ++ff[i][d];
                t /= d;
            }
        }
    }

    ll ans = 0;
    M now;
    int idx = 0;
    rep(i,n){
        while(idx<i){
            for(const auto &p:ff[idx]) now[p.fi] += p.se;
            ++idx;
        }

        while(idx < n){
            for(const auto &p:ff[idx]) now[p.fi] += p.se;
            if(div(now, fk)){
                for(const auto &p:ff[idx]) now[p.fi] -= p.se;
                break;
            }
            ++idx;
        }
        ans += n-idx;

        for(const auto &p:ff[i]) now[p.fi] -= p.se;
    }
    cout << ans << endl;
    return 0;
}
