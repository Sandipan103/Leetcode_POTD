#define pii pair<int, int>

class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        
        vector<int> indeg(n, 0), topo;
        vector<vector<int>> adj(n);

        for(auto &it : relations)    
            it[1]--, it[0]--, indeg[it[1]]++, adj[it[0]].push_back(it[1]);

        priority_queue<pii, vector<pii>, greater<pii>> pq;
        int maxi = 0;

        for(int i=0; i<n; i++)  
            if(!indeg[i])   pq.push({time[i], i});

        while(!pq.empty())   {
            pii fr = pq.top();
            int u = fr.second, t = fr.first;
            pq.pop();
            maxi = max(maxi, t);
            for(auto it : adj[u])   {
                indeg[it]--;
                if(!indeg[it])  pq.push({t + time[it], it});
            }
        }
        return maxi;
    }
};