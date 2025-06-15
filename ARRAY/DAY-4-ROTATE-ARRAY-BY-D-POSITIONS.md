# 🔄 Left Rotate an Array by d Positions - C++ Solutions

This document explains three different ways to rotate an array to the left by `d` positions using C++. Rotating means shifting elements to the left and wrapping the beginning elements to the end.

---

## 📘 Problem Statement

Given an array of integers `arr[]` of size `n`, and a number `d`, rotate the array elements to the left by `d` positions.

### 🔹 Example:
**Input:**  
`arr[] = {1, 2, 3, 4, 5, 6}`, `d = 2`  
**Output:**  
`{3, 4, 5, 6, 1, 2}`

---

## ✅ Solution 1: Brute Force (One-by-One Rotation)

### 👨‍💻 Code

```cpp
void rotateArr(vector<int>& arr, int d) {
    for(int i = 0; i < d; i++) {
        int first = arr[0];
        for(int j = 0; j < arr.size() - 1; j++) {
            arr[j] = arr[j + 1];
        }
        arr[arr.size() - 1] = first;
    }
}
```

## 🧠 Explanation
### We perform one rotation at a time: move all elements to the left by 1 and put the first element at the end.

-This is repeated d times.

## 📈 Complexity
**Time**: O(n * d)

**Space**: O(1)

# ✅ Solution 2: Reversal Algorithm (Efficient)
## 👨‍💻 Code
```cpp

void rotateArr(vector<int>& arr, int d) {
    int n = arr.size();
    d %= n;  // handle cases when d > n
    reverse(arr.begin(), arr.begin() + d);
    reverse(arr.begin() + d, arr.end());
    reverse(arr.begin(), arr.end());
}
```
## 🧠 Explanation
### Step 1: Reverse first d elements

### Step 2: Reverse the remaining n - d elements

### Step 3: Reverse the entire array

### This method rotates the array in-place.

## 📈 Complexity
**Time**: O(n)

**Space**: O(1)

# ✅ Solution 3: Using Temporary Array
## 👨‍💻 Code
```cpp

void rotateArr(vector<int>& arr, int d) {
    int n = arr.size();
    d %= n;  // handle d > n
    vector<int> temp(n);

    
    for(int i = 0; i < n - d; i++) {
        temp[i] = arr[d + i];
    }
    for(int i = 0; i < d; i++) {
        temp[n - d + i] = arr[i];
    }    
    for(int i = 0; i < n; i++) {
        arr[i] = temp[i];
    }
}
```
## 🧠 Explanation
-A new array temp is used to store the rotated version.

-The elements from index d to n-1 are placed first, followed by elements 0 to d-1.

## 📈 Complexity
**Time** : O(n)

**Space**: O(n)

## 📊 Summary
### -Approach	Time Complexity	Space Complexity	Notes
### -Brute Force (Sol 1)	O(n * d)	O(1)	Simple but slow for large d
### -Reversal Method (Sol 2)	O(n)	O(1)	Efficient and in-place
### -Temp Array (Sol 3)	O(n)	O(n)	Easy logic but uses extra space

## 👨‍💻 All solutions are written by me as part of my GeeksforGeeks learning journey. Feel free to use or contribute!





