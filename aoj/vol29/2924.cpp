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

bool solve(){
    int h,w,s,t;
    cin >>h >>w >>s >>t;

    if(h>w){
        swap(h,w);
        swap(s,t);
    }

    if(h==1) return t==1 || t==w;
    if(h%2==0 || w%2==0) return true;
    return (s+t)%2==0;
}

int main(){
    cout << (solve()?"Yes":"No") << endl;
    return 0;
}
