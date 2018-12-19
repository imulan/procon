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

using ps = pair<string, int>;

string solve(){
    int n;
    cin >>n;

    int sz = 2*n - 2;
    vector<string> s(sz);

    vector<vector<int>> L(n);
    rep(i,sz){
        cin >>s[i];

        int S = s[i].size();
        L[S].pb(i);
    }

    string pre = s[L[n-1][0]], suf = s[L[n-1][1]];
    rep(__,2){
        string ans = pre + suf.back();

        auto check_pre = [&](string t){
            int T = t.size();
            rep(i,T)if(t[i]!=ans[i]) return false;
            return true;
        };

        auto check_suf = [&](string t){
            int T = t.size();
            rep(i,T)if(t[T-1-i]!=ans[n-1-i]) return false;
            return true;
        };

        string ret(sz,'?');
        bool valid = true;
        for(int i=1; i<n; ++i){
            bool found = false;
            int pidx = L[i][0], sidx = L[i][1];
            rep(j,2){
                string pp = s[pidx], ss = s[sidx];
                if(check_pre(pp) && check_suf(ss)){
                    found = true;
                    break;
                }
                swap(pidx,sidx);
            }

            if(!found){
                valid = false;
                break;
            }
            ret[pidx] = 'P';
            ret[sidx] = 'S';
        }

        if(valid) return ret;
        swap(pre,suf);
    }
    return "#";
}

int main(){
    cout << solve() << endl;
    return 0;
}
