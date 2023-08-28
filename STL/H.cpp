#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <cinttypes>

class Graph {
public:
  void BuildGraph ();
  void FindDistances ();
  void PrintDistances ();
private:
  std::vector<std::vector<uint32_t>> list_;
  std::vector<uint32_t> distance_;
  std::vector<bool> passed_;
  uint32_t n_;
  uint32_t m_;
};

void Graph::BuildGraph () {
  std::cin >> n_ >> m_;
  list_.resize (n_);
  distance_.resize (n_);
  passed_.resize (n_);
  uint32_t u, v;
  for (size_t i = 0; i < m_; ++i) {
    std::cin >> u >> v;
    list_[u].push_back (v);
    list_[v].push_back (u);
  }
}

void Graph::FindDistances () {
  std::queue<uint32_t> bfs;
  passed_[0] = true;
  bfs.push(0);
  while (!bfs.empty()) {
    uint32_t cur = bfs.front();
    bfs.pop();
    for (auto i : list_[cur]) {
      if (!passed_[i] || distance_[cur] + 1 < distance_[i]) {
        distance_[i] = distance_[cur] + 1;
        passed_[i] = true;
        bfs.push(i);
      }
    }
  }
}

void Graph::PrintDistances () {
    for (size_t i = 0; i < n_; ++i) {
        std::cout << distance_[i] << std::endl;
    }
}

int main () {
  Graph g;
  g.BuildGraph();
  g.FindDistances();
  g.PrintDistances();
  return 0;
}