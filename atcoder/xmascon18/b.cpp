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


inline bool LZ(string s){
    return s[0]=='0';
}

const ll INF = 20181224 + 24;

ll POW(string a, string b){
    ll A = stoi(a), B = stoi(b);
    if(A==1) return 1;

    ll ret = 1;
    rep(i,B){
        ret *= A;
        if(ret>INF) break;
    }
    return ret;
}

bool check(int x){
    string s = to_string(x);
    int n = s.size();
    for(int i=1; i<=n-2; ++i){
        string r = s.substr(0,n-i);
        string c = s.substr(n-i);

        if(LZ(c)) continue;
        // cout << "r c " << r << " " << c << endl;

        int R = r.size();
        rep(mask,1<<(R-1)){
            int bc = __builtin_popcount(mask);
            if(bc%2==0) continue;

            vector<string> v;
            string t = "";
            rep(j,R){
                t += r[j];
                if(mask>>j&1){
                    v.pb(t);
                    t = "";
                }
            }
            v.pb(t);
            // dbg(v);

            int V = v.size();
            assert(V%2==0);
            bool lz = false;

            ll now = stoi(c);
            for(int j=0; j<V; j+=2){
                string a = v[j], b = v[j+1];
                if(LZ(a) || LZ(b)){
                    lz = true;
                    break;
                }

                now *= POW(a,b);
                if(now>x) break;
            }
            if(lz) continue;

            if(now==x){
                dbg(v);
                return true;
            }
        }
    }

    return false;
}

int main(){
    const int N = 20181224;
    // const int N = 34425;

    vector<int> ans;
    for(int i=30000; i<=N; ++i){
        // printf(" -- %d\n",i);
        if(check(i)){
            printf("%d\n",i);
        }
    }

    return 0;
}
