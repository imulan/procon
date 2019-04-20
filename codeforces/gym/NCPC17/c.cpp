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

const int D = 360;
set<int> x[3][D];

map<int,vector<int>> ID2col;
map<int,int> ID2val;
set<pi> s;

int calc(int ID){
    int ret = 0;
    rep(i,3){
        int val = ID2col[ID][i];
        if(x[i][val].size() > 1) continue;

        for(int j=1; j<D; ++j){
            int f = (val+j)%D;
            if(!x[i][f].empty()){
                ret += j;
                break;
            }
        }
        for(int j=1; j<D; ++j){
            int f = (val-j+D)%D;
            if(!x[i][f].empty()){
                ret += j;
                break;
            }
        }
    }
    // dbg(ret);
    return ret;
}

void del(int ID){
    s.erase({ID2val[ID],ID});
    set<int> recalc;

    rep(i,3){
        int val = ID2col[ID][i];
        x[i][val].erase(ID);

        if(x[i][val].size()==0){
            for(int j=1; j<D; ++j){
                int f = (val+j)%D;
                if(!x[i][f].empty()){
                    if(x[i][f].size() == 1){
                        recalc.insert(*x[i][f].begin());
                    }
                    break;
                }
            }
            for(int j=1; j<D; ++j){
                int f = (val-j+D)%D;
                if(!x[i][f].empty()){
                    if(x[i][f].size() == 1){
                        recalc.insert(*x[i][f].begin());
                    }
                    break;
                }
            }
        }
        else if(x[i][val].size()==1){
            recalc.insert(*x[i][val].begin());
        }
    }

    for(int i:recalc){
        s.erase({ID2val[i],i});
        ID2val[i] = calc(i);
        s.insert({ID2val[i],i});
    }
}

int main(){
    int n;
    scanf(" %d", &n);

    vector<int> a(n);
    rep(i,n){
        vector<int> v(3);
        rep(j,3) scanf(" %d", &v[j]);
        int ID;
        scanf(" %d", &ID);
        ID *= -1;

        a[i] = ID;

        ID2col[ID] = v;
        rep(j,3) x[j][v[j]].insert(ID);
    }

    rep(i,n){
        ID2val[a[i]] = calc(a[i]);
        s.insert({ID2val[a[i]], a[i]});
    }

    while(!s.empty()){
        // for(pi pp:s) dbg(pp);

        auto itr = s.begin();
        printf("%d\n", -itr->se);
        del(itr->se);
    }
    return 0;
}
