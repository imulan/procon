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

int solve(){
    int n;
    cin >>n;

    vector<string> s(n);
    vector<string> us[55];
    map<string,vector<int>> m;
    rep(i,n){
        cin >>s[i];

        int sz = s[i].size();
        rep(j,sz){
            string t = s[i].substr(j);
            int tt = t.size();
            us[tt].pb(t);
            m[t].pb(i);
        }
    }

    vector<bool> used(n);
    for(int i=50; i>0; --i){
        sort(all(us[i]));
        us[i].erase( unique(all(us[i])), us[i].end());

        for(const auto &ss:us[i]){
            vector<int> v;
            for(int j:m[ss]){
                if(!used[j]) v.pb(j);
            }

            int V = v.size();
            if(V>=2){
                used[v[0]] = true;
                used[v[1]] = true;
            }
        }
    }

    int ans = 0;
    rep(i,n)if(used[i]) ++ans;
    return ans;
}

int main(){
    int T;
    cin >>T;
    rep(i,T){
        printf("Case #%d: %d\n", i+1, solve());
    }
    return 0;
}
