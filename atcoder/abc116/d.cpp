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

using P = pair<ll,int>;
const P NG(-1,-1);

int main(){
    int n,k;
    cin >>n >>k;

    vector<int> t(n);
    vector<ll> d(n);
    rep(i,n){
        cin >>t[i] >>d[i];
        --t[i];
    }

    vector<P> mx(n,NG);
    rep(i,n){
        mx[t[i]] = max(mx[t[i]], {d[i],i});
    }

    vector<P> TOP;
    rep(i,n){
        if(mx[i]==NG) continue;
        TOP.pb(mx[i]);
    }
    sort(all(TOP));
    reverse(all(TOP));
    int T = TOP.size();

    ll rem_sum = 0;
    multiset<P> ms;
    rep(i,n){
        ms.insert({d[i],i});
        rem_sum += d[i];

        if(ms.size()>k){
            auto itr = ms.begin();
            rem_sum -= itr->fi;
            ms.erase(itr);
        }
    }

    ll ans = 0;
    ll top_sum = 0;
    for(ll x=1; x<=k; ++x){
        if(x > T) break;

        P add = TOP[x-1];

        top_sum += add.fi;
        int idx = add.se;

        if(ms.count(add)){
            ms.erase(add);
            rem_sum -= add.fi;
        }
        else{
            auto itr = ms.begin();
            rem_sum -= itr->fi;
            ms.erase(itr);
        }

        // printf(" x %d :: top %lld rem %lld\n",x,top_sum,rem_sum);
        ans = max(ans, top_sum+rem_sum+x*x);
    }

    cout << ans << endl;
    return 0;
}
