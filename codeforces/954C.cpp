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
    int n;
    cin >>n;
    vector<int> a(n);
    rep(i,n){
        cin >>a[i];
        --a[i];
    }

    bool ok = true;
    int y = -1;

    rep(i,n-1){
        int d = abs(a[i]-a[i+1]);
        if(d==0) ok = false;
        else if(d!=1){
            if(y==-1) y = d;
            else{
                if(y!=d) ok = false;
            }
        }
    }

    if(ok){
        if(y==-1) y = 1000000000;

        rep(i,n-1){
            int d = abs(a[i]-a[i+1]);
            if(d==1){
                int ux = a[i]/y,uy = a[i]%y;
                int vx = a[i+1]/y, vy = a[i+1]%y;
                if(abs(ux-vx)+abs(uy-vy)!=1) ok = false;
            }
        }
    }

    if(ok){
        cout << "YES" << endl;
        cout << "1000000000 " << y << endl;
    }
    else cout << "NO" << endl;
    return 0;
}
