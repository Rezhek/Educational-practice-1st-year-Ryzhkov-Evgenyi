#include <iostream>
#include <vector>
#include <algorithm>

class SparceGraph {
 private:
    std::vector<std::vector<int>> g_;
    int vertex_count_;

 public:
    SparceGraph (int n) : vertex_count_(n) {
        g_.resize(n);
    }

    void AddEdge(int from, int to) {
        g_[from].push_back(to);
        g_[to].push_back(from);
    }
    
    std::vector<int> GetChildren(int v) const{
        return g_[v];
    }

    std::vector<std::vector<int>> Kosaraju() {
        std::vector<int> top_sort = TopSort();
        std::vector<bool> used(vertex_count_, false);
        std::vector<std::vector<int>> components;
        for(int i = 0; i < static_cast<int>(top_sort.size()); ++i) {
        int v = top_sort[i];
        if (!used[v]) {
            std::vector<int> component;
            DFSKosaraju(v, used, component);
            components.push_back(component);
        }
    }
    return components;
        
    }

 private:
     std::vector<int> TopSort() {
        std::vector<bool> used(vertex_count_, false);
        std::vector<int> top_sort;
        for (int i = 0; i < vertex_count_; ++i) {
            if (!used[i]) {
                DFSTopSort(i, used, top_sort);
            }
        }
        std::reverse(top_sort.begin(), top_sort.end());
        return top_sort;
    }

     void DFSTopSort(int v, std::vector<bool>& used, std::vector<int>& top_sort) {
        used[v] = true;
        std::vector<int> children = GetChildren(v);
        for (int i = 0; i < static_cast<int>(children.size()); ++i) {
            int ch = children[i];
            if (!used[v]) {
                DFSTopSort(ch, used, top_sort);
            }
        }
        top_sort.push_back(v);
    }

    void DFSKosaraju(int v, std::vector<bool>& used, std::vector<int>& component) {
        used[v] = true;
        component.push_back(v);
        std::vector<int> children = GetChildren(v);
        for (int i = 0; i < static_cast<int>(children.size()); ++i) {
            int ch = children[i];
            if (!used[ch]) {
                DFSKosaraju(ch, used, component);
            }
        }
    }
};

int main() {
    int n = 0;
    int m = 0;
    std::cin >> n >> m;
    SparceGraph G(n);
    int u = 0;
    int v = 0;
    for (int i = 0; i < m; ++i) {
        std::cin >> u >> v;
        --u;
        --v;
        G.AddEdge(u, v);
    }
    std::vector<std::vector<int>> components = G.Kosaraju();
    std::cout << components.size() - 1 << std::endl;
}