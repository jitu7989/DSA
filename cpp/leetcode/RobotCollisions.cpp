#include <bits/stdc++.h>;
using namespace std;
using ll = long long;
using ii = pair<ll,ll>;

struct Robot{
    int position;
    int idx;
    int health;
    char direction;

};
bool compareByPosition(const Robot& p1, const Robot& p2) {
    return p1.position < p2.position;
}
bool compareByIdx(const Robot& p1, const Robot& p2) {
    return p1.idx < p2.idx;
}
class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        vector<Robot> robots;
        int n = positions.size();
        for (int i = 0; i < n; ++i) {
            Robot robo;
            robo.idx=i;
            robo.position=positions[i];
            robo.health=healths[i];
            robo.direction=directions[i];
            robots.push_back(robo);
        }
        sort(robots.begin(),robots.end(),compareByPosition);

        vector<Robot> survivors;
        stack<Robot> right;

        for (const auto &item: robots){
            if(item.direction=='L'){
                Robot collisionFromLeft = item;
                bool survived = true;
                while(!right.empty()){
                    Robot &collisionOnRight = right.top();
                    if(collisionOnRight.health==collisionFromLeft.health){
                        right.pop();
                        survived = false;
                        break;
                    }
                    else if(collisionFromLeft.health<collisionOnRight.health){
                        --collisionOnRight.health;
                        survived = false;
                        break;
                    }
                    else{
                        right.pop();
                        --collisionFromLeft.health;
                    }
                }
                if(survived) survivors.push_back(collisionFromLeft);
            }
            else {
                right.push(item);
            }
        }
        while(!right.empty()){
            survivors.push_back(right.top());
            right.pop();
        }
        sort(survivors.begin(),survivors.end(), compareByIdx);
        vector<int> h;
        for (const auto &item: survivors){
            h.push_back(item.health);
        }
        return h;
    }
};