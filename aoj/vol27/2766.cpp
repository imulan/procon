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
    int n,d;
    string x;
    cin >>n >>x >>d;

    string s(n,' ');
    rep(i,n){
        int rem = n-1-i;
        if(x[i]=='1'){
            if(d<=rem) s[i] = '1';
            else{
                s[i] = '0';
                --d;
            }
        }
        else{
            if(d>0){
                s[i] = '1';
                --d;
            }
            else s[i] = '0';
        }
    }
    cout << s << endl;
    return 0;
}
