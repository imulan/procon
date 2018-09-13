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

const int N = 130000;
using B = bitset<N>;

void solve(){
    int n;
    scanf(" %d", &n);

    int ini = 0;
    vector<int> tate,yoko;
    rep(i,n+1){
        int a;
        scanf(" %d", &a);

        if(i==0) ini = a;
        else{
            if(i%2==0) tate.pb(a);
            else yoko.pb(a);
        }

        if(i==n) break;
        char f;
        scanf(" %c", &f);
    }

    if(tate.size()==0 || yoko.size()<=1){
        printf("NO\n");
        return;
    }

    auto calc = [&](const vector<int> &v, int x){
        B dp;
        dp.set(x);

        int V = v.size();
        rep(i,V){
            B nx = dp;
            nx <<= v[i];
            dp |= nx;
        }

        int sv = x;
        rep(i,V) sv += v[i];

        int ans = 19191919;
        rep(i,N)if(dp[i]){
            ans = min(ans,abs(sv-2*i));
        }

        return ans;
    };

    int ret = calc(tate,ini) + calc(yoko,0);
    printf("%d\n",ret);
}

int main(){
    int T;
    scanf(" %d", &T);
    while(T--) solve();
    return 0;
}
