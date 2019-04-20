#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define pb push_back

int main(){
    int n;
    cin >>n;
    vector<string> s(n);
    rep(i,n) cin >>s[i];

    int m;
    cin >>m;
    vector<int> a(m),b(m);
    rep(i,m){
        cin >>a[i] >>b[i];
        --a[i];
        --b[i];
    }

    int ct = 0;
    int t = 0;
    for(int i=m-1; i>=0; --i){
        if(a[i]==t){
            ++ct;
            t = b[i];
        }
    }

    string ans = "";
    rep(i,ct) ans += "I_love_";
    ans += s[t];
    cout << ans << "\n";
    return 0;
}