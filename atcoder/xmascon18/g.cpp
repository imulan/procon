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

int h,w;

void FS(int x){
    string s = "Second";
    if(x==1) s = "First";
    cout << s << endl;
}

void S(){
    while(1){
        int y,x;
        cin >>y >>x;
        if(y==-1 && x==-1) return;
        cout << h-1-y << " " << w-1-x << endl;
    }
}

void F(){
    cout << h-1 << " " << w-1 << endl;
    while(1){
        int y,x;
        cin >>y >>x;
        if(y==-1 && x==-1) return;

        int ay,ax;
        if(x%2==0){
            if(y==h-1){
                ax = x+1;
                ay = 0;
            }
            else{
                ax = x;
                if(y%2==0) ay = y+1;
                else ay = y-1;
            }
        }
        else{
            if(y==0){
                ay = h-1;
                ax = x-1;
            }
            else{
                ax = x;
                if(y%2==1) ay = y+1;
                else ay = y-1;
            }
        }
        cout << ay << " " << ax << endl;
    }
}

void solve(){
    cin >>h >>w;

    int fs = 0;
    if(h%2==1 && w%2==1) fs = 1;
    FS(fs);

    if(fs) F();
    else S();
}

int main(){
    int T;
    cin >>T;
    rep(tt,T){
        solve();
    }
    return 0;
}
