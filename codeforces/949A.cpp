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

void solve(){
    string s;
    cin >>s;
    int n = s.size();

    set<int> r[2];
    rep(i,n){
        r[s[i]-'0'].insert(i);
    }

    vector<vector<int>> ans;
    while(!r[0].empty() || !r[1].empty()){
        vector<int> v;
        int idx = 0;
        int nx = 0;
        while(1){
            auto itr = r[nx].lower_bound(idx);
            if(itr == r[nx].end()) break;
            v.pb(*itr);
            idx = v.back();

            r[nx].erase(itr);
            nx = !nx;
        }

        if(nx == 0){
            cout << -1 << endl;
            return;
        }
        ans.pb(v);
    }

    rep(i,2)if(!r[i].empty()){
        cout << -1 << endl;
        return;
    }

    cout << ans.size() << endl;
    for(vector<int> v:ans){
        cout << v.size();
        for(int i:v) cout << " " << i+1;
        cout << endl;
    }
}

int main(){
    cin.tie(0);ios::sync_with_stdio(false);
    solve();
    return 0;
}
