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

int main(){
    int n;
    cin >>n;

    bool ok = false;
    int k = 1;
    while(1){
        int v = k*(k-1)/2;
        if(v>=n){
            if(v == n) ok = true;
            break;
        }
        ++k;
    }

    if(ok){
        cout << "Yes" << endl;
        cout << k << endl;

        int val = 1;
        vector<vector<int>> ans(k);
        rep(i,k)for(int j=i+1; j<k; ++j){
            ans[i].pb(val);
            ans[j].pb(val);
            ++val;
        }

        rep(i,k){
            cout << ans[i].size();
            for(int j:ans[i]) cout << " " << j;
            cout << endl;
        }
    }
    else cout << "No" << endl;

    return 0;
}
