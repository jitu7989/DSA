#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int ans = numBottles;

        int i = 0;
        while(numBottles>=numExchange){
            i++;
            cout << i << endl;
            int uncounted = (numExchange*(numExchange-1))/2;
            int vBottels = numBottles+uncounted;
            int n = (sqrt(1+(8*vBottels))-1.0)/2.0;
            int remaining = vBottels-((n*(n+1))/2);
            int bottlesDrank = (n-numExchange)+1;

            cout << "uncounted = " << uncounted << endl;
            cout << "vBottels = " << vBottels << endl;
            cout << "n = " << n << endl;
            cout << "remaining = " << remaining << endl;
            cout << "bottlesDrank = " << bottlesDrank << endl;

            ans += bottlesDrank;
            numBottles = bottlesDrank+remaining;
            numExchange = n+1;


            cout << "ans = " << ans << endl;
            cout << "numBottles = " << numBottles << endl;
            cout << "numExchange = " << numExchange << endl;
            cout << "==============\n";
        }
        return ans;
    }
};


int main() {
    Solution s;
    cout << s.maxBottlesDrunk(13,6) << '\n';
    cout << s.maxBottlesDrunk(10,3) << '\n';

}