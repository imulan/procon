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

string f(const vector<int> &ct){
    string ret = "";
    rep(i,3)rep(j,ct[i]) ret += ('0'+i);
    return ret;
}

int main(){
    string s;
    cin >>s;
    int n = s.size();

    string ans = "";
    int idx = n;
    bool two = false;
    vector<int> ct(3);

    rep(i,n){
        if(two && s[i]=='0'){
            idx = i;
            break;
        }
        ++ct[s[i]-'0'];
        if(s[i]=='2') two = true;
    }

    ct[1] = 0;
    rep(i,n) ct[1] += (s[i]=='1');

    rep(i,3)rep(j,ct[i]) ans += ('0'+i);
    for(int i=idx; i<n; ++i){
        if(s[i]!='1') ans += s[i];
    }

    cout << ans << endl;
    return 0;
}
