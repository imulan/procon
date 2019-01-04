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

string solve(){
    string a,b;
    cin >>a >>b;
    int A = a.size(), B = b.size();

    rep(i,A-B+1){
        bool ok = true;
        rep(j,B){
            if(b[j]=='_') continue;
            if(a[i+j] != b[j]) ok = false;
        }
        if(ok) return "Yes";
    }
    return "No";
}

int main(){
    cout << solve() << endl;
    return 0;
}
