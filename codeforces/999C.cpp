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
    int n,k;
    string s;
    cin >>n >>k >>s;

    queue<int> pos[26];
    rep(i,n){
        pos[s[i]-'a'].push(i);
    }

    vector<bool> er(n);
    int idx = 0;
    while(k){
        while(idx<26 && pos[idx].empty()) ++idx;

        --k;
        int v = pos[idx].front();
        pos[idx].pop();
        er[v] = true;
    }

    rep(i,n)if(!er[i]) cout << s[i];
    cout << endl;
    return 0;
}
