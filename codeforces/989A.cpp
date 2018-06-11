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
    string s;
    cin >>s;

    int n = s.size();
    rep(i,n-2){
        int ct[3]={};
        rep(j,3){
            if(s[i+j]!='.') ++ct[s[i+j]-'A'];
        }
        if(ct[0]==1 && ct[1]==1 && ct[2]==1) return "Yes";
    }

    return "No";
}

int main(){
    cout << solve() << endl;
    return 0;
}
