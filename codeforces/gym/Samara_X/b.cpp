#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define pb push_back

using pi = pair<int,int>;

const string h = "happiness";

pi solve(){
    string s;
    cin >>s;

    int n = s.size();
    vector<int> pos;
    rep(i,n-8){
        string t = s.substr(i,9);
        if(t==h) pos.pb(i);
    }

    if(pos.size()>=3) return {-1,-1};
    if(pos.size()==2) return {pos[0],pos[1]+1};
    if(pos.size()==1) return {pos[0],pos[0]+1};

    for(int i=1; i<n; ++i){
        swap(s[0],s[i]);

        bool f = true;
        rep(j,n-8){
            string t = s.substr(j,9);
            if(t==h){
                f = false;
                break;
            }
        }
        if(f) return {0,i};
        swap(s[0],s[i]);
    }
    return {0,1};
}

int main(){
    pi a = solve();
    if(a.fi == -1) cout << "NO" << "\n";
    else{
        cout << "YES" << "\n";
        cout << a.fi+1 << " " << a.se+1 << "\n";
    }
    return 0;
}