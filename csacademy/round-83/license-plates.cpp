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

string p;
int n;

int ans = 0;

string s;
void dfs(int d){
    if(d==n){
        rep(i,n-1)if(s[i]==s[i+1]) return;
        ++ans;
        return;
    }

    if(p[d]=='d'){
        rep(i,10){
            s[d] = '0'+i;
            dfs(d+1);
            s[d] = p[d];
        }
    }
    else{
        rep(i,26){
            s[d] = 'a'+i;
            dfs(d+1);
            s[d] = p[d];
        }
    }
}

int main(){
    cin >>p;
    n = p.size();

    s = p;
    dfs(0);

    cout << ans << endl;
    return 0;
}
