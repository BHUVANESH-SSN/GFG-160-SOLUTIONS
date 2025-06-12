USING SORTING METHOD:

TIME COMPLEXITY : O(n*log(n))

class Solution{
   public:

      int getSecondLargest(vector<int> &arr) {
      int n = arr.size();  
      sort(arr.begin(), arr.end());  
      for (int i = n - 2; i >= 0; i--) {      
          if (arr[i] != arr[n - 1]) {
              return arr[i];
          }
      }return -1;
   }

};


OPTIMAL ONE PASS SEARCH: 

TIME COMPLEXITY :  O(n)
class Solution {
  public:
    
    int getSecondLargest(vector<int> &arr) {
        int first=-1;
        int second=-1;
        int n=arr.size();
        for(int i=0;i<n;i++){
            if(arr[i]>first){
                second=first;
                first=arr[i];
            }
            else if (arr[i]>second && arr[i]<first){
                second=arr[i];
            }
        }return second;
      
    }
};

