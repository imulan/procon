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

int f(char c){
    if(c=='R') return 1;
    return 3;
}

int main(){
    string x;
    cin >>x;
    int n = x.size();

    int ans = 0;
    int dir = 0;
    int s = 0;

    while(s<n){
        int e = s;
        int ct[4]={};
        while(e<n){
            (dir += f(x[e])) %= 4;
            if(x[e]=='R') ++ct[dir];
            ++e;
            if(dir==0) break;
        }
        s = e;

        int add = 1;
        rep(i,4)if(ct[i]==0) add = 0;
        ans += add;
    }
    cout << ans << endl;
    return 0;
}
