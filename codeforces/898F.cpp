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

struct RollingHash{
    static const int MD = 3;
    static const vector<ll> hash_base, hash_mod;

    int n;
    vector<ll> hs[MD], pw[MD];

    RollingHash(){}
    RollingHash(const string &s){
        n = s.size();
        rep(i,MD){
            hs[i].assign(n+1,0);
            pw[i].assign(n+1,0);
            hs[i][0] = 0;
            pw[i][0] = 1;
            rep(j,n){
                pw[i][j+1] = pw[i][j]*hash_base[i] % hash_mod[i];
                hs[i][j+1] = (hs[i][j]*hash_base[i]+(s[j]-'0')) % hash_mod[i];
            }
        }
    }

    // 1-index
    ll hash_value(int l, int r, int i){
        return ((hs[i][r] - hs[i][l]*pw[i][r-l])%hash_mod[i]+hash_mod[i])%hash_mod[i];
    }

    bool match(int l1, int r1, int l2, int r2){
        bool ret = true;
        rep(i,MD) ret &= (hash_value(l1-1,r1,i) == hash_value(l2-1,r2,i));
        return ret;
    }

    vector<ll> calc(int l, int r){
        vector<ll> ret(MD);
        rep(i,MD) ret[i]=hash_value(l-1,r,i);
        return ret;
    }
};
const vector<ll> RollingHash::hash_base{10,10,10};
const vector<ll> RollingHash::hash_mod{1000000009,1000000007,1000000021};

string form(const string &a, const string &b, const string &c){
    return a+"+"+b+"="+c;
}

string solve(){
    string s;
    cin >>s;

    int n = s.size();
    RollingHash h(s);

    rep(i,n){
        // aの桁数
        int A = i+1;
        vector<ll> a = h.calc(1,A);

        // aの桁数が支配的
        for(int y:{A,A+1}){
            int x = n-y;
            // bがなくなったらダメ
            if(i+1 > x-1) continue;

            int C = n-x;
            vector<ll> c = h.calc(x+1,n);
            int B = x-(i+1);
            vector<ll> b = h.calc(A+1,x);

            // leading zero
            if((A>1&&s[0]=='0') || (B>1&&s[A]=='0') || (C>1&&s[A+B]=='0')) continue;

            bool ok = true;
            rep(j,a.size()){
                ok &= ( (a[j]+b[j]) % RollingHash::hash_mod[j] == c[j] );
            }
            if(ok) return form(s.substr(0,A), s.substr(A,B), s.substr(A+B));
        }

        // bの桁数が支配的
        int L = n-1-i;
        if(L<2) continue;
        for(int C:{L/2,L/2+1}){
            int x = n-C;
            vector<ll> c = h.calc(x+1,n);
            // bがなくなったらダメ
            if(i+1 > x-1) continue;

            int B = x-(i+1);
            vector<ll> b = h.calc(A+1,x);

            // leading zero
            if((A>1&&s[0]=='0') || (B>1&&s[A]=='0') || (C>1&&s[A+B]=='0')) continue;

            bool ok = true;
            rep(j,a.size()){
                ok &= ( (a[j]+b[j]) % RollingHash::hash_mod[j] == c[j] );
            }
            if(ok) return form(s.substr(0,A), s.substr(A,B), s.substr(A+B));
        }
    }
    assert(false);
}

int main(){
    cout << solve() << endl;
    return 0;
}
