#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <set>
#include <sstream>
#include <utility>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <climits>
#include <fstream>
using namespace std;

typedef long long ll;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) for(int i=0;i<(n);++i)
#define foreach(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); itr++)

class BearFair {
    public:
    string isFair(int n, int b, vector<int> upTo, vector<int> quantity) {
      int q=quantity.size();
      vector< pair<int,int> > v(q);
      REP(i,q){
        v[i].first=upTo[i];
        v[i].second=quantity[i];
      }
      v.push_back(make_pair(0,0));
      v.push_back(make_pair(b,n));
      sort(v.begin(),v.end());

      bool ans=true;

      int od=0,ev=0,fr=0;

      REP(i,q+1){
        int wid=v[i+1].first-v[i].first;

        if(wid==0){
          if(v[i+1].second!=v[i].second){
            ans=false;
            break;
          }
        }
        else{
          int nums=v[i+1].second-v[i].second;

          if(nums<0){
            ans=false;
            break;
          }

          if(wid<nums){
            ans=false;
            break;
          }
          else if(nums*2<=wid){
            fr += nums;
          }
          else{
            int now=v[i+1].first;
            while(v[i].first<now){
              if(now%2==0) ++ev;
              else ++od;

              --now;
              --nums;
              --wid;
              if(nums*2<=wid) break;
            }
            fr+=nums;
          }
        }

      }
      //printf("od:%d, ev:%d, fr:%d\n",od,ev,fr);

      if(ans){
        if(od>n/2 || ev>n/2) ans=false;
      }

      //output
      string ret="fair";
      if(!ans) ret="unfair";

      return ret;
    }
};

// CUT begin
ifstream data("BearFair.sample");

string next_line() {
    string s;
    getline(data, s);
    return s;
}

template <typename T> void from_stream(T &t) {
    stringstream ss(next_line());
    ss >> t;
}

void from_stream(string &s) {
    s = next_line();
}

template <typename T> void from_stream(vector<T> &ts) {
    int len;
    from_stream(len);
    ts.clear();
    for (int i = 0; i < len; ++i) {
        T t;
        from_stream(t);
        ts.push_back(t);
    }
}

template <typename T>
string to_string(T t) {
    stringstream s;
    s << t;
    return s.str();
}

string to_string(string t) {
    return "\"" + t + "\"";
}

bool do_test(int n, int b, vector<int> upTo, vector<int> quantity, string __expected) {
    time_t startClock = clock();
    BearFair *instance = new BearFair();
    string __result = instance->isFair(n, b, upTo, quantity);
    double elapsed = (double)(clock() - startClock) / CLOCKS_PER_SEC;
    delete instance;

    if (__result == __expected) {
        cout << "PASSED!" << " (" << elapsed << " seconds)" << endl;
        return true;
    }
    else {
        cout << "FAILED!" << " (" << elapsed << " seconds)" << endl;
        cout << "           Expected: " << to_string(__expected) << endl;
        cout << "           Received: " << to_string(__result) << endl;
        return false;
    }
}

int run_test(bool mainProcess, const set<int> &case_set, const string command) {
    int cases = 0, passed = 0;
    while (true) {
        if (next_line().find("--") != 0)
            break;
        int n;
        from_stream(n);
        int b;
        from_stream(b);
        vector<int> upTo;
        from_stream(upTo);
        vector<int> quantity;
        from_stream(quantity);
        next_line();
        string __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(n, b, upTo, quantity, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1453996832;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 250 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(2);
    set<int> cases;
    bool mainProcess = true;
    for (int i = 1; i < argc; ++i) {
        if ( string(argv[i]) == "-") {
            mainProcess = false;
        } else {
            cases.insert(atoi(argv[i]));
        }
    }
    if (mainProcess) {
        cout << "BearFair (250 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
