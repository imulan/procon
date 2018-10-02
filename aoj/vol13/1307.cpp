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

int n,sz;

const int N = 401;
int ct[N];
int R;
vector<int> pos;
vector<vector<int>> ans;
void dfs(int num, int idx){
    if(num == n){
        vector<int> sp(pos);
        sort(all(sp));

        vector<int> tmp;
        rep(i,n-1) tmp.pb(sp[i+1]-sp[i]);
        ans.pb(tmp);
        return;
    }

    while(idx>0 && ct[idx]==0) --idx;
    if(ct[idx]==0) return;


    for(int p:{idx,R-idx}){
        bool find_neg = false;
        for(int i:pos){
            int f = abs(i-p);
            --ct[f];
            if(ct[f]<0) find_neg = true;
        }

        if(!find_neg){
            pos.pb(p);
            dfs(num+1, idx);
            pos.pop_back();
        }

        for(int i:pos){
            int f = abs(i-p);
            ++ct[f];
        }
    }
}

int main(){
    while(cin >>n,n){
        memset(ct,0,sizeof(ct));

        sz = n*(n-1)/2;
        vector<int> d(sz);
        rep(i,sz){
            cin >>d[i];
            ++ct[d[i]];
        }

        pos.clear();
        pos.pb(0);
        pos.pb(d[0]);

        --ct[d[0]];
        R = d[0];

        ans.clear();
        dfs(2,d[0]);
        sort(all(ans));
        ans.erase(unique(all(ans)), ans.end());

        for(const vector<int> &v:ans){
            rep(i,n-1) cout << v[i] << " \n"[i==n-2];
        }
        cout << "-----\n";
    }
    return 0;
}
