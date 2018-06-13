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

const ll mod = 1000000007;
const ll LIM = 33;

string delsp(string s){
    string t = "";
    for(char c:s)if(c!=' ') t+=c;
    return t;
}

string s;
int n;
map<int,vector<int>> pos;

ll E(int &idx, int dep, int RR);
ll T(int &idx, int dep, int RR);

inline ll sq(ll x){
    return (x*x)%mod;
}

ll N(int &idx){
    ll ret = 0;
    while(idx<n && isdigit(s[idx])){
        ret = ret*10 + (s[idx]-'0');
        ret %= mod;
        ++idx;
    }
    return ret;
}

ll E(int &idx, int dep, int RR){
    if(pos[dep].empty()){
        return T(idx,dep,RR);
    }
    else{
        auto itr = lower_bound(all(pos[dep]), RR);
        if(itr != pos[dep].begin()){
            --itr;
            int rx = *itr;
            if(idx < rx){
                ll L = E(idx,dep,rx-1);
                assert(idx == rx);
                idx += 2;
                ll R = T(idx,dep,RR);

                if(R>LIM) return 0;
                else return L>>R;
            }
            else return T(idx,dep,RR);
        }
        else return T(idx,dep,RR);
    }
}

ll T(int &idx, int dep, int RR){
    if(isdigit(s[idx])){
        return N(idx);
    }
    else if(s[idx]=='S'){
        ++idx;
        assert(s[idx]=='<');
        ++idx;
        ll v = sq(E(idx,dep+1,RR));
        assert(s[idx]=='>');
        ++idx;
        return v;
    }
    else assert(false);
}

int main(){
    while(getline(cin,s),(s!="#")){
        pos.clear();

        s = delsp(s);

        n = s.size();
        int idx = n-1;
        while(idx>0){
            if(idx>0 && idx<n-1 && s[idx]=='>' && s[idx-1]=='>'){
                if(s[idx+1]=='S' || isdigit(s[idx+1])){
                    s[idx-1] = 'x';
                    s[idx] = 'x';
                }
            }
            --idx;
        }

        n = s.size();

        int d = 0;
        idx = 0;
        while(idx<n){
            if(s[idx]=='x'){
                pos[d].pb(idx);
                idx += 2;
            }
            else{
                if(s[idx]=='S') ++d;
                else if(s[idx]=='>') --d;

                ++idx;
            }
        }

        idx = 0;
        cout << E(idx,0,n) << endl;
    }
    return 0;
}
