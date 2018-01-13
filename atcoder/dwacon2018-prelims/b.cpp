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

int solve(string s){
    int n = s.size();

    int ct = 0;
    rep(i,n){
        if(s[i]=='2') ++ct;
        else --ct;
    }
    if(ct!=0) return -1;

    int ans = 0;
    vector<bool> used(n);

    while(1){
        bool two = true;
        bool update = false;

        rep(i,n)if(!used[i]){
            if(two && s[i]=='2'){
                used[i]=true;
                two = !two;
                update = true;
            }
            else if(!two && s[i]=='5'){
                used[i]=true;
                two = !two;
                update = true;
            }
        }

        if(!two) return -1;
        if(!update) break;
        ++ans;
    }

    rep(i,n)if(!used[i]) return -1;
    return ans;
}

int main(){
    string s;
    cin >>s;
    cout << solve(s) << endl;
    return 0;
}
