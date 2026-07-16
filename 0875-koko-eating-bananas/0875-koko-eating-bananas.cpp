class Solution {
    private :
    bool check(int mid , vector<int>&nums , int h ){
        long long ans = 0 ;

        for(int i = 0;i < nums.size() ;  i++){
            ans += (nums[i] + mid -1 )/ mid ;
        }
        return ans <= h;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long lo = 1;
        long long hi = *max_element(piles.begin() , piles.end());
        long long ans = 0 ;

        while(lo <= hi){
            int mid = (lo + hi)/2 ;

            if(check(mid , piles , h)){
                ans = mid ;
                hi = mid - 1;
            }
            else {
                lo = mid + 1;
            }
        }
        return ans ;
    }
};