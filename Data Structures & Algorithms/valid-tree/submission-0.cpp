class Solution {
public:
    bool isConnected(vector<bool> &visited) {
        for (auto i: visited)
            if (!i) 
                return false;
        return true;
    }

    bool dfs(vector<vector<int>> &adjList, vector<bool> &visited, int num, int parent) {
        visited[num] = true;

        for (auto i: adjList[num]) {
            if (visited[i]){
                if (i != parent) 
                    return false;
            } else 
                if (!dfs(adjList, visited, i, num)) return false;   
        }
        return true;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(n);
        vector<bool> visited(n, false);

        for (int i = 0; i < edges.size(); i++) {
            adjList[edges[i][0]].push_back(edges[i][1]);
            adjList[edges[i][1]].push_back(edges[i][0]);
        }

        return dfs(adjList, visited, 0, -1) && isConnected(visited);
    }
};
