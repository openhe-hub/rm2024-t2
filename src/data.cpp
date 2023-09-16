#include <bits/stdc++.h>
using namespace std;
const int N = 100;
mt19937 rnd(random_device{}());

inline int getRandI(int lb, int ub) {
	uniform_int_distribution<int> dist(lb, ub);
	return dist(rnd);
}

inline double getRandD(double lb, double ub) {
	uniform_real_distribution<double> dist(lb, ub);
	return dist(rnd);
}

int main() {
  ofstream fout;
  fout.open("../src/data.in");
	int n = getRandI(800, 1000), m = getRandI(900, 1000);
  fout << n << " " << m << endl;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) fout << getRandI(1, 100000) << " ";
    fout << endl;
	}
  fout << getRandD(0, 2) << endl;
  fout << getRandI(0, n - 1) << " " << getRandI(0, m - 1) << " "
		 << getRandI(0, n - 1) << " " << getRandI(0, m - 1) << endl;
	return 0;
}
