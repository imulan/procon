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

const int A = 26;
int ct[A];

int main(){
    int n;
    string s;
    cin >>n >>s;

    for(int i=0; i<n; i+=2) ++ct[s[i]-'a'];

    int num[10]={};
    rep(i,A) ++num[ct[i]];

    int ans = 2*num[1];
    for(int i=2; i<10; ++i){
        if(num[i] == 0) continue;
        if(num[i] == 1){
            ans += 4;
            continue;
        }
        ans += 5+2*num[i]-1;
    }
    --ans;
    cout << ans << endl;
    return 0;
}
