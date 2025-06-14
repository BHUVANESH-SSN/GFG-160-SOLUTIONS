# 🔁 Reverse an Array - C++ Solutions

This repository contains three different C++ solutions to reverse an array. Each solution uses a different approach, explained in simple terms.

---

## ✅ Solution 1: Using a Temporary Array

### 👨‍💻 Code

```cpp

void reverseArray(vector<int> &arr) {
    int n = arr.size();
    vector<int> temp(n);  // Create a temporary array

    // Copy elements in reverse order
    for(int i = 0; i < n; i++)
        temp[i] = arr[n - i - 1];

    // Copy back to original array
    for(int i = 0; i < n; i++)
        arr[i] = temp[i];
}

```
## 🧠 Explanation
-This approach uses a new array to store the reversed version of the input.

-We copy the elements from the end of the original array to the beginning of the temp array.

-Then we copy the result back to the original array.

-**Space Complexity**: O(n) – we use extra space.

## ✅ Solution 2: Using Two Pointers

### 👨‍💻 Code

```cpp


void reverseArray(vector<int> &arr) {
    int left = 0, right = arr.size() - 1;
    
    // Keep swapping the elements at left and right
    while(left < right) {
        swap(arr[left], arr[right]);
        left++;
        right--;
    }
}

```

### 🧠 Explanation

- We use two pointers: one starting from the beginning, the other from the end.
- We swap the elements and move the pointers inward until they meet.
- **Space Complexity:** O(1) – no extra space used.
- **Time Complexity:** O(n)

---

## ✅ Solution 3: Swapping with Loop

### 👨‍💻 Code

```cpp

void reverseArray(vector<int> &arr) {
    int n = arr.size();
    
    // Swap ith element from start with ith from end
    for(int i = 0; i < n/2; i++) {
        swap(arr[i], arr[n - i - 1]);
    }
}

```

### 🧠 Explanation

- This is a direct way to reverse by swapping the first and last elements one-by-one.
- It uses a simple `for` loop that runs only till half of the array.
- **Space Complexity:** O(1)
- **Time Complexity:** O(n)

---

## 📌 Summary

| Method | Time Complexity | Space Complexity | Extra Notes |
|--------|----------------|------------------|-------------|
| Temporary Array | O(n) | O(n) | Easy to understand |
| Two Pointers | O(n) | O(1) | Efficient, clean logic |
| Swapping with Loop | O(n) | O(1) | Slightly shorter version of 2 |

---

*👨‍💻 All codes are written by me as part of my learning journey on GeeksforGeeks.*
