#include <iostream>
#include <vector>

using namespace std;

struct Edge {
    int u, v, w;
};
vector<Edge> edges;
vector<vector<Edge>> adj;

vector<int> dist;
bool BellmanFord(vector<Edge> &edges, int n, int s) {
    dist.resize(n, INT_MAX);
    dist[s] = 0;
    bool negtiveCycle;
    for(int i = 0; i < n; ++i) {
        negtiveCycle = false;
        for(auto e: edges) {
            if(dist[e.u] != INT_MAX && dist[e.v] > dist[e.u] + e.w) {
                dist[e.v] = dist[e.u] + e.w;
                negtiveCycle = true;
            }
        }
        if(!negtiveCycle) break;
    }
    return negtiveCycle;
}

int main() {
    int n = 5;
    edges = {{1,2,3}, {3,2,4}, {1,3,8}, {2,4,1}, {2,5,7}, {1,5,-4}, {4,1,2}, {5,4,6}, {4,3,-5}};

    // 构建新图 G'
    vector<Edge> edges_new = edges;
    for(int v = 1; v <= 5; ++v) {
        edges_new.push_back({0, v, 0});
    }
    int s = 0;
    bool hasCycle = BellmanFord(edges_new, 6, s);

    cout << " has nagetive cycle" << hasCycle << endl;

    return 0;
}

