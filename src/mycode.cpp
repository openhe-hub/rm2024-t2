#include <bits/stdc++.h>

#define INF 0x3f3f3f3f

using namespace std;

typedef pair<int, int> pii;
vector<pii> directions = {{1.,  0.},
                          {-1., 0.},
                          {0.,  1.},
                          {0.,  -1.}};


void inflate(vector<vector<double>> &grid, double inflation_rate) {
  int rows = grid.size();
  int cols = grid[0].size();
  // calc inflation matrix
  vector<vector<double>> delta(rows, vector<double>(cols, 0.));
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; ++j) {
      for (pii dir: directions) {
        int new_x = i + dir.first;
        int new_y = j + dir.second;
        if (new_x >= 0 && new_x < rows && new_y >= 0 && new_y < cols) {
          delta[new_x][new_y] += grid[i][j] * inflation_rate;
        }
      }
    }
  }
  // sum up
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; ++j) {
      grid[i][j] += delta[i][j];
    }
  }
}

double dijkstra(vector<vector<double>> &grid, pii start, pii end) {
  int rows = grid.size();
  int cols = grid[0].size();
  priority_queue<pair<double, pii>, vector<pair<double, pii>>, greater<>> pq;
  vector<vector<double>> distances(rows, vector<double>(cols, INF));

  pq.push({0, start});
  distances[start.first][start.second] = 0;

  while (!pq.empty()) {
    double distance = pq.top().first;
    pii current = pq.top().second;
    pq.pop();

    if (current == end) {
      return distance;
    }

    for (pii dir: directions) {
      int new_x = current.first + dir.first;
      int new_y = current.second + dir.second;

      if (new_x >= 0 && new_x < rows && new_y >= 0 && new_y < cols) {
        double new_distance = distance + grid[new_x][new_y];

        if (new_distance < distances[new_x][new_y]) {
          distances[new_x][new_y] = new_distance;
          pq.push({new_distance, {new_x, new_y}});
        }
      }
    }
  }

  return -1; // no path found
}

int main() {
  ifstream fin;
  ofstream fout;
  fin.open("../src/data.in");
  fout.open("../src/mycode.out");
  // input
  int n = 0, m = 0;
  double inflation_factor = .0;
  pii start = {0, 0}, end = {0, 0};
  vector<vector<double>> grid;
  fin >> n >> m;
  for (int i = 0; i < n; ++i) {
    vector<double> vec;
    for (int j = 0; j < m; ++j) {
      double tmp = .0;
      fin >> tmp;
      vec.push_back(tmp);
    }
    grid.push_back(vec);
  }
  fin >> inflation_factor;
  fin >> start.first >> start.second >> end.first >> end.second;

  inflate(grid, inflation_factor);
  double shortestPath = dijkstra(grid, start, end);
  fout <<setiosflags(ios::fixed) << setprecision(3) << shortestPath << endl;

  return 0;
}