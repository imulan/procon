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

bool is_suffix(string a, string b){
    int A = a.size(), B = b.size();
    if(A>B) return false;

    rep(i,A)if(a[A-1-i]!=b[B-1-i]) return false;
    return true;
}

int main(){
    int n;
    cin >>n;

    map<string,vector<string>> m;
    rep(i,n){
        string name;
        int sz;
        cin >>name >>sz;
        rep(j,sz){
            string num;
            cin >>num;
            m[name].pb(num);
        }
    }

    cout << m.size() << endl;
    for(const auto &p:m){
        vector<string> d = p.se;
        sort(all(d));
        d.erase(unique(all(d)),d.end());
        int D = d.size();

        vector<string> ans;
        rep(i,D){
            bool ok = true;
            rep(j,D)if(j!=i){
                if(is_suffix(d[i],d[j])) ok = false;
            }
            if(ok) ans.pb(d[i]);
        }
        cout << p.fi << " " << ans.size();
        for(string a:ans) cout << " " << a;
        cout << "\n";
    }

    return 0;
}
