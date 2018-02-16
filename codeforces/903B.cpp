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

int main(){
    int h1,a1,c1;
    cin >>h1 >>a1 >>c1;
    int h2,a2;
    cin >>h2 >>a2;

    vector<string> ans;
    while(h2>0){
        if(h1 - a2 > 0 || h2 - a1 <= 0){
            ans.pb("STRIKE");
            h2 -= a1;
        }
        else{
            ans.pb("HEAL");
            h1 += c1;
        }
        h1 -= a2;
    }

    cout << ans.size() << endl;
    for(string s:ans) cout << s << endl;
    return 0;
}
