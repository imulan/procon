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

bool pal(string s){
    int n = s.size();
    rep(i,n)if(s[i]!=s[n-1-i]) return false;
    return true;
}

bool solve(string s){
    int n = s.size();
    rep(i,n){
        for(int L=1; L<=n-i; ++L){
            if(pal(s.substr(i,L))){
                if(L%2==0) return false;
            }
        }
    }
    return true;
}

int main(){
    string s;
    cin >>s;
    cout << (solve(s)?"Odd.":"Or not.") << endl;
    return 0;
}
