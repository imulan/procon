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

int query(const vector<int> &v){
    int V = v.size();
    printf("? %d", V);
    rep(i,V) printf(" %d",v[i]);
    printf("\n");
    fflush(stdout);

    int ret;
    scanf(" %d", &ret);

    assert(ret!=-1);
    return ret;
}

int find_one(int n, int x, int y, const vector<int> &q){
    int Q = q.size();
    int l=-1, r=Q-1;
    while(r-l>1){
        int m=(l+r)/2;

        vector<int> ask;
        rep(i,m+1) ask.pb(q[i]);

        if(ask.size()==0) l=m;
        else{
            int res = query(ask);
            if(res==y || res==(x^y)) r=m;
            else l=m;
        }
    }
    return q[l+1];
}

int main(){
    int n,x,y;
    scanf(" %d %d %d", &n, &x, &y);

    bool diff[10]={};
    rep(i,10){
        vector<int> q;
        for(int j=1; j<=n; ++j){
            if(!(j>>i&1)) q.pb(j);
        }

        int res = query(q);
        if(res==y || res==(x^y)) diff[i]=true;
    }

    int p1=0,p2=0;
    rep(i,10){
        if(diff[i]){
            vector<int> q;
            for(int j=1; j<=n; ++j){
                if(!(j>>i&1)) q.pb(j);
            }
            p1 = find_one(n,x,y,q);
            break;
        }
    }

    rep(i,10){
        int d = (p1>>i)&1;
        if(diff[i]) d = !d;
        p2 |= (d<<i);
    }

    printf("! %d %d\n", min(p1,p2), max(p1,p2));
    fflush(stdout);
    return 0;
}
