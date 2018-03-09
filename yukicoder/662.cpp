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

int main(){
    string s[5];
    int c[5];
    rep(i,5) cin >>s[i] >>c[i];

    int n[3];
    ll ct[3][5]={};

    rep(i,3){
        cin >>n[i];
        rep(j,n[i]){
            string t;
            cin >>t;
            int idx = -1;
            rep(k,5){
                if(t == s[k]) idx=k;
            }
            assert(idx!=-1);
            ++ct[i][idx];
        }
    }

    double E = 0;
    ll ans[5]={};
    rep(i,5){
        ans[i] = 5;
        rep(j,3) ans[i]*=ct[j][i];
        E += ans[i]*c[i];
    }
    rep(i,3) E/=n[i];

    printf("%.10f\n", E);
    rep(i,5) printf("%lld\n", ans[i]);
    return 0;
}
