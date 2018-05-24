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

struct SegTree{
    int n; vector<int> dat;
    //初期化
    SegTree(int _n){
        n=1;
        while(n<_n) n*=2;
        dat=vector<int>(2*n-1,0);
    }

    void add(int k, int a){
        k+=n-1;
        dat[k] += a;
        //更新
        while(k>0){
            k=(k-1)/2;
            dat[k]=dat[2*k+1]+dat[2*k+2];
        }
    }

    int _query(int a, int b, int k, int l, int r){
        if(r<=a || b<=l) return 0;
        if(a<=l && r<=b) return dat[k];

        int vl=_query(a,b,2*k+1,l,(l+r)/2);
        int vr=_query(a,b,2*k+2,(l+r)/2,r);
        return vl+vr;
    }
    //[a,b)
    int query(int a, int b){
        return _query(a,b,0,0,n);
    }
};

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

template<class Key>
using ordered_set = __gnu_pbds::tree<Key, __gnu_pbds::null_type, less<Key>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

const int N = 100010;

ordered_set<int> R[N];

const string YES = " is working hard now.", NO = " is not working now.";
inline void PRINT(string name, bool b){
    cout << name << (b?YES:NO) << "\n";
}

int main(){
    cin.tie(0);ios::sync_with_stdio(false);

    SegTree st(N);

    int n;
    cin >>n;

    map<string,int> rank, motivation;
    map<int,string> rank2name;

    vector<string> s(n);
    vector<int> a(n);
    rep(i,n) cin >>s[i] >>a[i];

    rep(i,n){
        rank[s[i]] = n-i;
        motivation[s[i]] = a[i];
        rank2name[n-i] = s[i];
        R[a[i]].insert(rank[s[i]]);
        st.add(a[i],1);
    }

    auto find_R = [&](int num){
        int l=0, r=N-1;
        while(r-l>1){
            int m = (l+r)/2;
            if(st.query(m,N) >= num) l=m;
            else r=m;
        }
        return l;
    };

    int p = n;

    int m;
    cin >>m;
    rep(i,m){
        char pm;
        string t;
        cin >>pm >>t;

        if(pm == '+'){
            int b;
            cin >>b;

            int np = p+1;

            rank[t] = -i;
            motivation[t] = b;
            rank2name[-i] = t;

            // 新しく加わる人が上から何番目か
            int up = st.query(b+1,N)+1;
            PRINT(t, up<=np/5);

            if(up<=np/5){
                // work -> not work
                if(p/5 == np/5){
                    int idx = find_R(np/5);
                    int ord = np/5 - st.query(idx+1,N) - 1;
                    PRINT(rank2name[ *R[idx].find_by_order(ord) ], false);
                }
            }
            else{
                // not work -> work
                if(p/5 < np/5){
                    int idx = find_R(np/5);
                    int ord = np/5 - st.query(idx+1,N) - 1;
                    PRINT(rank2name[ *R[idx].find_by_order(ord) ], true);
                }
            }

            R[b].insert(rank[t]);
            st.add(b, 1);
            p = np;
        }
        else{
            int np = p-1;

            // 抜ける人が上から何番目か
            int up = st.query(motivation[t]+1, N)+1;
            up += R[motivation[t]].order_of_key(rank[t]);

            if(up<=p/5){
                // not work -> work
                if(p/5 == np/5){
                    int idx = find_R(p/5 + 1);
                    int ord = p/5 - st.query(idx+1,N);
                    PRINT(rank2name[ *R[idx].find_by_order(ord) ], true);
                }
            }
            else{
                // work -> not work
                if(p/5 > np/5){
                    int idx = find_R(p/5);
                    int ord = p/5 - st.query(idx+1,N) - 1;
                    PRINT(rank2name[ *R[idx].find_by_order(ord) ], false);
                }
            }

            st.add(motivation[t], -1);
            R[motivation[t]].erase(rank[t]);
            rank.erase(t);
            motivation.erase(t);
            p = np;
        }
    }
    return 0;
}
