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

inline bool ok(const string &s){
    int S = s.size();
    if(S<2) return false;

    if((s[S-2]=='2'&&s[S-1]=='5') || (s[S-2]=='5'&&s[S-1]=='0') || (s[S-2]=='7'&&s[S-1]=='5') || (s[S-2]=='0'&&s[S-1]=='0')) return true;

    return false;
}

// 一番上の桁は動かさない
int calc(string s){
    // cout << "-------------CALC " << s << endl;
    int ret = 10101010;
    int n = s.size();

    for(string t:{"25","50","75","00"}){
        string pp = s;
        int ct = 0;

        for(int i=1; i>=0; --i){
            int idx = n-2+i;
            while(idx>0){
                if(pp[idx]==t[i]) break;
                --idx;
            }
            if(idx==0) break;

            for(int j=idx; j<n-2+i; ++j){
                ++ct;
                swap(pp[j],pp[j+1]);
            }
        }

        // cout << " END: " << pp << " : " << ct << endl;
        if(ok(pp)) ret = min(ret, ct);
    }

    return ret;
}

int solve(){
    string s;
    cin >>s;

    if(ok(s)) return 0;

    int S = s.size();
    if(S==1) return -1;
    if(S==2){
        swap(s[0],s[1]);
        if(ok(s)) return 1;
        else return -1;
    }

    int ct[10]={};
    rep(i,s.size()) ++ct[s[i]-'0'];

    if((ct[2]>0&&ct[5]>0) || (ct[5]>0&&ct[0]>0) || (ct[7]>0&&ct[5]>0) || (ct[0]>=2)){
        int ret = calc(s);

        for(int i=1; i<S; ++i){
            string t = s;
            int cost = 0;
            for(int j=i; j>0; --j){
                swap(t[j],t[j-1]);
                ++cost;
            }
            if(t[0]=='0') continue;

            ret = min(ret, calc(t) + cost);
        }

        return ret;
    }

    return -1;
}

int main(){
    cout << solve() << endl;
    return 0;
}
