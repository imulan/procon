#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

string solve(){
    string s[3];
    rep(i,3) cin >>s[i];

    int n = s[0].size();

    string ans = "?";

    string tmp = s[0];

    int ct[3]={};
    bool no_change = true;
    for(int i:{1,2}){
        ct[i]=0;
        rep(j,n) if(s[i][j] != s[0][j]) ++ct[i];

        if(ct[i]>1) no_change = false;
    }
    if(no_change) ans = tmp;

    rep(i,n){
        char def = tmp[i];
        rep(j,26){
            char c = 'a'+j;
            if(def == c) continue;

            tmp[i] = c;

            bool valid = true;
            for(int k:{1,2}){
                int tct = ct[k];
                if(s[k][i]==c) --tct;
                if(s[k][i]==def) ++tct;

                if(tct>1) valid = false;
            }

            if(valid){
                if(ans == "?") ans = tmp;
                else return "Ambiguous";
            }

            tmp[i] = def;
        }
    }

    if(ans == "?") return "Impossible";
    return ans;
}

int main(){
    cout << solve() << endl;
    return 0;
}