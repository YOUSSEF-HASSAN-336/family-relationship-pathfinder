#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
using namespace std;

int shortestRelationship(unordered_map<int, vector<int>>& tree, int start, int end) {
    if (start == end) return 0;

    unordered_set<int> visited;
    queue<pair<int, int>> q;

    q.push({start, 0});
    visited.insert(start);

    while (!q.empty()) {
        auto [current, depth] = q.front();
        q.pop();

        for (int neighbor : tree[current]) {
            if (neighbor == end)
                return depth + 1;

            if (!visited.count(neighbor)) {
                visited.insert(neighbor);
                q.push({neighbor, depth + 1});
            }
        }
    }

    return -1;
}

int main() {
    unordered_map<int, vector<int>> tree;
    int numEdges;
    cin >> numEdges;

    for (int i = 0; i < numEdges; ++i) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    int start, end;
    cin >> start >> end;

    int result = shortestRelationship(tree, start, end);

    if (result != -1)
        cout << result << endl;
    else
        cout << "No relationship path found." << endl;

    return 0;
}
