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
    int k;
    string n;
    cin >>k >>n;

    int ct[10]={};
    int s = 0;
    rep(i,n.size()){
        int d = n[i]-'0';
        ++ct[d];
        s += d;
    }

    int ans = 0;
    while(s<k){
        ++ans;
        rep(i,10){
            if(ct[i]>0){
                --ct[i];
                s += 9-i;
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
