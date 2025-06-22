# 🔢 Maximum Product Subarray

---

## 📘 Problem Statement

Given an array `arr[]` that contains **positive**, **negative**, and **zero** values, find the **maximum product** among all possible **contiguous subarrays**.

> ✅ The output is guaranteed to fit in a 32-bit signed integer.

---

## 🧪 Examples

| Input                      | Output | Explanation                    |
|---------------------------|--------|--------------------------------|
| `[-2, 6, -3, -10, 0, 2]`   | 180    | Subarray: `[6, -3, -10]`       |
| `[-1, -3, -10, 0, 6]`      | 30     | Subarray: `[-3, -10]`          |
| `[2, 3, 4]`                | 24     | Subarray: `[2, 3, 4]`          |
| `[-2, 0, -1]`              | 0      | Subarray: `[0]`                |

---

## 🧪 Constraints

- `1 ≤ arr.length ≤ 10^6`
- `-10 ≤ arr[i] ≤ 10`

---

## 💡 Approach 1: Brute Force (Nested Loops)

### 🔹 Idea

Try all possible subarrays using two nested loops and compute the product of each. Track the maximum product.

---

### 🧾 Code

```cpp

int maxProduct(vector<int>& arr) {
    int n = arr.size();
    int result = arr[0];

    for (int i = 0; i < n; i++) {
        int mul = 1;
        for (int j = i; j < n; j++) {
            mul *= arr[j];
            result = max(result, mul);
        }
    }
    return result;
}

```
# 🔢 Maximum Product Subarray

---

## 📈 Time and Space Complexity (Brute Force)

| Metric           | Value   |
|------------------|---------|
| Time Complexity  | O(n²)   |
| Space Complexity | O(1)    |

---

## ✅ Approach 2: Optimal (Kadane’s Variant for Product)

### 🔹 Idea

Track both the **maximum** and **minimum** product ending at each index.  
A negative number can turn a small **minimum** into a large **maximum**.

---

### 🔁 Transition Logic

```cpp

if (arr[i] < 0) swap(maxProd, minProd);

maxProd = max(arr[i], arr[i] * maxProd);
minProd = min(arr[i], arr[i] * minProd);
res = max(res, maxProd);
```
## 🧾 Code

```cpp
class Solution {
public:
    int maxProduct(vector<int>& arr) {
        int res = arr[0];
        int maxProd = arr[0];
        int minProd = arr[0];

        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] < 0) swap(maxProd, minProd);

            maxProd = max(arr[i], arr[i] * maxProd);
            minProd = min(arr[i], arr[i] * minProd);

            res = max(res, maxProd);
        }
        return res;
    }
};
```
## 📊 Time and Space Complexity

| Metric           | Value |
|------------------|-------|
| Time Complexity  | O(n)  |
| Space Complexity | O(1)  |
| In-place?        | ✅ Yes |
