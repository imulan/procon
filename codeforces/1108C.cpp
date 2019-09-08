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
    int n;
    string s;
    cin >>n >>s;

    string c = "BGR";

    int ans = n+1;
    string t;
    do{
        int ct = 0;
        string tt = s;
        rep(i,n){
            tt[i] = c[i%3];
            if(s[i]!=c[i%3]) ++ct;
        }

        if(ct<ans){
            ans = ct;
            t = tt;
        }
    }while(next_permutation(all(c)));

    cout << ans << "\n";
    cout << t << "\n";
    return 0;
}
