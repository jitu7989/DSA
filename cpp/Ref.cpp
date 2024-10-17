//The following shortcuts are frequently used in both our C/C++ and Java code:

// ans = a ? b : c;                      --> to simplify: if (a) ans = b; else ans = c;
// ans += val;                           --> to simplify: ans = ans + val; and its variants
// index = (index + 1) % n; index++;     --> if (index >= n) index = 0;
// index = (index + n - 1) % n; index--; --> if (index < 0) index = n - 1;
// int ans = (int)((double)d + 0.5);     --> for rounding to nearest integer
    // ans = min(ans, new_computation);      --> min/max shortcut