#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back

void solve(istream &fin, ostream &fout){
    int n,p,c,h;
    fin >>n >>p >>c >>h;
    --h;

    vector<int> b(n);
    rep(i,n){
        fin >>b[i];
        --b[i];
    }

    vector<int> l(p);
    rep(i,p){
        fin >>l[i];
        --l[i];
    }

    vector<int> ans;
    if(n==1){
        if(l[p-1] == h) ans.pb(0);
    }
    else if(n==2){
        bool all_h = true;
        rep(i,p)if(l[i]!=h) all_h = false;

        if(all_h) {
            int bb = 0;
            rep(i, n) bb += (b[i] != h);
            if (bb == 0) {
                rep(i, n) ans.pb(i);
            } else if (bb == 1) {
                rep(i, n) {
                    if (b[i] != h) ans.pb(i);
                }
            }
        }
    }
    else{
        vector<int> ini(c);
        rep(i,n) ++ini[b[i]];

        vector<int> ot(c);
        int nh = 0;
        for(int i=1; i<p; ++i){
            ++ot[l[i]];
            nh += (l[i]!=h);
        }

        vector<int> num(c);
        rep(i,c) num[i] = ini[i]+ot[i];

        multiset<int> ms;
        rep(i,c)if(i!=h) ms.insert(num[i]);

        rep(i,n) {
            if (b[i] != h) {
                ms.erase(ms.find(num[b[i]]));
                --num[b[i]];
                ms.insert(num[b[i]]);
            }
            if (l[0] != h) {
                ms.erase(ms.find(num[l[0]]));
                ++num[l[0]];
                ms.insert(num[l[0]]);
            }

            --ini[b[i]];
            ++ini[l[0]];

            int mx = *ms.rbegin();
//            printf(" %d : mx %d\n",i,mx);

            if(ini[h] > nh){
                int remh = ini[h] - nh;

                if(mx<n){
                    if(mx < remh) ans.pb(i);
                }
            }

            if(b[i]!=h) {
                ms.erase(ms.find(num[b[i]]));
                ++num[b[i]];
                ms.insert(num[b[i]]);
            }
            if(l[0]!=h) {
                ms.erase(ms.find(num[l[0]]));
                --num[l[0]];
                ms.insert(num[l[0]]);
            }

            ++ini[b[i]];
            --ini[l[0]];
        }
    }

    int A = ans.size();
    fout << A << '\n';
    rep(i,A){
        if(i) fout << ' ';
        fout << ans[i]+1;
    }
    fout << '\n';
}

int main(){
#ifdef ONLINE_JUDGE
    ifstream ifs("kabaleo.in");
    ofstream ofs("kabaleo.out");
    solve(ifs, ofs);
    ifs.close();
    ofs.close();
#else
    solve(cin, cout);
#endif
    return 0;
}