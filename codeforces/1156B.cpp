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

const int A = 26;

string solve(){
    string s;
    cin >>s;

    vector<int> ct(A);
    for(char c:s) ++ct[c-'a'];

    int p[2] = {};
    rep(i,A) p[i%2] += ct[i];
    if(p[0] == 0 || p[1] == 0) return s;

    for(int i=0; i<A; i+=2)for(int j=1; j<A; j+=2){
        if(abs(i-j)==1) continue;
        if(ct[i]>0 && ct[j]>0){
            string ans = "";

            --ct[i];
            for(int k=0; k<A; k+=2)rep(l,ct[k]) ans += 'a'+k;
            ans += 'a'+i;

            --ct[j];
            ans += 'a'+j;
            for(int k=1; k<A; k+=2)rep(l,ct[k]) ans += 'a'+k;

            return ans;
        }
    }

    return "No answer";
}

int main(){
    int T;
    cin >>T;
    while(T--) cout << solve() << "\n";
    return 0;
}
