#include <iostream>
#include <inttypes.h>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/boyer_myrvold_planar_test.hpp>


int main() {
  using namespace boost;

  typedef adjacency_list<vecS,
                         vecS,
                         undirectedS,
                         property<vertex_index_t, int>
                         > graph;

  graph g;
  uint32_t n, m;
  std::cin >> n >> m;
  uint32_t u, v;
  for (uint32_t i = 0; i < m; ++i) {
    std::cin >> u >> v;
    add_edge(u, v, g);
    add_edge(v, u, g);
  }

  if (boyer_myrvold_planarity_test(g)) {
    std::cout << "YES" << std::endl;
  }
  else {
    std::cout << "NO" << std::endl;
  }
 
  return 0;
}