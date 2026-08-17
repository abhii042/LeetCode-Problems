class Solution {
public:
    int minOperations(string s) {
        int n=s.size();
        string dorivexalu=s;

        int ans=INT_MAX;
        for(int k=0; k<n; k++){
            int cost=0;
            for(int i=0;i<n/2;i++){
                int left=dorivexalu[(i+k)%n]-'a';
                int right=dorivexalu[(n-1-i+k)%n]-'a';
                int diff = abs(left-right);
                cost +=min(diff,26-diff);
            }
            ans=min(ans,k+cost);
            
        }
        return ans;
    }
};