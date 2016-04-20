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

class LuckySum {
    public:
    long long construct(string note) {
		const ll INF=1LL<<60;

		//10の累乗
		ll p10[15];
		p10[0]=1;
		for(int i=1; i<15; ++i) p10[i]=p10[i-1]*10;

		//(定まった桁,繰り上がり,leading zeroに突入していない数)の中での最小値
		ll dp[15][2][3];
		rep(i,15)rep(j,2)rep(k,3) dp[i][j][k]=INF;

		int L=note.size();
		dp[0][0][2]=0;
		rep(i,L)
		{
			//現在注目している桁の文字
			char f=note[L-1-i];

			rep(carry,2)rep(remain,3)
			{
				ll t=dp[i][carry][remain];
				if(t<INF)
				{
					//printf(" %d %d %d\n",i,carry,remain);
					if(remain>=2)
					{
						if(f=='?' || f==carry+4+4+'0')
							dp[i+1][0][2]=min(dp[i+1][0][2],t+8*p10[i]);
						if(f=='?' || f==(carry+4+7)%10+'0')
							dp[i+1][1][2]=min(dp[i+1][1][2],t+11*p10[i]);
						if(f=='?' || f==(carry+7+7)%10+'0')
							dp[i+1][1][2]=min(dp[i+1][1][2],t+14*p10[i]);
					}
					if(i>0)
					{
						if(remain>=1)
						{
							if(f=='?' || f==carry+4+'0')
								dp[i+1][0][1]=min(dp[i+1][0][1],t+4*p10[i]);
							if(f=='?' || f==carry+7+'0')
								dp[i+1][0][1]=min(dp[i+1][0][1],t+7*p10[i]);
						}
						if(i==L-1 && carry!=0 && (f=='?' || f==carry+'0'))
							dp[i+1][0][0]=min(dp[i+1][0][0],t);
					}
				}
			}
		}

		ll ret=min({dp[L][0][0],dp[L][0][1],dp[L][0][2]});
		//rep(i,3) cout << " "<<dp[L][0][i] <<endl;
		if(ret>=INF) ret=-1;

        return ret;
    }
};

// CUT begin
ifstream data("LuckySum.sample");

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

template <typename T>
string to_string(T t) {
    stringstream s;
    s << t;
    return s.str();
}

string to_string(string t) {
    return "\"" + t + "\"";
}

bool do_test(string note, long long __expected) {
    time_t startClock = clock();
    LuckySum *instance = new LuckySum();
    long long __result = instance->construct(note);
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
        string note;
        from_stream(note);
        next_line();
        long long __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(note, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1459743130;
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
        cout << "LuckySum (300 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
