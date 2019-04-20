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

bool wrong(string a, string b){
    int A = a.size(), B = b.size();

    int i=0, j=0;
    while(1){
        // printf(" %d %d\n",i+1,j+1);
        if(i>=A) return true;
        if(j>=B) return false;

        if(a[i]==b[j]){
            ++i;
            ++j;
            continue;
        }

        if(i==0){
            ++j;
            continue;
        }

        i=0;
    }
}

void solve(){
    string a;
    cin >>a;

    int n = a.size();
    int idx = 1;
    while(idx<n && a[idx] != a[0]) ++idx;

    string ans = a.substr(0,idx) + a;
    if(wrong(a,ans)) ans = "Impossible";
    cout << ans << endl;
}

int main(){
    int T;
    cin >>T;
    rep(i,T){
        printf("Case #%d: ", i+1);
        solve();
    }
    return 0;
}
