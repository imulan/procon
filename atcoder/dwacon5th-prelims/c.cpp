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
    cin.tie(0);ios::sync_with_stdio(false);

    int n,Q;
    string s;
    cin >>n >>s >>Q;
    vector<int> x(Q);
    rep(i,Q) cin >>x[i];

    for(int k:x){
        ll ans = 0;

        ll num_m = 0;
        ll num_c = 0;

        ll c = 0;
        rep(i,k){
            if(s[i]=='M'){
                ++num_m;
            }
            else if(s[i]=='C'){
                ++num_c;
                c += num_m;
            }
        }

        rep(i,n){
            if(s[i]=='D'){
                ans += c;
            }

            if(s[i]=='M'){
                c -= num_c;
                --num_m;
            }
            else if(s[i]=='C'){
                --num_c;
            }

            if(i+k<n){
                if(s[i+k]=='M'){
                    ++num_m;
                }
                else if(s[i+k]=='C'){
                    ++num_c;
                    c += num_m;
                }
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
