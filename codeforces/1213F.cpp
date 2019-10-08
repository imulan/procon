#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
#define dbg(x) cout<<#x" = "<<((x))<<endl
template<class T,class U> ostream& operator<<(ostream& o, const pair<T,U> &p){o<<"("<<p.fi<<","<<p.se<<")";return o;}
template<class T> ostream& operator<<(ostream& o, const vector<T> &v){o<<"[";for(T t:v){o<<t<<",";}o<<"]";return o;}

int main(){
    int n,k;
    cin >>n >>k;

    vector<int> p(n),q(n);
    rep(i,n){
        cin >>p[i];
        --p[i];
    }
    rep(i,n){
        cin >>q[i];
        --q[i];
    }

    vector<int> b;
    int s = 0;
    while(s<n){
        int i = s;
        set<int> P,Q;
        while(i<n){
            if(p[i] != q[i]){
                P.insert(p[i]);
                Q.insert(q[i]);
                if(Q.count(p[i])) P.erase(p[i]);
                if(P.count(q[i])) P.erase(q[i]);
            }

            // dbg(i);
            // for(int x:P) cout << x+1 << " ";
            // cout << "\n";

            ++i;
            if(P.empty()) break;
        }

        b.pb(i);
        s = i;
    }

    int B = b.size();
    if(B>=k){
        string ans(n,'?');
        int pre = 0;
        rep(i,B){
            char c = 'a' + min(i,k-1);
            for(int j=pre; j<b[i]; ++j) ans[p[j]] = c;
            pre = b[i];
        }

        cout << "YES\n";
        cout << ans << "\n";
    }
    else cout << "NO\n";
    return 0;
}
