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

int solve(){
    int n;
    cin >>n;

    vector<int> a(n);
    rep(i,n) cin >>a[i];

    vector<int> s(a);
    sort(all(s));

    int q;
    cin >>q;
    vector<int> x(q),y(q);
    rep(i,q){
        cin >>x[i] >>y[i];
        --x[i];
        --y[i];
    }

    int ct = 0;
    vector<int> e(n);
    rep(i,n){
        e[i] = (a[i]==s[i]);
        ct += e[i];
    }
    if(ct == n) return 0;

    rep(i,q){
        ct -= e[x[i]];
        ct -= e[y[i]];

        swap(a[x[i]], a[y[i]]);
        e[x[i]] = (a[x[i]] == s[x[i]]);
        e[y[i]] = (a[y[i]] == s[y[i]]);

        ct += e[x[i]];
        ct += e[y[i]];

        if(ct == n) return i+1;
    }
    return -1;
}

int main(){
    cout << solve() << endl;
    return 0;
}
