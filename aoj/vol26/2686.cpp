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
    int n,a,b;
    cin >>n >>a >>b;
    vector<int> s(n);
    rep(i,n) cin >>s[i];
    sort(all(s));

    bool win = true;
    if(a==b){
        int x = 0;
        rep(i,n){
            int g = s[i]%(a+1);
            x ^= g;
        }

        if(x == 0) win = false;
    }
    else{
        if(s[n-1] <= min(a,b)){
            int x = 0;
            rep(i,n) x ^= s[i];

            if(x == 0) win = false;
        }
        else{
            if(a < b){
                int ct = 0;
                rep(i,n) ct += (a < s[i]);
                if(ct>1) win = false;
                else{
                    assert(ct == 1);

                    int x = 0;
                    rep(i,n) x ^= s[i];

                    int nx = s[n-1]^x;
                    int need = s[n-1] - nx;

                    if( !(need<=a && nx<=a) ) win = false;
                }
            }
        }
    }

    cout << (win?"Hanako":"Jiro") << endl;
    return 0;
}
