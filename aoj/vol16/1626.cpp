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
    int b;
    while(cin >>b,b){
        int n=1, l=b;
        for(int i=2; i<=b; ++i){
            int p = b - (i-1)*i/2;
            if(p<=0) break;
            if(p%i==0){
                l = p/i;
                n = i;
            }
        }
        printf("%d %d\n",l,n);
    }
    return 0;
}
