# 💹 Maximize Stock Profit (Unlimited Transactions)

Given an array `prices[]` of size `n` representing the stock price on each day, your task is to **maximize total profit** by buying and selling stocks **any number of times**.

### 🔒 Constraints:
- You must sell the stock before buying again (no multiple holdings).
- You can complete as many transactions as you want.

---

## 🧪 Examples

### Example 1
**Input:**  
`prices = [100, 180, 260, 310, 40, 535, 695]`  
**Output:**  
`865`

**Explanation:**
- Buy at 100, Sell at 310 → Profit = 210  
- Buy at 40, Sell at 695 → Profit = 655  
- **Total Profit = 865**

---

### Example 2
**Input:**  
`prices = [4, 2, 2, 2, 4]`  
**Output:**  
`2`  
**Explanation:**
- Buy at 2, Sell at 4 → Profit = 2

---

## 🧮 Approaches

---

### 🔁 Naive Recursive Approach (Exponential Time)

Check all valid pairs `(i, j)` such that `price[i] < price[j]` and `j > i`, calculate profit, and recursively explore the left and right subarrays.

```cpp
#include <iostream>
#include <vector>
using namespace std;

int maxProfitRec(vector<int> &price, int start, int end) {
    int res = 0;

    for (int i = start; i < end; i++) {
        for (int j = i + 1; j <= end; j++) {
            if (price[j] > price[i]) {
                int curr = (price[j] - price[i]) +
                           maxProfitRec(price, start, i - 1) +
                           maxProfitRec(price, j + 1, end);
                res = max(res, curr);
            }
        }
    }
    return res;
}
```

### ⏱ Time & Space Complexity (Naive Recursion)

- **Time Complexity:** `O(2^n)`
- **Space Complexity:** `O(1)` (ignoring recursion stack)

---

## ✅ Optimal Greedy Solution – Accumulate Profit (O(n) Time)

**🧠 Idea:**  
Add profit on every day where `prices[i] > prices[i-1]` — this simulates buying at the local minima and selling at the local maxima.

```cpp
class Solution {
  public:
    int maximumProfit(vector<int> &prices) {
        int profit = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > prices[i - 1]) {
                profit += prices[i] - prices[i - 1];
            }
        }
        return profit;
    }
};
```
---
