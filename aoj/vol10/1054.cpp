#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

#define x first
#define y second

using pi = pair<int,int>;
using P = pair<pi,pi>;

struct Page{
    string name;

    int m;
    vector<P> b;
    vector<string> l;

    Page(){};

    void READ(){
        cin >>name >>m;
        b = vector<P>(m);
        l = vector<string>(m);
        rep(i,m){
            cin >>b[i].fi.x >>b[i].fi.y >>b[i].se.x >>b[i].se.y;
            cin >>l[i];
        }
    }

    string click(int x, int y){
        rep(i,m){
            if(b[i].fi.x<=x && x<=b[i].se.x && b[i].fi.y<=y && y<=b[i].se.y) return l[i];
        }
        return "?";
    }
};

int main(){
    int n;
    while(cin >>n,n){
        int W,H;
        cin >>W >>H;

        vector<Page> p(n);
        rep(i,n) p[i].READ();

        map<string,int> name2id;
        rep(i,n) name2id[p[i].name] = i;

        int Q;
        cin >>Q;

        vector<int> a(Q+2,-1);
        int idx = 0;
        a[0] = 0;

        rep(qq,Q){
            string s;
            cin >>s;
            if(s == "click"){
                int X,Y;
                cin >>X >>Y;
                string res = p[a[idx]].click(X,Y);
                if(res != "?"){
                    for(int j=idx+1; j<Q+2; ++j) a[j] = -1;
                    a[idx+1] = name2id[res];
                    ++idx;
                }
            }
            else if(s == "back"){
                if(idx>0) --idx;
            }
            else if(s == "forward"){
                if(a[idx+1] != -1) ++idx;
            }
            else{
                // show
                cout << p[a[idx]].name << "\n";
            }
        }
    }
    return 0;
}
