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

inline char cv(int x){
    if(x<26) return 'A'+x;
    return 'a'+x-26;
}

inline int ID(char c){
    if(isupper(c)) return c-'A';
    return c-'a'+26;
}

const int INF = 1234567;

int main(){
    int n;
    cin >>n;
    vector<string> a(n);
    rep(i,n) cin >>a[i];

    vector<vector<int>> lpos(n,vector<int>(52,INF));
    vector<vector<int>> rpos(n,vector<int>(52,-INF));
    rep(i,n){
        rep(j,a[i].size()){
            int idx = ID(a[i][j]);
            lpos[i][idx] = min(lpos[i][idx],j);
            rpos[i][idx] = max(rpos[i][idx],j);
        }
    }

    int mx = 0;
    string ans = "zzz";

    rep(head,52)rep(tail,52){
        char h = cv(head), t = cv(tail);

        int ct[52]={};
        rep(i,n){
            int A = a[i].size();
            int l = lpos[i][head];
            int r = rpos[i][tail];
            if(r<=l) continue;

            ll ap=0;
            for(int j=l+1; j<r; ++j){
                int idx = ID(a[i][j]);
                if(!(ap>>idx&1)){
                    ap |= (1LL<<idx);
                    ++ct[idx];
                }
            }
        }

        int tmx = 0;
        rep(i,52) tmx = max(tmx, ct[i]);
        char m;
        rep(i,52){
            if(ct[i]==tmx){
                m = cv(i);
                break;
            }
        }

        string cand = "";
        cand += h;
        cand += m;
        cand += t;

        if(mx < tmx){
            mx = tmx;
            ans = cand;
        }
        else if(mx == tmx){
            ans = min(ans,cand);
        }
    }

    cout << ans << endl;
    return 0;
}
