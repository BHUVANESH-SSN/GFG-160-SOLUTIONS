#   DAY -10 📈 Maximum Subarray Sum (Kadane's Algorithm)

---

## 📘 Problem Statement

Given an integer array `arr[]`, find the **contiguous subarray** (containing at least one number) that has the **maximum sum**, and return that sum.

---

## 🧪 Examples

### Example 1:
**Input:** `arr = [2, 3, -8, 7, -1, 2, 3]`  
**Output:** `11`  
**Explanation:** The subarray `[7, -1, 2, 3]` gives the maximum sum.

---

### Example 2:
**Input:** `arr = [-2, -4]`  
**Output:** `-2`  
**Explanation:** The subarray `[-2]` gives the maximum sum.

---

### Example 3:
**Input:** `arr = [5, 4, 1, 7, 8]`  
**Output:** `25`  
**Explanation:** The entire array gives the maximum sum.

---

## 🔍 Naive Approach (O(n²) Time)

Try every possible subarray using two nested loops and track the maximum sum.

### 🔹 C++ Code:
```cpp

int maxSubarraySum(vector<int> &arr) {
    int res = arr[0];

    for (int i = 0; i < arr.size(); i++) {
        int currSum = 0;
        for (int j = i; j < arr.size(); j++) {
            currSum += arr[j];
            res = max(res, currSum);
        }
    }
    return res;
}


```

# ⚡ Kadane’s Algorithm – Maximum Subarray Sum (O(n) Time)

---

## 💡 Expected Approach – Kadane’s Algorithm

Kadane’s Algorithm helps find the **maximum subarray sum** in **O(n)** time with **O(1)** space.

### 🧠 Core Idea:

Maintain a variable `maxEnding` that stores the **maximum sum of subarrays ending at current index**. At each step:

- Extend the previous subarray: `maxEnding + arr[i]`
- OR start a new subarray: `arr[i]`
  
Then, track the global maximum `res` as the **maximum of all `maxEnding` values**.

---

## 🔹 C++ Code:

```cpp

int maxSubarraySum(vector<int> &arr) {
    int res = arr[0], maxEnding = arr[0];

    for (int i = 1; i < arr.size(); i++) {
        maxEnding = max(maxEnding + arr[i], arr[i]);
        res = max(res, maxEnding);
    }
    return res;
}


```
## 📊 Time and Space Complexity

| Approach             | Time Complexity | Space Complexity | Notes                          |
|----------------------|------------------|-------------------|-------------------------------|
| Naive (Nested Loops) | O(n²)            | O(1)              | ❌ Inefficient for large input |
| Kadane’s Algorithm   | O(n)             | O(1)              | ✅ Optimal, most efficient     |
