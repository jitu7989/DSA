#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("buckets.in", "r", stdin);
    freopen("buckets.out", "w", stdout);

    vector<string> board(10);
    for (int i = 0; i < 10; ++i) {
        cin >> board[i];
    }


    pair<int,int> lake, fire, rock;
    for (int a = 0; a < 10; ++a) {
        string basic_string  = board[a];
        for (int i = 0; i < 10; ++i) {
            if (basic_string[i]=='L') {
                lake.first = a;
                lake.second = i;
            }
            if (basic_string[i]=='B') {
                fire.first = a;
                fire.second = i;
            }
            if (basic_string[i]=='R') {
                rock.first = a;
                rock.second = i;
            }
        }
    }

    int ans = (abs(fire.first - lake.first)+abs(fire.second - lake.second)-1);
    if(
        (fire.first==lake.first && fire.first==rock.first && min(fire.second,lake.second)<=rock.second && rock.second<=max(fire.second,lake.second) )||
        (fire.second==lake.second && fire.second==rock.second && min(fire.first,lake.first)<=rock.first && rock.first<=max(fire.first,lake.first))
    )
    {
        ans += 2;
    }

    cout << ans;


}