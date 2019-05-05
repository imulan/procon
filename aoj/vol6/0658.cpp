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

using vi = vector<int>;

int main(){
    int h,w;
    cin >>h >>w;
    vector<string> s(h);
    rep(i,h) cin >>s[i];

    vector<vi> O(h, vi(w+1)), I(w, vi(h+1));
    rep(i,h){
        for(int j=w-1; j>=0; --j){
            O[i][j] = O[i][j+1];
            if(s[i][j] == 'O') ++O[i][j];
        }
    }

    rep(i,w){
        for(int j=h-1; j>=0; --j){
            I[i][j] = I[i][j+1];
            if(s[j][i]=='I') ++I[i][j];
        }
    }

    ll ans = 0;
    rep(i,h)rep(j,w)if(s[i][j] == 'J') ans += O[i][j+1]*I[j][i+1];
    cout << ans << endl;
    return 0;
}
