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

ll calc(const string &s){
    ll c = 1;
    ll ret = 0;
    rep(i,s.size()){
        if(s[i] == 'C') c *= 2;
        else ret += c;
    }
    return ret;
}

void solve(){
    int d;
    string s;
    cin >>d >>s;
    int n = s.size();

    if(calc(s)<=d){
        printf("0\n");
        return;
    }

    int ct = 0;
    while(1){
        int idx = n-1;
        while(idx>0){
            if(s[idx]=='S' && s[idx-1]=='C'){
                swap(s[idx],s[idx-1]);
                ++ct;
                break;
            }
            --idx;
        }

        if(idx == 0)  break;
        else{
            if(calc(s)<=d) break;
        }
    }

    if(calc(s)<=d) printf("%d\n", ct);
    else printf("IMPOSSIBLE\n");
}

int main(){
    int T;
    cin >>T;
    rep(i,T){
        printf("Case #%d: ", i+1);
        solve();
    }
    return 0;
}
