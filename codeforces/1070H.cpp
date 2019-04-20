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
    cin.tie(0);ios::sync_with_stdio(false);

    int n;
    cin >>n;

    map<string, set<int>> m;

    vector<string> sss(n);
    rep(i,n){
        string s;
        cin >>s;
        sss[i] = s;

        int S = s.size();
        rep(j,S){
            string tt = "";
            for(int k=j; k<S; ++k){
                tt += s[k];
                m[tt].insert(i);
            }
        }
    }

    int q;
    cin >>q;
    rep(i,q){
        string s;
        cin >>s;

        int ans = m[s].size();

        string tt = "-";
        if(ans>0) tt = sss[*m[s].begin()];
        cout << ans << " " << tt << "\n";
    }
    return 0;
}
