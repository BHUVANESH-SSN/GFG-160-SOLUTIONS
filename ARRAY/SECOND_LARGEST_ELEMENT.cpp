# 🥈 Second Largest Element in an Array

## 📌 Problem Statement:
Given an array of integers, find the second largest distinct element in the array.

---

## 🔍 Approach 1: Sorting Method

### 🧠 Idea:
- Sort the array in ascending order.
- Traverse from the end to find the first element smaller than the maximum (last element).
- Return that element as the second largest.

### 💻 Code (C++):
```cpp
class Solution {
public:
    int getSecondLargest(vector<int> &arr) {
        int n = arr.size();  
        sort(arr.begin(), arr.end());  
        for (int i = n - 2; i >= 0; i--) {      
            if (arr[i] != arr[n - 1]) {
                return arr[i];
            }
        }
        return -1;
    }
};
```
### Time Complexity  : O(n * log(n)) — due to sorting


### ⚡ Approach 2: Optimal One-Pass Search
### 🧠 Idea:
## Traverse the array only once.

### Track the largest (first) and second largest (second) elements.

### Update them while iterating without sorting.

### 💻 Code (C++):
```cpp
Copy code
class Solution {
public:
    int getSecondLargest(vector<int> &arr) {
        int first = -1;
        int second = -1;
        int n = arr.size();
        
        for (int i = 0; i < n; i++) {
            if (arr[i] > first) {
                second = first;
                first = arr[i];
            }
            else if (arr[i] > second && arr[i] < first) {
                second = arr[i];
            }
        }
        return second;
    }
};
```
###⏱️ Time Complexity: O(n) — Single pass through the array
✅ Summary:
## Approach	               Time Complexity    	Space Complexity       	Method
### Sorting Method          	O(n * log(n))	   O(1)	                Brute-force
### Optimal One-Pass            	O(n)	         O(1)	                Efficient ✅

📝 Note:
Both approaches assume the array has at least two distinct elements. If no second largest exists, -1 is returned.



