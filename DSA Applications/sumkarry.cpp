//ALgorithm to return a range where specific sum in an array is found

#include <iostream>

using namespace std;

void Sum_karray(int Arr[],const int &size, int &sum){

        int curr_sum = Arr[0];
        int start = 0;
        int curr_length = 0;
        
        int beg=0, end=0;
        
        //O(n)
        for(int i = 1; i<= size ; i++){
        
                while(curr_sum > sum && start < i-1){
                    curr_sum = curr_sum - Arr[start];  
                    start++;
                }
               
                
                if(curr_sum==sum && (i-start >= curr_length)){
                    beg = start;
                    end = i-1;
                    curr_length = i - start;
                 
                }
                
                if (i < size){ 
                 curr_sum += Arr[i];
                 }
                // cout << curr_sum <<endl; 
        }
        
          cout <<"element found between" << beg << " and "<< end << endl;
                
}


int main(){

        int arr[] = {0, 1, 1, 0, 4, 1, 1};
        int size = sizeof(arr)/sizeof(arr[0]);
        
        int sum = 2;
        Sum_karray(arr,size,sum);
        
}
