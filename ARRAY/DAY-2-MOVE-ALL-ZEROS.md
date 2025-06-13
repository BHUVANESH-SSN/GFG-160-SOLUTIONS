# Move All Zeroes to End of Array – C++ Solutions

This repository contains two solutions to the common problem of moving all `0`s in an array to the end while maintaining the relative order of non-zero elements.

---

## 🧠 Problem Statement

Given an array of non-negative integers, move all the `0`s to the right end of the array. The relative order of the non-zero elements should remain the same. The operation must be done in-place or with minimal additional space.

---

## ✨ Examples

```txt
Input:  [1, 2, 0, 4, 3, 0, 5, 0]
Output: [1, 2, 4, 3, 5, 0, 0, 0]

Input:  [10, 20, 30]
Output: [10, 20, 30]

Input:  [0, 0]
Output: [0, 0]
```
## Solution 1: Using Temporary Array


### 🔍 Logic
Create a temporary array of the same size.

Copy all non-zero elements to the beginning.

Fill the remaining positions with 0s.

Copy everything back to the original array.

# CODE :
```cpp
#include <iostream>
#include <vector>
using namespace std;


void pushZerosToEnd(vector<int>& arr) {
    int n = arr.size();
    vector<int> temp(n);
    int j = 0;

    // copy non-zero elements into temp[]
    for (int i = 0; i < n; ++i) {
        if (arr[i] != 0) {
            temp[j++] = arr[i];
        }
    }

    // fill remaining positions with zeros
    while (j < n) {
        temp[j++] = 0;
    }

    // copy  to original array
    for (int i = 0; i < n; ++i) {
        arr[i] = temp[i];
    }
}
```

### ⏱️ Time and Space Complexity
### Time: O(n)

### Space: O(n) (extra array)

## Solution 2: In-Place Using One Traversal


### 🔍 Logic
Use a pointer position to track where the next non-zero should go.

Loop through the array:

If arr[i] is not zero, swap it with arr[position].

Increment position.
# CODE
```cpp

#include <iostream>
#include <vector>
using namespace std;


void pushZerosToEnd(vector<int>& arr) {
    int position = 0;  // tracks position for next non-zero element

    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] != 0) {
            swap(arr[i], arr[position]);
            ++position;
        }
    }
}
```
## ⏱️ Time and Space Complexity
### Time: O(n)

### Space: O(1) (in-place)
