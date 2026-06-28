class DSU {
    public:
        vector<int> parent;

        DSU(int n) {
            parent.resize(n);
            for (int i = 0; i < n; i++)
                parent[i] = i;
        }

        int find(int x) {
            if (x == parent[x]) {
                return x;
            }
            return parent[x] = find(parent[x]);
        }

        void unite(vector<int> v) {
            int lx = find(v[0]);
            int ly = find(v[1]);

            if (lx != ly) {
                parent[ly] = lx;
            }
        }
};

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        DSU dsu(n);
        unordered_set<int> s;

        for (auto edge: edges) {
            dsu.unite(edge);
        }

        for (auto a: dsu.parent) {
            s.insert(dsu.find(a));
        }
        return s.size();
    }
};
