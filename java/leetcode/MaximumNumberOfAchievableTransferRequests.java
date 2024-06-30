package java.leetcode;

public class MaximumNumberOfAchievableTransferRequests {
    int max;
    int n;
    public int maximumRequests(int n, int[][] requests) {
        this.n = n;
        max = 0;
        int[] buildings = new int[n];
        maximizeRequests(buildings,requests,0,0);
        return max;
    }

    private void maximizeRequests(int[] buildings, int[][] requests, int requestToServe,int servedRequest) {
        if(requestToServe==requests.length){
            for (int i = 0; i < n; i++) {
                if(buildings[i]!=0){
                    return;
                }
            }
            max = Math.max(max,servedRequest);
            return;
        }
        int fromBuilding = requests[requestToServe][0];
        int toBuilding   = requests[requestToServe][1];
        buildings[fromBuilding]--;
        buildings[toBuilding]++;
        maximizeRequests(buildings,requests,requestToServe+1,servedRequest+1);
        buildings[fromBuilding]++;
        buildings[toBuilding]--;
        maximizeRequests(buildings,requests,requestToServe+1,servedRequest);

    }
}
