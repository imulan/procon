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
                hs[i][j+1] = (hs[i][j]*hash_base[i]+s[j]) % hash_mod[i];
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
const vector<ll> RollingHash::hash_base{1009,1021,1013};
const vector<ll> RollingHash::hash_mod{1000000009,1000000007,1000000021};

int main()
{
    string s;
    cin >>s;

    int S = s.size();
    RollingHash h(s);

    int aa = 0;
    for(int a=1; a<S; ++a)
    {
        int b = S-3*a;
        if(b<=0) continue;
        if(b%2==1) continue;

        b/=2;
        bool valid = true;

        if(h.calc(1,a)!=h.calc(a+b+1,a+b+a)) valid = false;
        if(h.calc(a+b+1,a+b+a)!=h.calc(2*(a+b)+1,2*(a+b)+a)) valid = false;
        if(h.calc(a+1,a+b)!=h.calc(2*a+b+1,2*a+b+b)) valid = false;

        if(valid) aa = a;
    }

    if(aa==0) cout << "mitomerarenaiWA" << endl;
    else
    {
        int l = aa + (S-3*aa)/2;
        cout << "Love " << s.substr(0,l) << "!" << endl;
    }
    return 0;
}
