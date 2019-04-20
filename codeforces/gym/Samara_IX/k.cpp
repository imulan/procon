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

int solve(){
    string s;
    cin >>s;
    int n = s.size();

    bool is_p = true;
    rep(i,n)if(s[i] != s[n-1-i]) is_p = false;
    if(is_p) return n/2 + 1;

    // 前半分固定
    string t = s.substr(0,(n+1)/2);
    int T = t.size();

    int sidx = -1;
    bool skip = false;
    int idx = n-1;
    rep(i,T){
        if(s[idx] != t[i]){
            if(skip){
                sidx = -1;
                break;
            }

            sidx = idx;
            skip = true;
            --i;
        }

        --idx;
    }
    if(sidx != -1) return sidx+1;

    // 後ろ半分固定
    t = s.substr(n/2);
    reverse(all(t));
    T = t.size();

    sidx = -1;
    skip = false;
    idx = 0;
    rep(i,T){
        if(s[idx] != t[i]){
            if(skip){
                sidx = -1;
                break;
            }

            sidx = idx;
            skip = true;
            --i;
        }
        ++idx;
    }
    if(sidx != -1) return sidx+1;

    return -1;
}

int main(){
    int a = solve();
    if(a == -1) cout << "NO" << "\n";
    else cout << "YES\n" << a << "\n";
    return 0;
}
