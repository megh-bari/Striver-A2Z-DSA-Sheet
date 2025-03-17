#include <bits/stdc++.h>
using namespace std;

/*
    This is a helper function 'knows'.
    You should not implement or modify it.

    bool knows(int A, int B);
    Function 'knows(A, B)' returns "true" if person A knows person B, otherwise "false".
*/

int findCelebrity(int n) {
    int top = 0;
    int down = n - 1;

    // Find celebrity
    while (top < down) {
        if (knows(top, down)) {
            // If top knows down, top cannot be the celebrity
            top++;
        } else {
            // If top does not know down, down cannot be the celebrity
            down--;
        }
    }

    int candidate = top;

    // Verify celebrity
    for (int i = 0; i < n; i++) {
        if (i != candidate) {
            if (knows(candidate, i) || !knows(i, candidate)) {
                return -1;
            }
        }
    }

    return candidate;
}
