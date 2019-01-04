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

const int B = 318;
const int INF = 19191919;

int a[B][B];
vector<int> s[B];

int QUERY(int l, int r, int d){
    auto F = [&](int x){
        return abs(d-x);
    };

    int ret = INF;
    int lid = l/B, rid = r/B;
    if(lid == rid){
        for(int i=l; i<=r; ++i) ret = min(ret, F(a[i/B][i%B]));
    }
    else{
        for(int i=l; i<(lid+1)*B; ++i) ret = min(ret, F(a[i/B][i%B]));
        for(int b=lid+1; b<rid; ++b){
            auto itr = lower_bound(all(s[b]),d);
            ret = min(ret, F(*itr));
            --itr;
            ret = min(ret, F(*itr));
        }
        for(int i=B*rid; i<=r; ++i) ret = min(ret, F(a[i/B][i%B]));
    }
    return ret;
}

int main(){
    int n;
    scanf(" %d", &n);
    rep(i,n){
        int v;
        scanf(" %d", &v);

        int bid = i/B;
        a[bid][i%B] = v;
        s[bid].pb(v);
    }

    rep(i,B){
        s[i].pb(-INF);
        s[i].pb(INF);
        sort(all(s[i]));
    }

    int q;
    scanf(" %d", &q);
    rep(i,q){
        int l,r,d;
        scanf(" %d %d %d", &l, &r, &d);
        printf("%d\n", QUERY(l,r,d));
    }
    return 0;
}
