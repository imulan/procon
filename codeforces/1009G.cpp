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

const string NG = "Impossible";

const int M = 1<<6;
int x[6]={};
int y[M]={};

bool Hall(){
    int ct[M];
    int sumy = 0;
    rep(i,1<<6){
        ct[i] = y[i];
        sumy += y[i];
    }

    // zeta
    rep(i,6)rep(mask,1<<6){
        if(mask>>i&1) ct[mask] += ct[mask^(1<<i)];
    }

    rep(mask,1<<6){
        int xx = 0;
        rep(i,6)if(mask>>i&1) xx += x[i];
        int tm = (~mask)&(M-1);
        if(xx > sumy-ct[tm]) return false;
    }
    return true;
}

string solve(){
    string s;
    int m;
    cin >>s >>m;

    int n = s.size();
    rep(i,n) ++x[s[i]-'a'];

    y[M-1] = n;
    vector<int> mm(n,M-1);
    rep(i,m){
        int pos;
        string t;
        cin >>pos >>t;
        --pos;

        int mask = 0;
        rep(j,t.size()) mask |= (1<<(t[j]-'a'));

        --y[M-1];
        ++y[mask];

        mm[pos] = mask;
    }

    string ans(n,' ');
    rep(i,n){
        bool found = false;
        rep(j,6)if(x[j]>0 && mm[i]>>j&1){
            --x[j];
            --y[mm[i]];

            if(Hall()){
                ans[i] = 'a'+j;
                found = true;
                break;
            }
            ++x[j];
            ++y[mm[i]];
        }
        if(!found) return NG;
    }
    return ans;
}

int main(){
    cin.tie(0);ios::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
