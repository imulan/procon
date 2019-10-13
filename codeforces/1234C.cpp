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

bool solve(){
    int n;
    cin >>n;
    string s[2];
    rep(i,2) cin >>s[i];

    int h = 0;
    rep(i,n){
        int v = s[h][i]-'0';
        if(v>2){
            int o = s[!h][i]-'0';
            if(o>2) h = !h;
            else return false;
        }
    }
    return h==1;
}

int main(){
    int q;
    cin >>q;
    while(q--) cout << (solve()?"YES":"NO") << "\n";
    return 0;
}
