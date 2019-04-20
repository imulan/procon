#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0; (i)<(int)(n); ++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

int fie[5][5]={
    {0,1,2,4,4},
    {5,5,2,3,4},
    {5,5,6,7,7},
    {9,9,9,7,7},
    {8,9,9,7,10}
};

string rec[11]={
    "New Customer",
    "Promising",
    "About to Sleep",
    "Hibernating",
    "Lost",
    "Potential Loyalist",
    "Need Attention",
    "About to Leave",
    "Champion",
    "Loyal Customer",
    "Can't Lose Them"
};

vector<int> yi;
vector<int> xi;
map<string,int> cnt;
map<string,int> lt;

int main(){
    yi.push_back(0);
    xi.push_back(0);
    for(int i=0;i<4;i++){
        int a;
        scanf("%d",&a);
        xi.push_back(a);
    }
    for(int i=0;i<4;i++){
        int a;
        scanf("%d",&a);
        yi.push_back(a);
    }
    yi.push_back(11451419);
    xi.push_back(11451419);
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int q;
        string name;
        cin >> q >> name;
        if(q==1){
            cnt[name]++;
            lt[name]=i;
        }else{
            if(cnt.find(name)==cnt.end()){
                cout << "None" << endl;
            }else{
                int y=lower_bound(yi.begin(),yi.end(),cnt[name])-yi.begin();
                int x=lower_bound(xi.begin(),xi.end(),i-lt[name])-xi.begin();
                y--;
                x--;
                cout << rec[fie[y][x]] << endl;
            }
        }
    }

    /*
    for(int i=0;i<n;i++){
        int q;
        string name;
        cin >> q >> name;
        if(q==1){
            cnt[name]++;
            lt[name]=i;
        }else{
            if(cnt.find(name)==cnt.end()){
                cout << "None" << endl;
            }else{
                int y=cnt[name];
                int x=i-lt[name];
                for(int j=0;j<5;j++){
                    for(int k=0;k<5;k++){
                        if(xi[k]<x && x<=xi[k+1] && yi[j]<y && y<=yi[j+1]){
                            cout << rec[fie[j][k]] << endl;
                        }
                    }
                }
            }
        }
    }
    */

   return 0;
}
