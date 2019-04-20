#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define pb push_back

using pi = pair<int,int>;

const vector<int> NG(1,-1);

vector<int> solve(){
    int n;
    cin >>n;
    vector<string> s(n);
    rep(i,n) cin >>s[i];

    int a = 0;
    rep(i,n){
        for(char c:s[i]){
            if(c=='(') ++a;
            else --a;
        }
    }
    if(a!=0) return NG;

    vector<int> pos,neg;
    rep(i,n){
        int ct = 0;
        for(char c:s[i]){
            if(c=='(') ++ct;
            else --ct;
        }
        if(ct>=0) pos.pb(i);
        else{
            neg.pb(i);
            reverse(all(s[i]));
            rep(j,s[i].size()){
                if(s[i][j]=='(') s[i][j]=')';
                else s[i][j] = '(';
            }
        }
    }

    auto calc_pos = [&](const vector<int> &z){
        using P = pair<pi,int>;

        int Z = z.size();
        vector<P> v(Z);
        rep(i,Z){
            int ct = 0, mn = 0;
            for(char c:s[z[i]]){
                if(c=='(') ++ct;
                else --ct;
                mn = min(mn,ct);
            }

//            printf(" %d: %d %d\n",i,ct,mn);
            v[i] = {{-mn,ct},i};
        }
        sort(all(v));

        vector<int> ret;
        int now = 0;
        rep(i,Z){
            int mn = -v[i].fi.fi, ad = v[i].fi.se;
            int idx = v[i].se;
            if(now + mn < 0) return NG;

            now += ad;
            ret.pb(z[idx]);
        }

        return ret;
    };

    vector<int> x = calc_pos(pos);
    vector<int> y = calc_pos(neg);

    if(x==NG || y==NG) return NG;
    reverse(all(y));
    for(int i:y) x.pb(i);

    for(int i:neg){
        reverse(all(s[i]));
        rep(j,s[i].size()){
            if(s[i][j]=='(') s[i][j]=')';
            else s[i][j] = '(';
        }
    }

    int ct = 0;
    for(int i:x){
        for(char c:s[i]){
            if(c=='(') ++ct;
            else --ct;
            if(ct<0) return NG;
        }
    }
    return x;
}

int main(){
    vector<int> ans = solve();
    int n = ans.size();
    if(ans == NG) cout << "NO" << "\n";
    else{
        cout << "YES" << "\n";
        rep(i,n) cout << ans[i]+1 << " \n"[i==n-1];
    }
    return 0;
}