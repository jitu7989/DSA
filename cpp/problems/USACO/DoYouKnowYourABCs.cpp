#include <bits/stdc++.h>
using namespace std;

int main() {


    vector<int> arr(7);
    for(int i=0;i<7;i++) {
        cin>>arr[i];
    }

    sort(arr.begin(),arr.end());
    int ab = arr[0]+arr[1];
    int c = 0;

    cout << arr[0] << " " << arr[1] << ' ';
    if (ab==arr[2]) {
        cout << arr[3];
    }
    else {
        cout << arr[2];
    }


}
