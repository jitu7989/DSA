#include <bits/stdc++.h>
using namespace std;

// When to use if for certain LR point criteria(l,r) is true then for criteria(l+(...(r-l)),r) should be true
int main() {
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; ++i) cin >> arr[i];

    // head starts at -1 cause template checks is there a next element to eat to that can create a window initial window length remains zero
    // tail=0, head=-1 length = tail-head+1 = 0-1+1 = 0
    int tail = 0, head = -1;

    int zero = 0;
    int ans = 0;
    //  T=Tail   H=Head
    //  HT
    // [_.                 ]
    //  Head Moves till it can move if it can't stops
    // T      H
    // [.     -            ]
    // Head Signals it can't move futher tails move forwards descresing window length
    //   T    H
    // [ .    -            ]
    // IF tail Surpasses Head
    //       HT
    // [     -.            ]
    // Both Points to smae index
    //       TH
    // [     -            ]
    while (tail < n) {
        //is there a next elements to eat and we can eat it
        int nextElementIdx = head + 1;
        while (nextElementIdx < n && (zero < k || arr[nextElementIdx] == 1) /*condition default could be (nextElemenet<n && (Application Condition)) */) {
            // Pre increment Application Logic
            // if (arr[nextElementIdx]==0) zero++;

            // includes element in window
            head++;

            // Post increment Application Logic
            if (arr[head] == 0) zero++;
        }
        //logic needed to perform by according problem statement
        ans = max(ans, head - tail + 1);

        // resetting to window length to zero
        if (tail > head) {
            tail++;
            head = tail - 1;
        } else {
            // Pre Increment Application Logic
            if (arr[tail] == 0) zero--;

            //removes tail element in window
            tail++;

            // Post Increment Application Logic
        }
    }

    cout << ans << '\n';
}
