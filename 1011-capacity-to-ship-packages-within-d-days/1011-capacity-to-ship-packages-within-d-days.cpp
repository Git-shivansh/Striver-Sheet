class Solution {
    bool check(int mid , vector<int>&w , int days){
        int n = w.size() ;

        int sum =0 ;
        int cnt =1 ;
        for(int i =0 ; i <n  ; i++){
            if(sum + w[i] <= mid){
                sum += w[i];
            }
            else {
                cnt++;
                sum = w[i] ;
            }
        }
        return cnt <= days;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int lo = *max_element(weights.begin(), weights.end()) ;
        int hi = accumulate(weights.begin(), weights.end(), 0LL);
        int ans =0 ;
        while(lo <= hi){
            int mid = (lo + hi) / 2 ;
            
            if(check(mid , weights , days)){
                ans = mid ;
                hi = mid -1 ;
            }
            else {
                lo = mid + 1;
            }
        }
        return ans ;
    }
};