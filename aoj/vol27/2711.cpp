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
    static const int MD = 2;
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
const vector<ll> RollingHash::hash_base{1009,1021};
const vector<ll> RollingHash::hash_mod{1000000009,1000000007};

int main(){
    string s;
    int Q;
    cin >>s >>Q;
    int S = s.size();

    string rev = s;
    reverse(all(rev));

    RollingHash H(s),T(rev);

    while(Q--){
        int l,r,t;
        scanf(" %d %d %d", &l, &r, &t);

        vector<int> check;
        // prefix
        int L = l, R = r;
        int ok = L+t-1, ng = R+1;
        rep(i,2){
            // printf(" binary s %d %d \n",ok,ng);
            // dbg(L);
            while(ng-ok>1){
                int mid = (ok+ng)/2;
                if(H.match(L+t,mid,L,mid-t)) ok = mid;
                else ng = mid;
            }
            if(l<=ok+1 && ok+1<=r) check.pb(ok+1);
            // dbg(ok+1);
            L = ok+2-t;
            ok = L+t-1;
            ng = R+1;
        }

        // suffix
        int cv_l = S-r+1, cv_r = S-l+1;
        L = cv_l;
        R = cv_r;
        ok = L+t-1;
        ng = R+1;
        rep(i,2){
            // printf(" binary s %d %d \n",ok,ng);
            // dbg(L);
            while(ng-ok>1){
                int mid = (ok+ng)/2;
                if(T.match(L+t,mid,L,mid-t)) ok = mid;
                else ng = mid;
            }
            if(l<=S+1 - (ok+1) && S+1 - (ok+1)<=r) check.pb(S+1 - (ok+1));
            // dbg(ok+1);
            // dbg(S+1 - (ok+1));
            L = ok+2-t;
            ok = L+t-1;
            ng = R+1;
        }

        set<int> IDX;
        for(int i:check){
            for(int j=-1; j<=1; ++j){
                int idx = i + j*t;
                if(l<=idx && idx<=r) IDX.insert(idx);
            }
        }
        map<char,int> mm;
        for(int idx:IDX){
            // printf(" FOCUS :: %d %c\n",idx,s[idx-1]);
            ++mm[s[idx-1]];
        }

        bool ans = true;
        if(mm.size() > 2) ans = false;
        else if(mm.size() == 2){
            vector<int> v;
            for(const auto p:mm) v.pb(p.se);
            if(min(v[0],v[1])>1) ans = false;
        }

        printf("%s\n", (ans?"Yes":"No"));
    }
    return 0;
}
