#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int mirrorReflection(int p, int q)
    {
        int x = __gcd(p, q);
        p /= x;
        q /= x;

        if (p % 2 == 1 && q % 2 == 1)
        {
            return 1;
        }
        if (p % 2 == 0 && q % 2 == 1)
        {
            return 2;
        }
        return 0;
    }
};
