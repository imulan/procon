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

void solve(){
    string s;
    cin >>s;
    int n = s.size();

    int ct[26]={};
    rep(i,n) ++ct[s[i]-'a'];

    int odd = 0;
    rep(i,26) odd += ct[i]%2;

    if(odd>1){
        cout << -1 << endl;
        return;
    }

    string p = "";
    if(odd==1){
        rep(i,26){
            if(ct[i]%2==1) p += 'a'+i;
            --ct[i];
        }
    }

    rep(i,26){
        while(ct[i]>0){
            char c = 'a'+i;
            p = c+p+c;
            ct[i] -= 2;
        }
    }

    queue<int> idx[26];
    rep(i,n) idx[s[i]-'a'].push(i+1);

    vector<int> ans(n);
    rep(i,n){
        ans[i] = idx[p[i]-'a'].front();
        idx[p[i]-'a'].pop();
    }
    rep(i,n) cout << ans[i] << " \n"[i==n-1];
}

int main(){
    int T;
    cin >>T;
    while(T--) solve();
    return 0;
}
