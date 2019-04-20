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

int main(){
    int n;
    cin >>n;
    while(n--){
        string s;
        cin >>s;

        int ct[A]={};
        for(char c:s) ++ct[c-'a'];

        auto check = [&](){
            rep(l,A)for(int r=l; r<A; ++r){
                bool t = true;
                rep(i,A){
                    if(l<=i && i<=r){
                        if(ct[i]!=1) t = false;
                    }
                    else{
                        if(ct[i]!=0) t = false;
                    }
                }
                if(t) return true;
            }
            return false;
        };

        cout << (check()?"Yes":"No") << '\n';
    }
    return 0;
}
