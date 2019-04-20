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

const int N = 26;
bool bs[N],bt[N];
bool uni[N],com[N];

int main(){
    string s,t;
    cin >>s >>t;

    for(char c:s) bs[c-'A'] = true;
    for(char c:t) bt[c-'A'] = true;

    rep(i,N){
        uni[i] = bs[i]^bt[i];
    }

    auto CT = [&](string x, int a){
        char f = 'A'+a;

        int ret = 0;
        for(char c:x) ret += (c==f);
        return ret;
    };

    int ans = 0;
    rep(i,N){
        ans += max(CT(s,i), CT(t,i));
    }
    if(uni[s[0]-'A'] || uni[t[0]-'A']) ++ans;
    cout << ans << endl;
    return 0;
}
