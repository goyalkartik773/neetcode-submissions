class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int,int>> cars;
        for(int i=0;i<n;i++) {
            cars.push_back({position[i], speed[i]});
        }
        sort(cars.begin(), cars.end());

        stack<double> st;
        double tm = (double)(target - cars[n-1].first) / cars[n-1].second;
        st.push(tm);

        for(int i=n-2;i>=0;i--) {
            tm = (double)(target - cars[i].first) / cars[i].second;

            if(tm > st.top()) {   // new fleet
                st.push(tm);
            }
            // else merge into fleet ahead
        }
        return st.size();
    }
};