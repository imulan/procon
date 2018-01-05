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

int m[36]={31,28,31,30,31,30,31,31,30,31,30,31,
           31,28,31,30,31,30,31,31,30,31,30,31,
           31,29,31,30,31,30,31,31,30,31,30,31};

string solve(){
    int n;
    cin >>n;
    vector<int> a(n);
    rep(i,n) cin >>a[i];

    rep(i,36){
        bool ok = true;
        rep(j,n){
            int idx=(i+j)%36;
            ok &= (a[j]==m[idx]);
        }
        if(ok) return "YES";
    }
    return "NO";
}

int main(){
    cout << solve() << endl;
    return 0;
}
