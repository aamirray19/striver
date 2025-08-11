#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int arrangeCoins(int n) 
    {
        int start = 0;
        int end = n;

        while (start <= end)
        {
            long long mid = start + (end-start)/2;
            long long coins = (mid*(mid+1))/2;

            if (coins == n)
            {
                return mid;
            }
            else if(coins > n)
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        return end;
    }
};


/*The provided code is designed to solve the problem of arranging `n` coins into a staircase pattern. The goal is to find the maximum number of complete rows that can be formed.

The formula used in the solution is:
\[
\text{coins in k rows} = \frac{k \cdot (k + 1)}{2}
\]
This is the sum of the first `k` natural numbers. The binary search is used to efficiently find the maximum `k` such that the number of coins used (\(\text{coins}\)) does not exceed `n`.

---

### Dry Run of the Solution

#### Input:
`n = 8`

---

### **Initial Values**:
- `start = 0`, `end = 8`

---

### Iterations:

1. **First Iteration**:
   - Calculate `mid = start + (end - start) / 2 = 0 + (8 - 0) / 2 = 4`.
   - Calculate `coins = (4 * (4 + 1)) / 2 = (4 * 5) / 2 = 10`.
   - Compare `coins` with `n`:
     - `coins (10) > n (8)` → Update `end = mid - 1 = 4 - 1 = 3`.

---

2. **Second Iteration**:
   - Calculate `mid = start + (end - start) / 2 = 0 + (3 - 0) / 2 = 1`.
   - Calculate `coins = (1 * (1 + 1)) / 2 = (1 * 2) / 2 = 1`.
   - Compare `coins` with `n`:
     - `coins (1) < n (8)` → Update `start = mid + 1 = 1 + 1 = 2`.

---

3. **Third Iteration**:
   - Calculate `mid = start + (end - start) / 2 = 2 + (3 - 2) / 2 = 2`.
   - Calculate `coins = (2 * (2 + 1)) / 2 = (2 * 3) / 2 = 3`.
   - Compare `coins` with `n`:
     - `coins (3) < n (8)` → Update `start = mid + 1 = 2 + 1 = 3`.

---

4. **Fourth Iteration**:
   - Calculate `mid = start + (end - start) / 2 = 3 + (3 - 3) / 2 = 3`.
   - Calculate `coins = (3 * (3 + 1)) / 2 = (3 * 4) / 2 = 6`.
   - Compare `coins` with `n`:
     - `coins (6) < n (8)` → Update `start = mid + 1 = 3 + 1 = 4`.

---

5. **Loop Exit**:
   - The loop ends because `start > end` (`start = 4`, `end = 3`).

---

### **Final Step**:
- The function returns `end = 3`, which is the maximum number of complete rows that can be formed with 8 coins.

---

### **Output**:
`3`

---

### **Execution Summary**:

| Iteration | `start` | `end` | `mid` | `coins` | Comparison           | Updated Range |
|-----------|---------|-------|-------|---------|----------------------|----------------|
| 1         | 0       | 8     | 4     | 10      | `coins > n`          | `start = 0, end = 3` |
| 2         | 0       | 3     | 1     | 1       | `coins < n`          | `start = 2, end = 3` |
| 3         | 2       | 3     | 2     | 3       | `coins < n`          | `start = 3, end = 3` |
| 4         | 3       | 3     | 3     | 6       | `coins < n`          | `start = 4, end = 3` |

**Final Output**: `3`*/