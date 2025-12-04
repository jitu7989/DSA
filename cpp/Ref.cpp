//The following shortcuts are frequently used in both our C/C++ and Java code:

// ans = a ? b : c;                      --> to simplify: if (a) ans = b; else ans = c;
// ans += val;                           --> to simplify: ans = ans + val; and its variants
// index = (index + 1) % n; index++;     --> if (index >= n) index = 0;
// index = (index + n - 1) % n; index--; --> if (index < 0) index = n - 1;
// int ans = (int)((double)d + 0.5);     --> for rounding to nearest integer
// ans = min(ans, new_computation);      --> min/max shortcut
#include <bits/stdc++.h>
#include <pstl/utils.h>
using namespace std;

class Solution {
public:

    double getMax(int day, string currency, double amount, vector<map<string,pair<vector<double>,vector<string>>>> exchange) {
        if (day>2) return amount;

        double mx = 0.0;
        map<string,pair<vector<double>,vector<string>>> map = exchange[day-1];

        if (map.find(currency)!=map.end() && !map.find(currency)->second.first.empty()) {
            auto rates = map.find(currency)->second.first;
            auto values  = map.find(currency)->second.second;
            for (int i = 0; i < values.size(); ++i) {
                double change_rate = rates[i];
                double change_amount = amount*change_rate;

                double x = getMax(day,values[i],change_amount,exchange);
                mx = max(mx,x);
            }
        }

        return max(mx,getMax(day+1,currency, amount,exchange));
    }
    double maxAmount(string initialCurrency,
                     vector<vector<string>>& pairs1, vector<double>& rates1,
                     vector<vector<string>>& pairs2, vector<double>& rates2
    ) {
        double amount = 1.0;

        map<string,pair<vector<double>,vector<string>>> tradeMap,tradeMap2;
        for (int i = 0; i < pairs1.size(); ++i) {
            vector<string> tradePair = pairs1[i];
            tradeMap[tradePair[0]].first.push_back(rates1[i]);
            tradeMap[tradePair[0]].second.push_back(tradePair[1]);
        }

        for (int i = 0; i < pairs2.size(); ++i) {
            vector<string> tradePair = pairs2[i];
            tradeMap2[tradePair[0]].first.push_back(rates2[i]);
            tradeMap2[tradePair[0]].second.push_back(tradePair[1]);
        }


        return getMax(1,initialCurrency,amount,{tradeMap,tradeMap2});

    }
};


int main() {
    Solution s;
    vector<vector<int>> a = {{9,4},{19,5},{2,8},{3,11},{2,15}};

    vector<vector<string>> pairs1 = {{"EUR","USD"},{"USD","JPY"}};
    vector<double> rates1 = {2.0,3.0};
    vector<vector<string>> pairs2 = {{"JPY","USD"},{"USD","CHF"},{"CHF","EUR"}};
    vector<double> rates2 = {4.0,5.0,6.0};

    cout << s.maxAmount("EUR",pairs1,rates1,pairs2,rates2);
}
