class Solution {
public:
    std::vector<bool> canVisit;
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        canVisit.resize(n);

        int current = 0;
        dfs(current, rooms);

        int visited = std::accumulate(canVisit.begin(), canVisit.end(), 0);
        if (visited == n){

            return true;
        }
        return false;
    }

    void dfs(int at, vector<vector<int>>& rooms){

        if (canVisit[at]){ return; }
        else {
            canVisit[at] = true;
            for (int key : rooms[at]){

                dfs(key, rooms);
            }
        }
    }
};
