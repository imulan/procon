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

using C = pair<int,char>;

C READ(){
    string s;
    cin >>s;

    int v = s[0]-'0';
    if(s[0]=='T') v = 10;
    else if(s[0]=='J') v = 11;
    else if(s[0]=='Q') v = 12;
    else if(s[0]=='K') v = 13;
    else if(s[0]=='A') v = 14;
    v -= 2;

    return {v,s[1]};
}

const int INF = 1919191;

int LIS(const vector<int> &v){
    int n = v.size();
    vector<int> dp(n+1,INF);

    rep(i,n){
        int idx = lower_bound(all(dp), v[i]) - dp.begin();
        dp[idx] = v[i];
    }

    for(int i=n; i>=0; --i)if(dp[i]<INF) return i+1;
    return -1;
}

int main(){
    int n;
    cin >>n;

    vector<C> c(n);
    rep(i,n) c[i] = READ();

    string suit = "shdc";
    sort(all(suit));

    int ans = n;
    do{
        auto CV = [&](C card, int mask){
            int ret = card.fi;
            rep(i,4)if(card.se == suit[i]){
                if(mask>>i&1) ret = 12-card.fi;
                ret += 13*i;
            }
            return ret;
        };

        rep(mask,1<<4){
            vector<int> v(n);
            rep(i,n) v[i] = CV(c[i],mask);

            ans = min(ans, n-LIS(v));
        }
    }while(next_permutation(all(suit)));

    cout << ans << endl;
    return 0;
}
