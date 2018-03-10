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

bool ch(char a, char b){
    if(a>b) swap(a,b);
    return (a=='S' && b=='W');
}

void solve(){
    int h,w;
    cin >>h >>w;
    vector<string> s(h);
    rep(i,h) cin >>s[i];

    rep(i,h)rep(j,w)if(s[i][j]=='.') s[i][j]='D';

    rep(i,h){
        rep(j,w-1){
            if(ch(s[i][j], s[i][j+1])){
                cout << "No" << endl;
                return;
            }
        }
    }
    rep(j,w){
        rep(i,h-1){
            if(ch(s[i][j], s[i+1][j])){
                cout << "No" << endl;
                return;
            }
        }
    }

    cout << "Yes" << endl;
    rep(i,h) cout << s[i] << endl;
}

int main(){
    solve();
    return 0;
}
