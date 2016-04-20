#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define pb push_back
#define fi first
#define se second

class ReplacingDigit {
    public:
	inline int digit(int x)
	{
		int ret=0;
		while(x>0)
		{
			x/=10;
			++ret;
		}
		return ret;
	}

    int getMaximumStockWorth(vector<int> A, vector<int> D) {
		int n=A.size();

		int f=8;
		while(f>=0 && D[f]==0) --f;

		int pw[8]={0};
		pw[0]=1;
		for(int i=1; i<=7; ++i) pw[i]=pw[i-1]*10;

		while(f!=-1)
		{
			int idx=-1;
			int dif=0;

			rep(i,n)
			{
				int b=digit(A[i]);
				int now=A[i];
				int d[7];

				rep(j,b)
				{
					d[j]=now%10;
					now/=10;
				}

				for(int j=b-1; j>=0; --j)
				{
					if(d[j]<f+1 && dif<(f+1-d[j])*pw[j])
					{
						dif=(f+1-d[j])*pw[j];
						idx=i;
						break;
					}
				}
			}

			if(idx==-1) break;
			else
			{
				int b=digit(A[idx]);
				int now=A[idx];
				int d[7];

				rep(i,b)
				{
					d[i]=now%10;
					now/=10;
				}
				for(int i=b-1; i>=0; --i)
				{
					if(d[i]<f+1)
					{
						//printf("change %d ->",A[idx]);
						A[idx]+=(f+1-d[i])*pw[i];
						//printf(" %d\n",A[idx]);
						break;
					}
				}

				--D[f];
				while(f>=0 && D[f]==0) --f;
			}
		}

		int ret=0;
		rep(i,n) ret+=A[i];
		return ret;
    }
};

// CUT begin
ifstream data("ReplacingDigit.sample");

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

bool do_test(vector<int> A, vector<int> D, int __expected) {
    time_t startClock = clock();
    ReplacingDigit *instance = new ReplacingDigit();
    int __result = instance->getMaximumStockWorth(A, D);
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
        vector<int> A;
        from_stream(A);
        vector<int> D;
        from_stream(D);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(A, D, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1460473374;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
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
        cout << "ReplacingDigit (500 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
