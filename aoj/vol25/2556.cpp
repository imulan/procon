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

const ll mod = 1e9+7;

int calc(string s, string t){
    int n = s.size();
    rep(i,n){
        if(s[i]>t[i]) return 1;
        if(s[i]<t[i]) return -1;
    }
    return 0;
}

ll toI(string s){
    ll ret = 0;
    rep(i,s.size()) ret = (ret*10+s[i]-'0')%mod;
    return ret;
}

const int N = 10010;
ll pw[N];

ll f(string s, string c){
    // dbg(s);
    int S = s.size(), C = c.size();

    ll ret = 0;
    rep(i,S-C+1){
        string L = s.substr(0,i);
        string t = s.substr(i,C);
        string R = s.substr(i+C);

        int flg = calc(t,c);

        // cout << L << " " << t << " " << R << endl;

        if(L == ""){
            if(c != "0"){
                if(flg == 0) (ret += toI(R)) %= mod;
                else if(flg == 1) (ret += pw[R.size()]) %= mod;
            }
        }
        else{
            ll nL = toI(L);
            ll nR = toI(R);

            if(c != "0") nL = (nL+1)%mod;

            if(flg == 1){
                (ret += nL*pw[R.size()]) %= mod;
            }
            else if(flg == 0){
                (ret += (nL-1+mod)*pw[R.size()]) %= mod;
                (ret += nR+1) %= mod;
            }
            else{
                (ret += (nL-1+mod)*pw[R.size()]) %= mod;
            }
        }
        // dbg(ret);
    }

    return ret;
}

ll g(string s, string c){
    int S = s.size(), C = c.size();

    ll ret = 0;
    rep(i,S-C+1){
        if(s.substr(i,C) == c) ++ret;
    }

    return ret;
}

int main(){
    pw[0] = 1;
    rep(i,N-1) pw[i+1] = (pw[i]*10)%mod;

    string a,b,c;
    cin >>a >>b >>c;

    ll ans = f(b,c);
    ans = (ans-f(a,c)+mod)%mod;
    ans = (ans+g(a,c))%mod;
    cout << ans << endl;
    return 0;
}
