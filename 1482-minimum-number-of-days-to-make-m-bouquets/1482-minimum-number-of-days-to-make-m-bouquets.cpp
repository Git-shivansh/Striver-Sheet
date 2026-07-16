class Solution {
public:
    bool possible(vector<int>& bloomDay, int m, int k, int day) {
        int cnt = 0;
        int bouquets = 0;
        for(int x : bloomDay) {
            if(x <= day) {
                cnt++;
            }
            else {
                cnt = 0;
            }

            if(cnt == k) {
                bouquets++;
                cnt = 0;
            }
        }

        return bouquets >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {

        long long need = 1LL * m * k;

        if(need > bloomDay.size()) return -1;

        int lo = *min_element(bloomDay.begin(), bloomDay.end());
        int hi = *max_element(bloomDay.begin(), bloomDay.end());

        int ans = -1;

        while(lo <= hi) {
            int mid = lo + (hi - lo)/2;
            if(possible(bloomDay, m, k, mid)) {
                ans = mid;
                hi = mid - 1;
            }
            else {
                lo = mid + 1;
            }
        }

        return ans;
    }
};