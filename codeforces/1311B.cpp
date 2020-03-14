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
    int n,m;
    cin >>n >>m;

    vector<int> a(n);
    rep(i,n) cin >>a[i];

    vector<int> p(m);
    rep(i,m){
        cin >>p[i];
        --p[i];
    }
    sort(all(p));

    int s = 0;
    while(s<m){
        int idx = s;
        while(idx+1<m && p[idx]+1==p[idx+1]) ++idx;

        int l = p[s], r = p[idx]+1;
        sort(a.begin()+l, a.begin()+r+1);
        s = idx+1;
    }

    rep(i,n-1)if(a[i]>a[i+1]) return false;
    return true;
}

int main(){
    int T;
    cin >>T;
    while(T--) cout << (solve()?"YES":"NO") << "\n";
    return 0;
}
