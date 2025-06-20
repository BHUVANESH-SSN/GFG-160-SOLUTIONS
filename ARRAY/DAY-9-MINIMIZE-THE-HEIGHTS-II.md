# 🏰 DAY 9- Minimize Maximum Height Difference Between Towers 

---

## 📘 Problem Statement

You are given an array `arr[]` of size `n`, representing the heights of towers, and a positive integer `k`.  
You are allowed to **increase or decrease** each height by **`k` only once**.

Your task is to **minimize the difference between the tallest and the shortest tower** after the modification.

---

## 🧪 Examples

### Example 1:
**Input:**  
`arr = [12, 6, 4, 15, 17, 10], k = 6`  
**Modified Heights:** `[6, 12, 10, 9, 11, 4]`  
**Output:** `8`  
**Explanation:** Max = 12, Min = 4 → Difference = 8

---

### Example 2:
**Input:**  
`arr = [1, 5, 10, 15], k = 3`  
**Modified Heights:** `[4, 8, 7, 12]`  
**Output:** `8`  
**Explanation:** Max = 12, Min = 4 → Difference = 8

---

## 📌 Key Insight

- Sort the array.
- For each tower `i`, assume:
  - Towers `0` to `i-1` are increased by `k`
  - Towers `i` to `n-1` are decreased by `k`
- Track:
  - `minH = min(arr[0] + k, arr[i] - k)`
  - `maxH = max(arr[i-1] + k, arr[n-1] - k)`
- The **minimum of all (maxH - minH)** across valid `i` is the result.

---

## ✅ C++ Code: Using Sorting

```cpp

int getMinDiff(vector<int> &arr, int k) {
    int n = arr.size();
    sort(arr.begin(), arr.end());

    int res = arr[n - 1] - arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] - k < 0)
            continue;

        int minH = min(arr[0] + k, arr[i] - k);
        int maxH = max(arr[i - 1] + k, arr[n - 1] - k);

        res = min(res, maxH - minH);
    }

    return res;
}

```

## 📊 Time and Space Complexity

| Metric            | Value         |
|-------------------|---------------|
| Time Complexity   | O(n log n)    |
| Space Complexity  | O(1)          |
| Sorting Required? | ✅ Yes         |

---

## 🧠 Summary

- Always **sort the array** before processing.
- For each index `i`, imagine:
  - Adding `k` to elements `arr[0]` to `arr[i-1]`
  - Subtracting `k` from elements `arr[i]` to `arr[n-1]`
- Use:
  - `minHeight = min(arr[0] + k, arr[i] - k)`
  - `maxHeight = max(arr[i-1] + k, arr[n-1] - k)`
- Track and update the **minimum difference** between tallest and shortest tower dynamically.

---

## 📚 Related Concepts

- 🔁 **Greedy Algorithms**
- 📉 **Difference Minimization**
- 🔤 **Sorting-based Problem Solving**

