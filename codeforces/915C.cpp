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

string make_min(vector<int> ct){
    string ret = "";
    for(int i=1; i<=9; ++i){
        if(ct[i]>0){
            --ct[i];
            ret += '0'+i;
            break;
        }
    }

    rep(i,10){
        rep(j,ct[i]) ret += '0'+i;
    }

    return ret;
}

string make_max(vector<int> ct){
    string ret = "";
    for(int i=9; i>=0; --i){
        rep(j,ct[i]) ret += '0'+i;
    }
    return ret;
}

// 先頭からpre文字は一致させる
string f(vector<int> ca, vector<int> cb, int pre, string b){
    int n = b.size();

    string ret = "";
    rep(i,pre){
        int v = b[i]-'0';
        --cb[v];

        if(ca[v]==0) return "#";
        --ca[v];
        ret += b[i];
    }

    if(pre!=n){
        int v = b[pre]-'0';
        bool found = false;
        for(int i=v-1; i>=0; --i){
            if(ca[i]>0){
                --ca[i];
                found = true;
                ret += '0'+i;
                break;
            }
        }
        if(!found) return "#";

        ret += make_max(ca);
    }

    return ret;
}

string solve(){
    string a,b;
    cin >>a >>b;
    int A = a.size(), B = b.size();

    vector<int> ca(10), cb(10);
    rep(i,A) ++ca[a[i]-'0'];
    rep(i,B) ++cb[b[i]-'0'];

    if(A<B) return make_max(ca);

    assert(A==B);

    string ans = make_min(ca);
    rep(i,A+1){
        string t = f(ca,cb,i,b);
        if(t!="#") ans = max(ans,t);
    }
    return ans;
}

int main(){
    cout << solve() << endl;
    return 0;
}
