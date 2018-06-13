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

struct Node{
    int v;
    Node *l, *r;
};

Node* new_node(){
    Node *ret;
    ret = (Node*)malloc(sizeof(Node));
    ret->l = NULL;
    ret->r = NULL;
    return ret;
}

void dfs(string s, Node *root){
    // dbg(s);
    int n = s.size();

    int d = 0;
    int lidx,ridx;
    rep(i,n){
        if(s[i]=='(') ++d;
        if(s[i]==')') --d;

        if(s[i]=='['){
            if(d==0){
                lidx = i;
                ridx = i;
                while(s[ridx]!=']') ++ridx;
                break;
            }
        }
    }

    int val = 0;
    for(int i=lidx+1; i<ridx; ++i) val = val*10 + s[i]-'0';

    string ls = "", rs = "";
    for(int i=1; i<lidx-1; ++i) ls += s[i];
    for(int i=ridx+2; i<n-1; ++i) rs += s[i];

    root->v = val;

    if(ls!=""){
        root->l = new_node();
        dfs(ls,root->l);
    }
    if(rs!=""){
        root->r = new_node();
        dfs(rs,root->r);
    }
}

void merge(Node *a, Node *b, Node *c){
    c->v = a->v + b->v;
    if(a->l!=NULL && b->l!=NULL){
        c->l = new_node();
        merge(a->l,b->l,c->l);
    }
    if(a->r!=NULL && b->r!=NULL){
        c->r = new_node();
        merge(a->r,b->r,c->r);
    }
}

string recover(Node *root){
    if(root == NULL) return "";

    string ret = "";

    ret += '(';
    ret += recover(root->l);
    ret += ')';

    ret += '[';
    ret += to_string(root->v);
    ret += ']';

    ret += '(';
    ret += recover(root->r);
    ret += ')';

    return ret;
}

int main(){
    string a,b;
    cin >>a >>b;

    Node *ra, *rb;

    ra = new_node();
    dfs(a,ra);

    rb = new_node();
    dfs(b,rb);

    Node *rc;
    rc = new_node();
    merge(ra,rb,rc);

    cout << recover(rc) << endl;
    return 0;
}
