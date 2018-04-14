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

vector<string> flipX(const vector<string> &s){
    int n = s.size();
    vector<string> t(n,string(n,' '));

    rep(i,n)rep(j,n) t[i][n-j-1] = s[i][j];
    return t;
}

vector<string> flipY(const vector<string> &s){
    int n = s.size();
    vector<string> t(n,string(n,' '));

    rep(i,n)rep(j,n) t[n-i-1][j] = s[i][j];
    return t;
}

vector<string> rotate(const vector<string> &s){
    int n = s.size();
    vector<string> t(n,string(n,' '));

    rep(i,n)rep(j,n) t[n-j-1][i] = s[i][j];
    return t;
}

bool solve(){
    int n;
    cin >>n;

    vector<string> s(n), t(n);
    rep(i,n) cin >>s[i];
    rep(i,n) cin >>t[i];

    rep(i,3){
        vector<string> u(s);

        if(i==1) u = flipX(u);
        if(i==2) u = flipY(u);

        rep(j,4){
            if(u == t) return true;
            u = rotate(u);
        }
    }

    return false;
}

int main(){
    cout << (solve()?"Yes":"No") << endl;
    return 0;
}
