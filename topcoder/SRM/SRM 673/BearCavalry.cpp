#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(i=0;i<n;++i)
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define mp make_pair
#define pb push_back
#define fi first
#define sc second

const long mod=1e9+7;

class BearCavalry {
    public:
    int countAssignments(vector<int> warriors, vector<int> horses) {
      int i,j;

      int n=horses.size();
      long ret=0;

      rep(i,n){//braveheartの乗る馬を決定
        //braveheartの強さ(これ以上になってはいけない)
        int BHst=warriors[0]*horses[i];

        vector<int> h(horses);
        //braveheartの乗る馬を除いておく
        h.erase(h.begin()+i);
        sort(h.begin(),h.end());

        //j番目の馬まで選んでもbraveheartより強くならない
        int ct[50]={0};

        //j番目のwarriorはどこまで選んでよいか
        for(j=1; j<n; ++j){
          int k=0;
          while(k<h.size() && warriors[j]*h[k]<BHst) ++k;
          ++ct[k];
        }

        //どの馬も選べない戦士がいるときは不可
        if(ct[0]>0) continue;

        long tmp=1;
        for(j=n-1; j>0; --j){
          //選べる馬がない
          if(ct[j]==0){
            tmp=0;
            break;
          }
          else{
            tmp*=ct[j];
            ct[j-1]+=ct[j]-1;
          }
          tmp%=mod;
        }

        ret+=tmp;
        ret%=mod;
      }

      return (int)ret % (int)mod;
    }
};

// CUT begin
ifstream data("BearCavalry.sample");

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

bool do_test(vector<int> warriors, vector<int> horses, int __expected) {
    time_t startClock = clock();
    BearCavalry *instance = new BearCavalry();
    int __result = instance->countAssignments(warriors, horses);
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
        vector<int> warriors;
        from_stream(warriors);
        vector<int> horses;
        from_stream(horses);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(warriors, horses, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1456310130;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 300 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
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
        cout << "BearCavalry (300 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
