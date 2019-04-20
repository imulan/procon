#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0; (i)<(int)(n); ++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

using pi = pair<int,int>;
using q = pair<char,pi>;

const int INF = 19191919;

struct SegTree{
    int n;
    vector<int> mx,mn;
    SegTree(){}
    SegTree(int _n){
        n = 1;
        while(n<_n) n*=2;
        mx = vector<int>(2*n-1, -INF);
        mn = vector<int>(2*n-1, INF);
    }

    void update(int k, int a){
        k += n-1;
        mx[k] = a;
        mn[k] = a;
        while(k>0){
            k = (k-1)/2;
            mx[k] = max(mx[2*k+1], mx[2*k+2]);
            mn[k] = min(mn[2*k+1], mn[2*k+2]);
        }
    }
    
    int _MIN(int a, int b, int k, int l, int r){
        if(r<=a || b<=l) return INF;
        if(a<=l && r<=b) return mn[k];
        int vl = _MIN(a,b,2*k+1,l,(l+r)/2);
        int vr = _MIN(a,b,2*k+2,(l+r)/2,r);
        return min(vl,vr);
    }
    int MIN(int a, int b){
        return _MIN(a,b,0,0,n);
    }
    
    int _MAX(int a, int b, int k, int l, int r){
        if(r<=a || b<=l) return -INF;
        if(a<=l && r<=b) return mx[k];
        int vl = _MAX(a,b,2*k+1,l,(l+r)/2);
        int vr = _MAX(a,b,2*k+2,(l+r)/2,r);
        return max(vl,vr);
    }
    int MAX(int a, int b){
        return _MAX(a,b,0,0,n);
    }

};

const int N = 100010;
int n;
int a[N],b[N];
SegTree st;

int num;
vector<q> add;

