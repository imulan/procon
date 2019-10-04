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
    int n;
    string s;
    cin >>n >>s;

    vector<int> f(10);
    for(int i=1; i<=9; ++i) cin >>f[i];

    int l = 0;
    while(l<n){
        int v = s[l]-'0';
        if(v < f[v]) break;
        ++l;
    }

    int r = l;
    while(r<n){
        int v = s[r]-'0';
        if(v > f[v]) break;
        ++r;
    }

    for(int i=l; i<r; ++i) s[i] = f[s[i]-'0']+'0';
    cout << s << "\n";
    return 0;
}
