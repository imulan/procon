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

const int dx[4]={1,0,-1,0};
const int dy[4]={0,-1,0,1};

void solve(int m, int n){
    vector<string> a(n);
    vector<int> v(n);
    rep(i,n) cin >>a[i] >>v[i];

    auto IN = [&](int y, int x){
        return 0<=y && y<=m && 0<=x && x<=m;
    };

    int y=0, x=0, d=0;
    rep(i,n){
        if(a[i]=="MOVE"){
            x += v[i]*dx[d];
            y += v[i]*dy[d];
        }
        else{
            if(v[i]==0) (d+=3)%=4;
            else (d+=1)%=4;
        }
        if(!IN(y,x)){
            cout << -1 << endl;
            return;
        }
    }

    cout << x << " " << y << endl;
}

int main(){
    int m,n;
    while(cin >>m >>n) solve(m,n);
    return 0;
}
