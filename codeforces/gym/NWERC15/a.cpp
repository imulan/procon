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

int main(){
    int n,m;
    scanf(" %d %d", &n, &m);

    vector<pi> e;
    rep(i,n){
        int a,s;
        scanf(" %d %d", &a, &s);

        // end
        e.pb({a+s, 0});
        // start
        e.pb({a, 1});
    }
    sort(all(e));

    int ans = 0;
    multiset<int> ave;
    rep(i,2*n){
        int t = e[i].fi;
        int q = e[i].se;

        if(q==0){
            // end
            ave.insert(t);
        }
        else{
            // start
            auto itr = ave.lower_bound(t-m);
            if(itr == ave.end()) ++ans;
            else ave.erase(itr);
        }
        // printf(" %d: %d %d\n", i, t, q);
        // dbg(ans);
    }

    printf("%d\n", n-ans);
    return 0;
}
