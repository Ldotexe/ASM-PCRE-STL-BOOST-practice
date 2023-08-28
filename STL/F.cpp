#include <iostream>
#include <vector>
#include <stack>
#include <cinttypes>

class Graph{
public:
    void GraphCtor ();
    uint32_t FindMinBridges();
private:
    std::vector<std::vector<uint32_t>> list;
    std::vector<bool> connected;
    uint32_t n;
    uint32_t m;
};

void Graph::GraphCtor () {
    std::cin >> n >> m;
    list.resize(n);
    connected.resize(n);
    connected[0] = true;
}

uint32_t Graph::FindMinBridges () {
    uint32_t u, v;
    uint32_t progress = 1;
    std::stack<uint32_t> dfs;
    for (uint32_t i = 0; i < m; ++i) {
        std::cin >> u >> v;
        list[u].push_back(v);
        list[v].push_back(u);
        if (connected[u] == true && connected[v] == false) {
            dfs.push(v);
        }
        if (connected[v] == true && connected[u] == false) {
            dfs.push(u);
        }
        while (!dfs.empty()) {
            uint32_t cur = dfs.top();
            dfs.pop();
            if (!connected[cur]) {
                for (uint32_t j : list[cur]) {
                    if (!connected[j]) {
                        dfs.push(j);
                    }
                }
                connected[cur] = true;
                ++progress;
            }
        }
        if (progress == n) {
            return i + 1;
        }
    }
    return m;
}

int main () {
    Graph g;
    g.GraphCtor();
    std::cout << g.FindMinBridges() << std::endl;
    return 0;
}