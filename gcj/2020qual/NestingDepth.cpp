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

string solve(){
    string s;
    cin >>s;

    string ans = "";
    int d = 0;
    for(char c:s){
        int x = c-'0';

        while(d < x){
            ans += '(';
            ++d;
        }
        while(d > x){
            ans += ')';
            --d;
        }
        ans += c;
    }
    while(d > 0){
        ans += ')';
        --d;
    }

    return ans;
}

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    int T;
    cin >>T;
    rep(i,T) cout << "Case #" << i+1 << ": " << solve() << "\n";
    return 0;
}
