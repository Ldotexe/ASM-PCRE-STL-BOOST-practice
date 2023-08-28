#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <cinttypes>

class Graph {
public:
  void BuildGraph ();
  std::vector<uint32_t> FindPath ();
private:
  std::vector<std::vector<std::pair<uint32_t, uint32_t>>> list_;
  std::vector<uint32_t> distance_;
  std::vector<uint32_t> previous_;
  std::vector<bool> passed_;
  uint32_t n_;
  uint32_t m_;  
  uint32_t start_;
  uint32_t finish_;
};

void Graph::BuildGraph () {
  std::cin >> n_ >> m_ >> start_ >> finish_;
  list_.resize (n_);
  distance_.resize (n_);
  previous_.resize(n_);
  passed_.resize (n_);
  uint32_t u, v, w;
  for (size_t i = 0; i < m_; ++i) {
    std::cin >> u >> v >> w;
    list_[u].push_back (std::make_pair (v, w));
    list_[v].push_back (std::make_pair (u, w));
  }
}

std::vector<uint32_t> Graph::FindPath () {
  std::vector<uint32_t> path;
  std::queue<uint32_t> bfs;
  passed_[start_] = true;
  bfs.push(start_);
  while (!bfs.empty()) {
    uint32_t cur = bfs.front();
    bfs.pop();
    for (auto i : list_[cur]) {
      if (!passed_[i.first] || i.second + distance_[cur] < distance_[i.first]) {
        distance_[i.first] = i.second + distance_[cur];
        previous_[i.first] = cur;
        passed_[i.first] = true;
        bfs.push(i.first);
      }
    }
  }
  uint32_t cur = finish_;
  while (cur != start_) {
    path.push_back(cur);
    cur = previous_[cur];
  }
  path.push_back(cur);
  std::reverse(path.begin(), path.end());
  return path;
}

int main () {
  Graph g;
  g.BuildGraph();
  std::vector<uint32_t> ans = g.FindPath();
  for (size_t i = 0; i < ans.size(); ++i) {
    std:: cout << ans[i] << " ";
  }
  std::cout << std::endl;
  return 0;
}