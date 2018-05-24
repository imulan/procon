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

bool err;

string e;

ll N(int l, int r);
ll F(int l, int r);
ll T(int l, int r);
ll E(int l, int r);

ll N(int l, int r){
    if(l>r){
        err = true;
        return 0;
    }

    ll ret = 0;
    for(int i=l; i<=r; ++i){
        if(e[i]=='0' || e[i]=='1') ret = ret*2 + e[i]-'0';
        else{
            err = true;
            return 0;
        }
    }

    if(e[l]=='0'){
        if(l!=r) err = true;
    }
    return ret;
}

ll F(int l, int r){
    if(l>r){
        err = true;
        return 0;
    }

    if(e[l]=='('){
        if(e[r]!=')') err = true;
        return E(l+1,r-1);
    }
    else if(e[l]=='-'){
        return -F(l+1,r);
    }
    else return N(l,r);
}

ll T(int l, int r){
    if(l>r){
        err = true;
        return 0;
    }

    int b = 0;

    int a_pos = -1;
    for(int i=r; i>=l; --i){
        if(e[i]==')') ++b;
        else if(e[i]=='(') --b;

        if(e[i]=='*'){
            if(b==0){
                a_pos = i;
                break;
            }
        }
    }

    if(a_pos == -1) return F(l,r);
    else return T(l,a_pos-1)*F(a_pos+1,r);
}

ll E(int l, int r){
    if(l>r){
        err = true;
        return 0;
    }

    char op = '?';
    int o_pos = -1;
    int b = 0;
    for(int i=r; i>=l; --i){
        if(e[i]==')') ++b;
        else if(e[i]=='(') --b;

        if(e[i]=='+' && b==0){
            o_pos = i;
            op = '+';
            break;
        }

        if(e[i]=='-' && b==0){
            o_pos = i;
            while(l<=o_pos && e[o_pos]=='-') --o_pos;

            if(o_pos<l){
                op = '?';
                break;
            }
            else{
                if(e[o_pos] == '+'){
                    op = '+';
                    break;
                }
                else if(e[o_pos] == '*') continue;
                else{
                    ++o_pos;
                    op = '-';
                    break;
                }
            }
        }
    }

    if(op=='?') return T(l,r);
    else if(op=='+') return E(l,o_pos-1)+T(o_pos+1,r);
    else return E(l,o_pos-1)-T(o_pos+1,r);
}

bool Q(int l, int r){
    int eq_pos = 0;
    for(int i=l; i<=r; ++i){
        if(e[i]=='=') eq_pos = i;
    }

    err = false;
    ll L = E(l,eq_pos-1);
    ll R = E(eq_pos+1,r);
    return L==R;
}

int main(){
    string s;
    cin >>s;
    int n = s.size();

    set<char> a;
    for(char c:s){
        if(islower(c)||isupper(c)) a.insert(c);
    }

    if(a.size()>8){
        cout << 0 << endl;
        return 0;
    }

    string x = "01+-*()=";
    sort(all(x));

    set<string> valid;
    set<string> check;
    do{
        auto itr = x.begin();
        map<char,char> cv;
        for(char c:a){
            cv[c] = *itr;
            ++itr;
        }

        string t = s;
        rep(i,n)if(cv.count(t[i])) t[i]=cv[t[i]];

        int eq = 0;
        rep(i,n) eq += (t[i]=='=');
        if(eq!=1) continue;

        e = t;
        bool res = Q(0,e.size()-1);

        if(!err && res) valid.insert(t);
        if(!err) check.insert(t);
    }while(next_permutation(all(x)));

    // for(string V:valid) dbg(V);
    // for(string C:check) dbg(C);
    cout << valid.size() << endl;
    return 0;
}
