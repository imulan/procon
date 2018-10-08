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

const int mod = 2011;

int mod_pow(int x, int n){
    int ret = 1;
    while(n){
        if(n&1) (ret *= x) %= mod;
        (x *= x) %= mod;
        n >>= 1;
    }
    return ret;
}

int mod_inv(int x){
    return mod_pow(x, mod-2);
}

int h,w;
string s[20];

const int H = 22, W = 88;
int vertical_dots[W][H];
int horizontal_dots[H][W];

void CUT(int &ly, int &lx, int &ry, int &rx){
    int ww = rx-lx+1;
    while(horizontal_dots[ly][rx+1] - horizontal_dots[ly][lx] == ww) ++ly;
    while(horizontal_dots[ry][rx+1] - horizontal_dots[ry][lx] == ww) --ry;

    int hh = ry-ly+1;
    while(vertical_dots[lx][ry+1] - vertical_dots[lx][ly] == hh) ++lx;
    while(vertical_dots[rx][ry+1] - vertical_dots[rx][ly] == hh) --rx;
}

int expr(int ly, int lx, int ry, int rx);

int digit(int ly, int lx, int ry, int rx){
    CUT(ly,lx,ry,rx);
    assert(ly==ry && lx==rx);
    return s[ly][lx] - '0';
}

int fraction(int ly, int lx, int ry, int rx){
    CUT(ly,lx,ry,rx);
    // printf(" !!! fraction: (%d %d %d %d) \n", ly,lx,ry,rx);

    int base_y = -1;
    for(int y=ly; y<=ry; ++y){
        if(s[y][lx] == '-'){
            base_y = y;
            break;
        }
    }
    assert(base_y >= 0);

    return (expr(ly,lx,base_y-1,rx) * mod_inv(expr(base_y+1,lx,ry,rx))) % mod;
}

int primary(int ly, int lx, int ry, int rx){
    CUT(ly,lx,ry,rx);

    int brac = -1;
    for(int y=ly; y<=ry; ++y){
        if(s[y][lx]=='('){
            brac = y;
            break;
        }
    }

    if(brac==-1) return digit(ly,lx,ry,rx);
    else{
        assert(s[brac][rx] == ')');
        return expr(ly,lx+2,ry,rx-2);
    }
}

int powexpr(int ly, int lx, int ry, int rx){
    CUT(ly,lx,ry,rx);

    if(ly==ry && lx==rx) return digit(ly,lx,ry,rx);

    int exp = -1;
    for(int y=ly; y<=ry; ++y){
        if( isdigit(s[y][rx]) ) exp = s[y][rx]-'0';
    }

    if(exp == -1) return primary(ly,lx,ry,rx);
    return mod_pow(primary(ly,lx,ry,rx-1), exp);
}

int factor(int ly, int lx, int ry, int rx){
    CUT(ly,lx,ry,rx);
    // printf(" factor: (%d %d %d %d) \n", ly,lx,ry,rx);

    // fraction
    for(int y=ly; y<=ry; ++y){
        bool is_frac = true;
        for(int x=lx; x<=rx; ++x){
            is_frac &= (s[y][x] == '-');
        }
        if(is_frac) return fraction(ly,lx,ry,rx);
    }

    // - factor
    for(int y=ly; y<=ry; ++y){
        if(s[y][lx] == '-'){
            return (-factor(ly,lx+2,ry,rx) + mod) % mod;
        }
    }

    return powexpr(ly,lx,ry,rx);
}

int term(int ly, int lx, int ry, int rx){
    CUT(ly,lx,ry,rx);
    // printf(" term: (%d %d %d %d) \n", ly,lx,ry,rx);

    int base_y = -1;
    for(int y=ly; y<=ry; ++y){
        bool is_frac = true;
        for(int x=lx; x<=rx; ++x){
            is_frac &= (s[y][x] == '-');

            if(s[y][x] == '*'){
                bool ok = true;
                for(int i:{-1,1}){
                    int xx = x+i;
                    if(lx<=xx && xx<=rx){
                        for(int yy=ly; yy<=ry; ++yy){
                            ok &= (s[yy][xx]=='.');
                        }
                    }
                }

                if(ok){
                    base_y = y;
                    break;
                }
            }
        }

        if(base_y!=-1) break;
        if(is_frac) return fraction(ly,lx,ry,rx);
    }

    if(base_y == -1) return factor(ly,lx,ry,rx);

    int sep_x = rx;
    int brac = 0;
    while(sep_x>=lx){
        if(s[base_y][sep_x] == ')') ++brac;
        if(s[base_y][sep_x] == '(') --brac;

        if(brac==0 && s[base_y][sep_x] == '*') break;
        --sep_x;
    }

    if(sep_x<lx) return factor(ly,lx,ry,rx);
    return (term(ly,lx,ry,sep_x-1) * factor(ly,sep_x+1,ry,rx)) % mod;
}

int expr(int ly, int lx, int ry, int rx){
    CUT(ly,lx,ry,rx);
    // printf(" expr: (%d %d %d %d) \n", ly,lx,ry,rx);

    int base_y = -1;
    for(int y=ly; y<=ry; ++y){
        bool is_frac = true;
        for(int x=lx; x<=rx; ++x){
            is_frac &= (s[y][x] == '-');

            if(s[y][x] == '+' || s[y][x] == '-'){
                bool ok = true;
                for(int i:{-1,1}){
                    int xx = x+i;
                    if(lx<=xx && xx<=rx){
                        for(int yy=ly; yy<=ry; ++yy){
                            ok &= (s[yy][xx]=='.');
                        }
                    }
                }

                if(ok){
                    base_y = y;
                    break;
                }
            }
        }

        if(base_y!=-1) break;
        if(is_frac) return fraction(ly,lx,ry,rx);
    }

    if(base_y == -1) return term(ly,lx,ry,rx);

    int sep_x = rx;
    int brac = 0;
    while(sep_x>=lx){
        if(s[base_y][sep_x] == ')') ++brac;
        if(s[base_y][sep_x] == '(') --brac;

        if(brac==0){
            if(s[base_y][sep_x] == '+') break;
            if(s[base_y][sep_x] == '-'){
                if(lx+2<=sep_x && sep_x+1<=rx){
                    bool valid = (s[base_y][sep_x-1]=='.' && s[base_y][sep_x+1]=='.');
                    char ch = s[base_y][sep_x-2];
                    if(valid){
                        if(ch == '-'){
                            // chは分数の線なのでok
                            if(sep_x-3>=0 && s[base_y][sep_x-3]=='-') break;
                        }
                        else{
                            if(ch != '+' && ch != '*') break;
                        }
                    }
                }
            }
        }
        --sep_x;
    }

    if(sep_x<lx) return term(ly,lx,ry,rx);

    int mul = 1;
    if(s[base_y][sep_x] == '-') mul = -1;

    return (expr(ly,lx,ry,sep_x-1) + mul*term(ly,sep_x+1,ry,rx) + mod) % mod;
}

int main(){
    while(cin >>h,h){
        rep(i,h) cin >>s[i];
        w = s[0].size();

        memset(vertical_dots, 0, sizeof(vertical_dots));
        rep(i,w){
            rep(j,h){
                vertical_dots[i][j+1] = vertical_dots[i][j] + (s[j][i]=='.');
            }
        }

        memset(horizontal_dots, 0 ,sizeof(horizontal_dots));
        rep(i,h){
            rep(j,w){
                horizontal_dots[i][j+1] = horizontal_dots[i][j] + (s[i][j]=='.');
            }
        }

        cout << expr(0,0,h-1,w-1) << endl;
    }
    return 0;
}