// [l,r)
void check(int l, int r, int val){
    bool all_ok = true;
    for(int i=l; i<r; ++i)if(val!=a[i]) all_ok = false;       
    if(all_ok){
        num = 0;
        return;
    }
    
    if(st.MIN(l,r) == val){
        num = 1;
        add.pb({'m',{l+1,r}});
        return;
    }
    if(st.MAX(l,r) == val){
        num = 1;
        add.pb({'M',{l+1,r}});
        return;
    }
    
    // num = 2
    if(a[l]==val){
        num = 2;
        
        int mv = st.MIN(l+1,r);
        add.pb({'m',{l+2,r}});
        if(mv<val){
            add.pb({'M',{l+1,r}});
        }
        else{
            add.pb({'m',{l+1,r}});
        }
        return;
    }
    
    if(a[r-1]==val){
        num = 2;
        
        int mv = st.MIN(l,r-1);
        add.pb({'m',{l+1,r-1}});
        if(mv<val){
            add.pb({'M',{l+1,r}});
        }
        else{
            add.pb({'m',{l+1,r}});
        }
        return;
    }
    
    if(r-l == 3 && a[l+1] == val){
        num = 2;
        if(a[l]<=a[l+1] && a[l+1]<=a[l+2]){
            add.pb({'m',{l+2,l+3}});
            add.pb({'M',{l+1,l+3}});
        }
        else{
            add.pb({'M',{l+2,l+3}});
            add.pb({'m',{l+1,l+3}});
        }
        return;
    }
        
    for(int i=l+1; i<r-1; ++i)if(a[i]==val){
        if(st.MIN(l,i)>=val && st.MAX(i+1,r)>=val){
            num = 2;
            add.pb({'M',{i+2,r}});
            add.pb({'m',{l+1,r}}); 
            return;   
        }
        if(st.MAX(l,i)<=val && st.MIN(i+1,r)<=val){
            num = 2;
            add.pb({'m',{i+2,r}});
            add.pb({'M',{l+1,r}}); 
            return;   
        }
        if(st.MAX(l,i)>=val && st.MIN(i+1,r)>=val){
            num = 2;
            add.pb({'M',{l+1,i}});
            add.pb({'m',{l+1,r}}); 
            return;   
        }
        if(st.MIN(l,i)<=val && st.MAX(i+1,r)<=val){
            num = 2;
            add.pb({'m',{l+1,i}});
            add.pb({'M',{l+1,r}}); 
            return;   
        }
    }
    
    // num = 3
    if(r-l>3){
        if(a[l+1] == val){
            rep(ii,2){
                char cc = 'm';
                int mv = st.MIN(l+2,r);
                if(ii){
                    mv = st.MAX(l+2,r);
                    cc = 'M';
                }        
                
                if(a[l]<=a[l+1] && a[l+1]<=mv){
                    num = 3;
                    add.pb({cc,{l+3,r}});
                    add.pb({'m',{l+2,r}});
                    add.pb({'M',{l+1,r}});
                    return;
                }
                if(a[l]>=a[l+1] && a[l+1]>=mv){
                    num = 3;
                    add.pb({cc,{l+3,r}});
                    add.pb({'M',{l+2,r}});
                    add.pb({'m',{l+1,r}});
                    return;
                }
            }
        }
        if(a[r-2] == val){
            rep(ii,2){
                char cc = 'm';
                int mv = st.MIN(l,r-2);
                if(ii){
                    mv = st.MAX(l,r-2);
                    cc = 'M';
                }        
                
                if(mv<=a[r-2] && a[r-2]<=a[r-1]){
                    num = 3;
                    add.pb({cc,{l+1,r-2}});
                    add.pb({'m',{r-1,r}});
                    add.pb({'M',{l+1,r}});
                    return;
                }
                if(mv>=a[r-2] && a[r-2]>=a[r-1]){
                    num = 3;
                    add.pb({cc,{l+1,r-2}});
                    add.pb({'M',{r-1,r}});
                    add.pb({'m',{l+1,r}});
                    return;
                }
            }
        }
    }
        
    for(int i=l+2; i<r-2; ++i)if(a[i]==val){
        if(st.MIN(l,i)<=val && st.MIN(i+1,r)<=val){
            num = 3;
            add.pb({'m',{l+1,i}});        
            add.pb({'m',{i+2,r}});        
            add.pb({'M',{l+1,r}});        
            return;
        }
        if(st.MAX(l,i)>=val && st.MAX(i+1,r)>=val){
            num = 3;
            add.pb({'M',{l+1,i}});        
            add.pb({'M',{i+2,r}});        
            add.pb({'m',{l+1,r}});        
            return;
        }
    }
        
    // num = 4
    for(int i=l+1; i<r-1; ++i)if(a[i]==val){
        rep(_l,2)rep(_r,2){
            int lv = st.MIN(l,i);
            if(_l) lv = st.MAX(l,i);
            int rv = st.MIN(i+1,r);
            if(_r) rv = st.MAX(i+1,r);
            
            if(lv<=val && val<=rv){
                num = 4;
 
                char cc = 'm';
                if(_l) cc = 'M';
                add.pb({cc,{l+1,i}});
 
                cc = 'm';
                if(_r) cc = 'M';
                add.pb({cc,{i+2,r}});
                
                add.pb({'m',{i+1,r}});
                add.pb({'M',{l+1,r}});
 
                return;
            }
            if(lv>=val && val>=rv){
                num = 4;

                char cc = 'm';
                if(_l) cc = 'M';
                add.pb({cc,{l+1,i}});
 
                cc = 'm';
                if(_r) cc = 'M';
                add.pb({cc,{i+2,r}});
                
                add.pb({'M',{i+1,r}});
                add.pb({'m',{l+1,r}});
                return;
            }
        }
    }
}

void solve(){
    scanf(" %d", &n);
    rep(i,n) scanf(" %d", &a[i]);
    rep(i,n) scanf(" %d", &b[i]);
    
    st = SegTree(n);
    rep(i,n){
        st.update(i,a[i]);
    }    
    
    vector<q> ans;
    int s=0;
    while(s<n){
        int v = b[s];
        int e = s;
        while(e<n && b[e]==v) ++e;
                
        num = INF;
        add.clear();
        check(s,e,v);
        
        if(num == INF){
            printf("-1\n");
            return;
        }
        for(const auto &aa:add) ans.pb(aa);
        
        s = e;
    }
    
    int sz = ans.size();
    printf("%d\n", sz);
    rep(i,sz){
        printf("%c %d %d\n", ans[i].fi, ans[i].se.fi, ans[i].se.se);
    }
}

int main(){
    solve();    
    return 0;
}
