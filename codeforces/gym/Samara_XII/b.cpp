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

int main(){
    string s[2];
    rep(i,2) cin >>s[i];

    int n = s[0].size();

    int ct[4] = {};
    rep(i,n){
        int a = 0;
        rep(j,2)if(s[j][i]=='#') a |= (1<<j);
        ++ct[a];
    }

    if(ct[1] && ct[2] && !ct[3]) cout << "NO" << "\n";
    else{
        cout << "YES" << "\n";

        int idx = 0;
        for(int v:{0,1,3,2})rep(loop,ct[v]){
            rep(i,2) s[i][idx] = (v>>i&1)?'#':'.';
            ++idx;
        }

        rep(i,2) cout << s[i] << "\n";
    }
    return 0;
}
