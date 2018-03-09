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

bool sur(const vector<string> &s){
    int n = s.size();
    rep(i,n){
        if(s[0][i]=='#') return false;
        if(s[n-1][i]=='#') return false;
        if(s[i][0]=='#') return false;
        if(s[i][n-1]=='#') return false;
    }
    return true;
}

int calc(const vector<string> &s){
    int n = s.size();
    int ret = 0;
    // horizontal one
    for(int y:{0,n-1})for(int x:{0,1}){
        vector<string> t(s);
        int tmp = 0;

        bool ok = true;
        rep(i,n-1) ok &= (t[y][x+i]=='.');
        if(ok){
            ++tmp;
            rep(i,n-1) t[y][x+i] = '#';
        }

        // vertical
        rep(i,n){
            rep(j,2){
                bool place = true;
                rep(k,n-1) place &= (t[j+k][i]=='.');

                if(place){
                    ++tmp;
                    rep(k,n-1) t[j+k][i] = '#';
                }
            }
        }
        ret = max(ret, tmp);
    }
    return ret;
}

int main(){
    int n;
    cin >>n;
    vector<string> s(n);
    rep(i,n) cin >>s[i];

    int ans = 0;
    if(sur(s)) ans = 4;
    ans = max(ans, calc(s));

    rep(i,n)rep(j,i) swap(s[i][j], s[j][i]);
    ans = max(ans, calc(s));

    cout << ans << endl;
    return 0;
}
