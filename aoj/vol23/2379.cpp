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

struct Dice{
    char f[7];

    Dice(){
        rep(i,6) f[i] = '?';
    }

    void R(){
        char tmp = f[0];
        f[0] = f[4];
        f[4] = f[5];
        f[5] = f[2];
        f[2] = tmp;
    }

    void L(){
        char tmp = f[0];
        f[0] = f[2];
        f[2] = f[5];
        f[5] = f[4];
        f[4] = tmp;
    }

    void B(){
        char tmp = f[0];
        f[0] = f[1];
        f[1] = f[5];
        f[5] = f[3];
        f[3] = tmp;
    }

    void F(){
        char tmp = f[0];
        f[0] = f[3];
        f[3] = f[5];
        f[5] = f[1];
        f[1] = tmp;
    }

    void CCW(){
        char tmp = f[1];
        f[1] = f[4];
        f[4] = f[3];
        f[3] = f[2];
        f[2] = tmp;
    }
};

const int dy[4]={1,-1,0,0};
const int dx[4]={0,0,1,-1};

int h,w;
string s[55];
bool vis[55][55];

bool IN(int y, int x){
    return (0<=y && y<h && 0<=x && x<w && s[y][x]!='.');
}

Dice t;
void dfs(int y, int x){
    vis[y][x] = true;
    t.f[0] = s[y][x];

    rep(i,4){
        int ny = y+dy[i], nx = x+dx[i];
        if(IN(ny,nx) && !vis[ny][nx]){
            if(i==0) t.B();
            else if(i==1) t.F();
            else if(i==2) t.L();
            else if(i==3) t.R();

            dfs(ny,nx);

            if(i==0) t.F();
            else if(i==1) t.B();
            else if(i==2) t.R();
            else if(i==3) t.L();
        }
    }
}

int black[8][3]={ {2,3,5}, {3,4,5}, {1,4,5}, {1,2,5}, {0,2,3}, {0,3,4}, {0,1,4}, {0,1,2} };

bool solve(){
    cin >>h >>w;
    rep(i,h) cin >>s[i];

    vector<Dice> d;
    rep(i,h)rep(j,w)if(s[i][j]!='.' && !vis[i][j]){
        t = Dice();
        dfs(i,j);
        d.pb(t);
    }

    assert(d.size() == 8);

    // rep(i,8){
    //     rep(j,6) printf(" %c",d[i].f[j]);
    //     printf("\n");
    // }

    rep(i,8){
        int b_ct = 0;
        rep(j,6) b_ct += (d[i].f[j]=='#');
        if(b_ct != 3) return false;
    }

    vector<int> p(8);
    rep(i,8) p[i] = i;

    do{
        bool ok = true;

        vector<vector<char>> aa,bb;
        for(int i:{0,6}){
            t = d[p[i]];

            int CT = 0;
            rep(z1,4){
                t.R();
                rep(z2,4){
                    t.F();
                    rep(z3,4){
                        t.CCW();

                        int b_ct = 0;
                        rep(j,3) b_ct += (t.f[black[i][j]]=='#');
                        if(b_ct == 3){
                            ++CT;

                            if(i==0){
                                aa.pb({t.f[0],t.f[1],t.f[4]});
                            }
                            else{
                                bb.pb({t.f[2],t.f[3],t.f[5]});
                            }
                        }
                    }
                }
            }

            if(CT == 0){
                ok = false;
                break;
            }
        }
        if(!ok) continue;

        // dbg(p);
        sort(all(aa));
        aa.erase(unique(all(aa)), aa.end());
        sort(all(bb));
        bb.erase(unique(all(bb)), bb.end());

        int AA = aa.size(), BB = bb.size();
        rep(ai,AA)rep(bi,BB){
            char ch[7];
            ch[0] = aa[ai][0];
            ch[1] = aa[ai][1];
            ch[2] = bb[bi][0];
            ch[3] = bb[bi][1];
            ch[4] = aa[ai][2];
            ch[5] = bb[bi][2];

            set<char> cols;
            rep(i,6) cols.insert(ch[i]);
            if(cols.size() != 6) continue;

            ok = true;
            rep(i,8){
                bool found = false;
                t = d[p[i]];
                rep(z1,4){
                    t.R();
                    rep(z2,4){
                        t.F();
                        rep(z3,4){
                            t.CCW();

                            int b_ct = 0;
                            rep(j,3) b_ct += (t.f[black[i][j]]=='#');
                            if(b_ct == 3){
                                int ok_ct = 0;
                                rep(j,6){
                                    if(t.f[j]!='#'){
                                        ok_ct += (t.f[j] == ch[j]);
                                    }
                                }

                                if(ok_ct == 3) found = true;
                            }
                        }
                    }
                }

                if(!found){
                    ok = false;
                    break;
                }
            }
            if(ok) return true;
        }
    }while(next_permutation(all(p)));

    return false;
}

int main(){
    cout << (solve()?"Yes":"No") << endl;
    return 0;
}
