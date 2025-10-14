class Solution {
public:
    int findSet(vector<int> &parent, int a) {
        if (parent[a] == a) return a;
        return parent[a] = findSet(parent, parent[a]); // path compression
    }

    void Union(vector<int> &parent, vector<int> &rankv, int a, int b) {
        a = findSet(parent, a);
        b = findSet(parent, b);
        if (a == b) return;

        if (rankv[a] < rankv[b]) {
            parent[a] = b;
        } else if (rankv[a] > rankv[b]) {
            parent[b] = a;
        } else {
            parent[b] = a;
            rankv[a]++; // union by rank
        }
    }

    struct Edge {
        int src;
        int dest;
        int wt;
    };

    static bool cmp(const Edge &e1, const Edge &e2) {
        return e1.wt < e2.wt;
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<Edge> edges;

        // Generate all possible edges with Manhattan distances
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                edges.push_back({i, j, dist});
            }
        }

        // Sort edges by weight
        sort(edges.begin(), edges.end(), cmp);

        // Initialize Union-Find data structure
        vector<int> parent(n);
        vector<int> rankv(n, 1);
        for (int i = 0; i < n; i++) parent[i] = i;

        int edgeCount = 0; // Need n-1 edges
        int ans = 0;

        // Kruskal's algorithm
        for (const Edge &curr : edges) {
            if (edgeCount == n - 1) break;

            int srcPar = findSet(parent, curr.src);
            int destPar = findSet(parent, curr.dest);

            if (srcPar != destPar) { // Adding this edge won't create a cycle
                Union(parent, rankv, srcPar, destPar);
                ans += curr.wt;
                edgeCount++;
            }
        }

        return ans; // Total weight of MST
    }
};
