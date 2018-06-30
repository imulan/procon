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

using f = map<string,ll>;

void PRINT(f a){
    for(const auto &p:a){
        cout << p.se << p.fi << " + ";
    }
    cout << endl;
}

f norm(f a){
    f ret;
    for(const auto &p:a){
        string v = p.fi;
        sort(all(v));
        if(p.se != 0) ret[v] = p.se;
    }
    return ret;
}

f sub(f a){
    a = norm(a);

    f ret;
    for(const auto &p:a){
        string v = p.fi;
        if(p.se != 0) ret[v] = -p.se;
    }
    return ret;
}

f add(f a, f b){
    a = norm(a);
    b = norm(b);

    for(const auto &p:b) a[p.fi] += p.se;

    return norm(a);
}

f mul(f a, f b){
    a = norm(a);
    b = norm(b);

    f ret;
    for(const auto &p:a)for(const auto &q:b){
        string var = p.fi+q.fi;
        sort(all(var));

        ret[var] += p.se*q.se;
    }
    return norm(ret);
}

f E(string s);

f T(string s){
    int n = s.size();
    f ret;
    ret[""]=1;

    int idx = 0;
    while(idx<n){
        f m;
        if(s[idx]==' '){
            ++idx;
            continue;
        }
        else if(s[idx]=='('){
            int ep = idx;
            int p = 0;
            while(ep<n){
                if(s[ep]=='(') ++p;
                if(s[ep]==')'){
                    --p;
                    if(p==0) break;
                }
                ++ep;
            }
            assert(ep<n);
            assert(s[ep]==')');

            string t = s.substr(idx+1,ep-idx-1);
            m = E(t);
            idx = ep+1;
        }
        else if(isdigit(s[idx])){
            ll val = 0;
            while(idx<n && isdigit(s[idx])){
                val = val*10 + (s[idx]-'0');
                ++idx;
            }

            int pw = 1;
            int nx = idx;
            while(nx<n && s[nx]==' ') ++nx;
            if(nx<n && s[nx]=='^'){
                ++nx;
                while(nx<n && s[nx]==' ') ++nx;

                assert(nx<n);
                assert(isdigit(s[nx]));

                pw = 0;
                while(nx<n && isdigit(s[nx])){
                    pw = 10*pw + (s[nx]-'0');
                    ++nx;
                }
            }

            ll vv = 1;
            rep(_,pw) vv *= val;

            m[""] = vv;
            idx = nx;
        }
        else if(islower(s[idx])){
            char c = s[idx];
            ++idx;

            int pw = 1;
            int nx = idx;
            while(nx<n && s[nx]==' ') ++nx;
            if(nx<n && s[nx]=='^'){
                ++nx;
                while(nx<n && s[nx]==' ') ++nx;

                assert(nx<n);
                assert(isdigit(s[nx]));

                pw = 0;
                while(nx<n && isdigit(s[nx])){
                    pw = 10*pw + (s[nx]-'0');
                    ++nx;
                }
            }

            string t = "";
            rep(_,pw) t += c;

            m[t] = 1;
            idx = nx;
        }
        else assert(false);

        ret = mul(ret, m);
    }

    return norm(ret);
}

f E(string s){
    int n = s.size();
    f ret;

    int p = 0;
    int start = 0;
    bool plus = true;

    rep(i,n){
        if(s[i]=='(') ++p;
        if(s[i]==')') --p;

        if(s[i]=='+' || s[i]=='-'){
            if(p==0){
                string term = s.substr(start,i-start);
                f t = norm(T(term));
                if(!plus) t = sub(t);
                plus = (s[i]=='+');

                ret = add(ret, t);

                start = i+1;
            }
        }
    }

    string term = s.substr(start,n-start);
    f t = norm(T(term));
    if(!plus) t = sub(t);

    ret = add(ret, t);

    return norm(ret);
}

int main(){
    string s;
    while(getline(cin, s),(s!=".")){
        f S = E(s);
        // PRINT(S);

        string t;
        while(getline(cin, t),(t!=".")){
            f T = E(t);
            // PRINT(T);
            cout << (S==T?"yes":"no") << endl;
        }
        cout << "." << endl;
    }
    return 0;
}
