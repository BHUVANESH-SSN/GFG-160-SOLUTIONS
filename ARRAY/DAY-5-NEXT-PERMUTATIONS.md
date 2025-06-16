# 🔁 Next Lexicographical Permutation - C++ Solution

This document explains how to compute the **next lexicographical permutation** of a given array of integers using C++.
- A **manual implementation**
- A **built-in STL solution**
---

## 📘 Problem Statement

Given an array `arr[]` of size `n`, the task is to print the **next lexicographical permutation** of the array. If no such permutation exists (i.e., the array is in descending order), return the **smallest (first) permutation** instead.

---

## 🔹 Example 1

**Input:**  
`arr = [2, 4, 1, 7, 5, 0]`  
**Output:**  
`[2, 4, 5, 0, 1, 7]`  
**Explanation:**  
This is the next lexicographical permutation of the array.

---

## 🔹 Example 2

**Input:**  
`arr = [3, 2, 1]`  
**Output:**  
`[1, 2, 3]`  
**Explanation:**  
This is the last permutation, so we return the first one.

---

## 🔹 Example 3

**Input:**  
`arr = [1, 3, 5, 4, 2]`  
**Output:**  
`[1, 4, 2, 3, 5]`  
**Explanation:**  
Next permutation after sorting the suffix.

---

## ✅ C++ Code: Efficient Next Permutation

```cpp

void nextPermutation(vector<int> &arr) {
    int n = arr.size(); 
    int pivot = -1;

    
    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] < arr[i + 1]) {
            pivot = i;
            break;
        }
    }

    
    if (pivot == -1) {
        reverse(arr.begin(), arr.end());
        return;
    }

  
    for (int i = n - 1; i > pivot; i--) {
        if (arr[i] > arr[pivot]) {
            swap(arr[i], arr[pivot]);
            break;
        }
    }

   
    reverse(arr.begin() + pivot + 1, arr.end());
}
```
## 🧠 Explanation of Steps

### 🔹 1. Find the Pivot
Traverse the array from the end to find the **first index `i`** such that: arr[i] < arr[i + 1]
This marks the first point where the array is not in descending order and a swap can be made to form a higher permutation.

---

### 🔹 2. Find the Next Greater Element
From the right side of the array, find the **smallest element greater than `arr[pivot]`**, and **swap** them.  
This ensures the next permutation is **just slightly greater** than the current one.

---

### 🔹 3. Reverse the Suffix
Reverse the subarray from `pivot + 1` to the end.  
This rearranges the suffix into the **lowest possible (ascending) order**, ensuring the permutation is the next in lexicographical order.

---

### ⚠️ Edge Case
If the entire array is in **descending order** (no pivot is found), then the array is the **last permutation**.  
In this case, **reverse the whole array** to return the **first permutation** (sorted in ascending order).

---

## 📈 Time and Space Complexity

| Approach              | Time Complexity | Space Complexity | In-place |
|-----------------------|-----------------|------------------|----------|
| Manual Implementation | O(n)            | O(1)             | ✅        |
| STL Method            | O(n)            | O(1)             | ✅        |

