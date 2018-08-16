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
    int n,k;
    cin >>n >>k;

    vector<string> s(4);
    rep(i,4) s[i] = string(n,'.');

    if(k%2==0){
        rep(i,k/2){
            s[1][i+1] = '#';
            s[2][i+1] = '#';
        }
    }
    else{
        if(k>n-2){
            rep(i,n-2) s[1][i+1] = '#';
            k-=n-2;
            s[2][1] = '#';
            --k;
            if(n-2!=1){
                s[2][n-2] = '#';
                --k;
            }

            for(int i=2; i<n-2; ++i){
                if(k<=0) break;
                s[2][i] = '#';
                --k;
            }
        }
        else rep(i,k) s[2][i + (n-k)/2] = '#';
    }

    cout << "YES" << endl;
    rep(i,4) cout << s[i] << endl;
    return 0;
}
