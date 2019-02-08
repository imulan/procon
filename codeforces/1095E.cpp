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
    int n;
    string s;
    cin >>n >>s;

    int ct = 0;
    rep(i,n){
        if(s[i] == '(') ++ct;
        else --ct;
    }

    if(abs(ct) != 2){
        cout << 0 << "\n";
        return 0;
    }

    if(ct == 2){
        reverse(all(s));
        rep(i,n){
            if(s[i]=='(') s[i] = ')';
            else s[i] = '(';
        }
    }

    vector<int> c(n);
    ct = 0;
    rep(i,n){
        if(s[i]=='(') ++ct;
        else --ct;

        c[i] = ct;
    }

    vector<int> pre(c), suf(c);
    rep(i,n-1) pre[i+1] = min(pre[i+1], pre[i]);
    for(int i=n-1; i>0; --i) suf[i-1] = min(suf[i-1], suf[i]);

    int ans = 0;
    rep(i,n)if(s[i]==')'){
        if(i>0 && pre[i-1]<0) continue;
        if(i<n-1 && suf[i+1]<-2) continue;

        ++ans;
    }
    cout << ans << "\n";
    return 0;
}
