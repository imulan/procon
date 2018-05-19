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

void solve(){
    int c;
    cin >>c;
    vector<int> b(c);
    rep(i,c) cin >>b[i];

    if(b[0]==0 || b[c-1]==0){
        printf("IMPOSSIBLE\n");
        return;
    }

    string emp(c,'.');
    vector<string> f(c,emp);

    int idx = 0;
    rep(i,c){
        while(idx<c && b[idx]==0) ++idx;

        if(idx<i){
            rep(j,i-idx){
                f[j][i-j]='/';
            }
        }
        else if(i<idx){
            rep(j,idx-i){
                f[j][i+j]='\\';
            }
        }
        --b[idx];
    }

    vector<string> ans;
    rep(i,c){
        ans.pb(f[i]);
        if(f[i]==emp) break;
    }
    cout << ans.size() << endl;
    for(string s:ans) cout << s << endl;
}

int main(){
    int T;
    cin >>T;
    rep(i,T){
        printf("Case #%d: ", i+1);
        solve();
    }
    return 0;
}
