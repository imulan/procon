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

using pi = pair<int,int>;

int main(){
    int n;
    cin >>n;
    vector<int> a(n);
    rep(i,n) cin >>a[i];

    set<pi> s;
    vector<pi> v;
    map<pi,int> seg2id;
    int start = 0;
    while(start<n){
        int i = 0;
        while(start+i<n && a[start]==a[start+i]) ++i;

        pi seg(-i,start);
        s.insert(seg);
        seg2id[seg] = v.size();
        v.pb(seg);
        start += i;
    }

    int V = v.size();
    vector<int> l(V,-1),r(V,-1);
    rep(i,V-1){
        l[i+1] = i;
        r[i] = i+1;
    }

    int ans = 0;
    while(!s.empty()){
        // dbg((vector<pi>(all(s))));
        ++ans;
        pi p = *s.begin();
        s.erase(p);
        int id = seg2id[p];

        if(l[id]!=-1) r[l[id]] = r[id];
        if(r[id]!=-1) l[r[id]] = l[id];

        if(l[id]!=-1 && r[id]!=-1){
            int lval = a[v[l[id]].se], rval = a[v[r[id]].se];
            if(lval == rval){
                pi newseg(v[l[id]].fi+v[r[id]].fi ,v[l[id]].se);
                s.erase(v[l[id]]);
                s.erase(v[r[id]]);
                s.insert(newseg);
                v[l[id]] = newseg;
                seg2id.erase(v[l[id]]);
                seg2id.erase(v[r[id]]);
                seg2id[newseg] = l[id];
                r[l[id]] = r[r[id]];
                if(r[r[id]]!=-1) l[r[r[id]]] = l[id];
            }
        }
    }
    cout << ans << endl;
    return 0;
}
