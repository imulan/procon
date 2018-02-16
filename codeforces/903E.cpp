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

bool have_same_c(const string &s){
    int ct[26]={};
    rep(i,s.size()) ++ct[s[i]-'a'];

    rep(i,26)if(ct[i]>=2) return true;
    return false;
}

string solve(){
    int k,n;
    cin >>k >>n;
    vector<string> s(k);
    rep(i,k) cin >>s[i];

    vector<string> can;
    rep(i,k)for(int j=i+1; j<k; ++j){
        rep(x,n){
            // 2n candidates
            if(s[i][x] != s[j][x]){
                rep(y,n)if(x!=y){
                    string t = s[i];
                    swap(t[x],t[y]);
                    can.pb(t);

                    t = s[j];
                    swap(t[x],t[y]);
                    can.pb(t);
                }

                i=j=k;
                break;
            }
        }
    }

    if(can.empty()){
        swap(s[0][0], s[0][1]);
        return s[0];
    }

    for(const string &c:can){
        bool valid = true;
        rep(i,k){
            vector<int> diff;
            rep(j,n)if(c[j] != s[i][j]) diff.pb(j);

            int D = diff.size();
            if(D==0){
                if(!have_same_c(s[i])) valid = false;
            }
            else if(D==2){
                int x = diff[0], y = diff[1];
                string t = c;
                swap(t[x],t[y]);
                if(t != s[i]) valid = false;
            }
            else valid = false;

            if(!valid) break;
        }

        if(valid) return c;
    }
    return "-1";
}

int main(){
    cout << solve() << endl;
    return 0;
}
