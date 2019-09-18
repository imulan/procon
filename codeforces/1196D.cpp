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

const string c = "RGB";

int f(char x){
    rep(i,3)if(c[i]==x) return i;
}

int solve(){
    int n,k;
    string s;
    cin >>n >>k >>s;

    int ct[3][3] = {};
    rep(i,k) ++ct[i%3][f(s[i])];

    auto calc = [&](){
        int ret = k;
        rep(i,3){
            int tmp = 0;
            rep(j,3){
                int idx = (j+i)%3;

                int a = 0;
                rep(x,3) a += ct[j][x];
                a -= ct[j][idx];

                tmp += a;
            }
            ret = min(ret, tmp);
        }
        return ret;
    };

    int ans = calc();
    for(int i=k; i<n; ++i){
        --ct[(i-k)%3][f(s[i-k])];
        ++ct[i%3][f(s[i])];
        ans = min(ans, calc());
    }
    return ans;
}

int main(){
    int q;
    cin >>q;
    while(q--) cout << solve() << "\n";
    return 0;
}
