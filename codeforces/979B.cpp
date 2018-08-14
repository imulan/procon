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

int f(string s, int n){
    int S = s.size();
    int ct[52]={};
    rep(i,S){
        if(islower(s[i])) ++ct[s[i]-'a'];
        else ++ct[s[i]-'A'+26];
    }

    int mx = 0;
    rep(i,52) mx = max(mx, ct[i]);

    if(n==1){
        if(mx==S) return max(1,S-1);
        return mx+1;
    }

    return min(S, mx+n);
}

const string a[4] = {"Kuro", "Shiro", "Katie", "Draw"};

string solve(){
    int n;
    string s[3];
    cin >>n;
    rep(i,3) cin >>s[i];

    int b[3];
    int mb = 0;
    rep(i,3){
        b[i] = f(s[i],n);
        mb = max(mb,b[i]);
    }

    int idx = -1;
    rep(i,3){
        if(mb == b[i]){
            if(idx != -1) idx = 3;
            else idx = i;
        }
    }
    return a[idx];
}

int main(){
    cout << solve() << endl;
    return 0;
}
