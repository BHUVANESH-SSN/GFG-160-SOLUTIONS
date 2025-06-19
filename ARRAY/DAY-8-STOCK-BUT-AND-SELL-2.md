#  Best Time to Buy and Sell Stock – One Transaction Allowed

---

## 📘 Problem Statement

Given an array `prices[]` of length `N`, where `prices[i]` denotes the price of a stock on day `i`, your task is to **find the maximum profit possible with at most one transaction** (1 buy and 1 sell).  
You must **buy before you sell**.

---

## 🧪 Examples

### Example 1
**Input:** `prices = [7, 10, 1, 3, 6, 9, 2]`  
**Output:** `8`  
**Explanation:** Buy at `1`, sell at `9` → Profit = `9 - 1 = 8`

---

### Example 2
**Input:** `prices = [7, 6, 4, 3, 1]`  
**Output:** `0`  
**Explanation:** No profit possible as prices are decreasing.

---

### Example 3
**Input:** `prices = [1, 3, 6, 9, 11]`  
**Output:** `10`  
**Explanation:** Buy at `1`, sell at `11` → Profit = `10`

---


## ❌ Naive Approach – O(n²)

### 🔹 Idea:
Use two nested loops to try all combinations of buy-sell pairs.

### ✅ Code:
```cpp

int maxProfit(vector<int> &prices) {  
    int n = prices.size();
    int res = 0;

    
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            res = max(res, prices[j] - prices[i]);
        }
    }
    return res;
}


```

## ✅ Expected Approach – One Traversal (O(n))
### 🔹 Idea:
Keep track of the minimum price so far and at every step, calculate the profit and update the result if it’s greater.
## CODE 
```cpp

int maxProfit(vector<int> &prices) {
    int minSoFar = prices[0];
    int res = 0;

    for (int i = 1; i < prices.size(); i++) {
        minSoFar = min(minSoFar, prices[i]);             
        res = max(res, prices[i] - minSoFar);           
    }

    return res;
}


```

## 📊 Time and Space Complexity

| Approach             | Time Complexity | Space Complexity | Notes                        |
|----------------------|------------------|-------------------|------------------------------|
| Naive (Nested Loops) | O(n²)            | O(1)              | ❌ Too slow for large n       |
| Optimal (One-Pass)   | O(n)             | O(1)              | ✅ Best for interviews/tasks  |

---

## 📌 Summary

- Use the **O(n²)** brute-force approach only for **learning or conceptual clarity**.
- The **O(n)** one-pass solution is optimal for **interviews and production use**.
- This problem is a classic case of **greedy strategy using min-so-far tracking**.

