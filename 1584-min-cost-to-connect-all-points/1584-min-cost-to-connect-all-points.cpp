class Solution {
public:
    int manhattanDist(vector<int> &p1, vector<int> &p2)
    {
        return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]);
    }

    vector<int> parent, sz;

    int findSet(int node)
    {
        if (parent[node] == node)
            return node;
        return parent[node] = findSet(parent[node]);
    }

    void unionSet(int u, int v)
    {
        int pu = findSet(u);
        int pv = findSet(v);

        if (pu == pv)
            return;

        if (sz[pu] >= sz[pv])
        {
            parent[pv] = pu;
            sz[pu] += sz[pv];
        }
        else
        {
            parent[pu] = pv;
            sz[pv] += sz[pu];
        }
    }

    int minCostConnectPoints(vector<vector<int>> &points)
    {
        int n = points.size();

        parent.resize(n);
        sz.assign(n, 1);

        for (int i = 0; i < n; i++)
            parent[i] = i;

        vector<tuple<int, int, int>> edges;

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int dist = manhattanDist(points[i], points[j]);
                edges.push_back({dist, i, j});
            }
        }

        sort(edges.begin(), edges.end());

        int cost = 0;
        int edgesTaken = 0;

        for (auto &[w, u, v] : edges)
        {
            if (findSet(u) != findSet(v))
            {
                unionSet(u, v);
                cost += w;
                edgesTaken++;

                if (edgesTaken == n - 1)
                    break;
            }
        }

        return cost;
    }
};