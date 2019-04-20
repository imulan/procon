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

int READ(){
    string s;
    cin >>s;

    int ret = 0;
    for(char c:s){
        if(c == '.') continue;
        ret = ret*10 + (c-'0');
    }
    return ret;
}

int main(){
    int n;
    cin >>n;

    vector<string> s(n);
    vector<int> a(n),b(n);
    rep(i,n){
        cin >>s[i];
        a[i] = READ();
        b[i] = READ();
    }

    int ans = 19191919;
    vector<string> t;
    rep(i,n){

        vector<pair<int,int>> v;
        rep(j,n)if(j!=i) v.pb({b[j], j});

        sort(all(v));
        int tmp = a[i];
        rep(j,3) tmp += v[j].fi;

        if(tmp < ans){
            ans = tmp;

            vector<string> vs;
            vs.pb(s[i]);
            rep(j,3) vs.pb(s[v[j].se]);
            t = vs;
        }
    }

    printf("%d.%02d\n", ans/100, ans%100);
    rep(i,4) cout << t[i] << '\n';
    return 0;
}
