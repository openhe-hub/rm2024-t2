#include <bits/stdc++.h>

using namespace std;
const int maxn = 1005;
int n, m;
double t;
int grid[maxn][maxn];
double a[maxn][maxn];
double dis[maxn][maxn];

struct Point {
    int x, y;

    Point() {}

    Point(int _x, int _y) {
      x = _x;
      y = _y;
    }

    friend Point operator+(Point A, Point B) {
      return Point(A.x + B.x, A.y + B.y);
    }

    friend bool operator==(Point A, Point B) {
      return (A.x == B.x && A.y == B.y);
    }

    friend bool operator<(Point A, Point B) {
      return true;
    }
};

typedef pair<double, Point> pdp;

Point dir[4] = {Point(-1, 0), Point(0, -1), Point(1, 0), Point(0, 1)};

inline bool valid(Point P) {
  return (1 <= P.x && P.x <= n && 1 <= P.y && P.y <= m);
}

double dijkstra(Point st, Point ed) {
  priority_queue<pdp, vector<pdp>, greater<pdp> > pq;
  for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) dis[i][j] = 1e18;
  dis[st.x][st.y] = 0;
  pq.push(make_pair(0, st));
  while (!pq.empty()) {
    pdp cur = pq.top();
    pq.pop();
    Point u = cur.second;
    double dist = cur.first;
    if (dist > dis[u.x][u.y]) continue;
    if (u == ed) break;
    for (int k = 0; k < 4; k++) {
      Point v = u + dir[k];
      if (valid(v) && a[v.x][v.y] + dist < dis[v.x][v.y]) {
        dis[v.x][v.y] = a[v.x][v.y] + dist;
        pq.push(make_pair(dis[v.x][v.y], v));
      }
    }
  }
  return dis[ed.x][ed.y];
}

int main() {
  ifstream fin;
  ofstream fout;
  fin.open("../src/data.in");
  fout.open("../src/correct.out");
  fin >> n >> m;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      fin >> grid[i][j];
      a[i][j] = grid[i][j];
    }
  fin >> t;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      for (int k = 0; k < 4; k++) {
        Point P = Point(i, j) + dir[k];
        if (valid(P)) a[P.x][P.y] += t * grid[i][j];
      }
    }
  Point st, ed;
  fin >> st.x >> st.y >> ed.x >> ed.y;
  st = st + Point(1, 1);
  ed = ed + Point(1, 1);
  fout << setiosflags(ios::fixed) << setprecision(3) << dijkstra(st, ed) << endl;
  return 0;
}
