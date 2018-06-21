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
using vi = vector<int>;

vi calc(const vector<pi> &v){
    int s[4]={}, r[13]={};
    rep(i,5){
        ++s[v[i].fi];
        ++r[v[i].se];
    }

    bool same_suit = false;
    rep(i,4) same_suit |= (s[i]==5);

    vi ret;
    // Royal straight flush: A, K, Q, J and 10 of the same suit. This is a special case of straight flush.
    if(same_suit && r[0] && r[12] && r[11] && r[10] && r[9]){
        ret.pb(9);
        return ret;
    }

    // Straight flush: Five cards in sequence (e.g. 7, 6, 5, 4 and 3) and of the same suit.
    if(same_suit){
        for(int i=12; i>=4; --i){
            bool ok = true;
            rep(j,5) ok &= (r[i-j]==1);
            if(ok){
                ret.pb(8);
                ret.pb(i);
                return ret;
            }
        }
    }

    // Four of a kind: Four cards of the same rank.
    rep(i,13){
        if(r[i]==4){
            ret.pb(7);
            if(i==0) ret.pb(13);
            else ret.pb(i);

            rep(j,13){
                if(r[j]==1){
                    if(j==0) ret.pb(13);
                    else ret.pb(j);
                }
            }

            return ret;
        }
    }

    // Full house: Three cards of the same rank, plus a pair of another rank.
    int three = 0, two = 0;
    rep(i,13){
        if(r[i]==3) ++three;
        if(r[i]==2) ++two;
    }
    if(three==1 && two==1){
        ret.pb(6);
        rep(i,13){
            if(r[i]==3){
                if(i==0) ret.pb(13);
                else ret.pb(i);
            }
        }
        rep(i,13){
            if(r[i]==2){
                if(i==0) ret.pb(13);
                else ret.pb(i);
            }
        }
        return ret;
    }

    // Flush: Five cards of the same suit, but not in sequence.
    if(same_suit){
        ret.pb(5);
        if(r[0]) ret.pb(13);
        for(int i=12; i>0; --i)if(r[i]) ret.pb(i);
        return ret;
    }

    // Straight: Five cards in sequence, but not of the same suit.
    if(r[0] && r[12] && r[11] && r[10] && r[9]){
        ret.pb(4);
        ret.pb(13);
        return ret;
    }
    for(int i=12; i>=4; --i){
        bool ok = true;
        rep(j,5) ok &= (r[i-j]==1);
        if(ok){
            ret.pb(4);
            ret.pb(i);
            return ret;
        }
    }

    // Three of a kind: Just three cards of the same rank.
    if(r[0]==3){
        ret.pb(3);
        ret.pb(13);

        for(int i=12; i>0; --i){
            if(r[i]==1) ret.pb(i);
        }

        return ret;
    }
    for(int i=12; i>0; --i){
        if(r[i]==3){
            ret.pb(3);
            ret.pb(i);

            if(r[0]==1) ret.pb(13);
            for(int j=12; j>0; --j){
                if(r[j]==1) ret.pb(j);
            }

            return ret;
        }
    }

    // Two pairs: Two cards of the same rank, and two other cards of another same rank.
    two = 0;
    rep(i,13) two += (r[i]==2);
    if(two == 2){
        ret.pb(2);
        if(r[0]==2) ret.pb(13);
        for(int i=12; i>0; --i)if(r[i]==2) ret.pb(i);
        rep(i,13){
            if(r[i]==1){
                if(i==0) ret.pb(13);
                else ret.pb(i);
            }
        }
        return ret;
    }

    // One pair: Just a pair of cards (two cards) of the same rank.
    rep(i,13){
        if(r[i]==2){
            ret.pb(1);
            if(i==0) ret.pb(13);
            else ret.pb(i);

            if(r[0]==1) ret.pb(13);
            for(int j=12; j>0; --j)if(r[j]==1) ret.pb(j);

            return ret;
        }
    }

    // High card: Any other hand.
    ret.pb(0);
    if(r[0]) ret.pb(13);
    for(int i=12; i>0; --i)if(r[i]) ret.pb(i);
    return ret;
}

vi hand(const vector<pi> &v){
    vi ret(1,-1);
    rep(i,7)rep(j,i){
        vector<pi> cards;
        rep(k,7)if(k!=i && k!=j) cards.pb(v[k]);
        ret = max(ret, calc(cards));
    }

    // dbg(v);dbg(ret);
    return ret;
}

pi cv(string s){
    string suit = "SHDC", rank = "A23456789TJQK";
    int a = suit.find(s[0]), b = rank.find(s[1]);
    return {a,b};
}

int main(){

    while(1){
        vector<pi> y,o,c;
        string s;
        cin >>s;
        if(s=="#") break;
        y.pb(cv(s));

        cin >>s;
        y.pb(cv(s));

        rep(i,2){
            cin >>s;
            o.pb(cv(s));
        }
        rep(i,3){
            cin >>s;
            c.pb(cv(s));
        }

        // dbg(y);dbg(o);dbg(c);
        set<pi> used;
        for(pi p:y) used.insert(p);
        for(pi p:o) used.insert(p);
        for(pi p:c) used.insert(p);

        int U=0, win=0;
        rep(i,52)rep(j,i){
            pi turn(i/13,i%13), river(j/13,j%13);
            if(used.count(turn) || used.count(river)) continue;

            vector<pi> my(y), enemy(o);
            for(pi p:c){
                my.pb(p);
                enemy.pb(p);
            }
            for(pi p:{turn,river}){
                my.pb(p);
                enemy.pb(p);
            }

            vi mh = hand(my), oh = hand(enemy);

            ++U;
            if(mh > oh) ++win;
        }

        printf("%.10f\n", (double)win/U);
    }
    return 0;
}
