#  DAY 6 🔢 Problem: Majority Element II     

You are given an array `arr[]` of size `n`, where each element represents a vote for a candidate.  
Return all elements that appear **more than ⌊ n/3 ⌋ times**, in **increasing order**.

---

## 🔍 Examples

### Example 1:
**Input:**  
`arr = [2, 1, 5, 5, 5, 5, 6, 6, 6, 6, 6]`  
**Output:**  
`[5, 6]`  
**Explanation:**  
`5` appears 4 times, `6` appears 5 times. Both are > `n/3 = 3.66`.

### Example 2:
**Input:**  
`arr = [1, 2, 3, 4, 5]`  
**Output:**  
`[]`  
**Explanation:**  
No number appears more than `5/3 = 1.66` times.

---

## ✅ Solution 1: Hash Map Frequency Count (Brute Force)

```cpp
class Solution {
  public:
    vector<int> findMajority(vector<int>& arr) {
        vector<int> ans;
        unordered_map<int, int> freq;
        int threshold = arr.size() / 3;

        for (int num : arr) {
            freq[num]++;
        }

        for (auto& [key, count] : freq) {
            if (count > threshold)
                ans.push_back(key);
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};
```

## ✅ Pros:
-Simple and intuitive.

-Good for learning basics of frequency-based problems.

## ❌ Cons:
-Uses extra space: O(n) due to hashmap.

-Not optimal for large datasets.


✅ Solution 2: Boyer-Moore Voting Algorithm (Optimized)

## CODE
```cpp
class Solution {
  public:
    vector<int> findMajority(vector<int>& arr) {
        int n = arr.size();
        int num1 = 0, num2 = 1; // Initialize to different values
        int c1 = 0, c2 = 0;
        vector<int> res;

        
        for (int x : arr) {
            if (x == num1)
                c1++;
            else if (x == num2)
                c2++;
            else if (c1 == 0) {
                num1 = x;
                c1 = 1;
            } else if (c2 == 0) {
                num2 = x;
                c2 = 1;
            } else {
                c1--;
                c2--;
            }
        }

       
        c1 = c2 = 0;
        for (int x : arr) {
            if (x == num1) c1++;
            else if (x == num2) c2++;
        }

        if (c1 > n / 3) res.push_back(num1);
        if (c2 > n / 3) res.push_back(num2);

        sort(res.begin(), res.end());
        return res;
    }
};

### ✅ Pros:
- Optimal time: **O(n)**
- Space efficient: **O(1)** (in-place algorithm)

### ❌ Cons:
- Slightly tricky to understand and implement correctly.
- Can break if initial `num1` and `num2` are same — hence initialize them differently (`num2 = 1`, not `0`).

---

## 📊 Time and Space Complexity

| Approach           | Time Complexity | Space Complexity | Extra Notes               |
|--------------------|------------------|-------------------|----------------------------|
| Hash Map (Sol 1)   | O(n)             | O(n)              | Easy, but less efficient   |
| Boyer-Moore (Sol 2)| O(n)             | O(1)              | Optimal, in-place          |

---

## 📌 Summary
- Use **Hash Map** for quick prototyping or when memory isn’t a concern.
- Use **Boyer-Moore** for optimal performance in interviews or large datasets.


