class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> p;
        int n = position.size();
        
        for (int i = 0; i < n; i++) {
            pair<int, int> pi;
            pi.first = position[i];
            pi.second = speed[i];
            p.push_back(pi);
        }

        sort(p.rbegin(), p.rend());

        double max_time_taken = -1, ans = 0;
        double time_taken;
        
        for (int i = 0; i < n; i++) {
            time_taken =  ((double) (target - p[i].first)) / p[i].second;

            cout << time_taken << '\n';
            
            if (time_taken > max_time_taken) {
                ans++;
            }
            
            max_time_taken = max(time_taken, max_time_taken);
        }   

        return ans;
    }
};