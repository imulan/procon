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

using pic = pair<int,char>;

int main(){
    int n;
    cin >>n;

    vector<int> x(n),y(n);
    vector<char> d(n);

    vector<int> ux,uy;
    rep(i,n){
        cin >>x[i] >>y[i] >>d[i];
        ux.pb(x[i]);
        uy.pb(y[i]);
    }

    sort(all(ux));
    ux.erase(unique(all(ux)), ux.end());
    sort(all(uy));
    uy.erase(unique(all(uy)), uy.end());

    int X = ux.size(), Y = uy.size();

    rep(i,n){
        x[i] = lower_bound(all(ux), x[i]) - ux.begin();
        y[i] = lower_bound(all(uy), y[i]) - uy.begin();
    }

    // initialize
    vector<set<pic>> SX(X), SY(Y);
    rep(i,n){
        SX[x[i]].insert({y[i],d[i]});
        SY[y[i]].insert({x[i],d[i]});
    }

    int ans = 0;
    rep(i,n){
        vector<set<pic>> sx(SX), sy(SY);

        int tmp = 0;
        int cx = x[i], cy = y[i];
        char cd = d[i];
        while(1){
            // remove current position
            sx[cx].erase({cy,cd});
            sy[cy].erase({cx,cd});
            ++tmp;

            if(cd == '>'){
                auto itr = sy[cy].lower_bound({cx,cd});
                if(itr == sy[cy].end()) break;

                cx = itr->fi;
                cd = itr->se;
            }
            else if(cd == '<'){
                auto itr = sy[cy].lower_bound({cx,cd});
                if(itr == sy[cy].begin()) break;
                --itr;
                cx = itr->fi;
                cd = itr->se;

            }
            else if(cd == 'v'){
                auto itr = sx[cx].lower_bound({cy,cd});
                if(itr == sx[cx].end()) break;

                cy = itr->fi;
                cd = itr->se;
            }
            else if(cd == '^'){
                auto itr = sx[cx].lower_bound({cy,cd});
                if(itr == sx[cx].begin()) break;
                --itr;
                cy = itr->fi;
                cd = itr->se;
            }
            else assert(false);
        }

        ans = max(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}
