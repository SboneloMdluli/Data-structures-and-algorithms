//algorithm to remove duplicates in string array

#include <iostream>
#include <unordered_map>
#include <tuple>
#include <string>

using namespace std;

void cmpressed(char str[]){

        int size = sizeof(str)/sizeof(str[0]);
        char char_set [256] = {0}; //O(1) assuming its an ASCII string
        int uniq_pos = 0;
        //O(n) in place
        for(int i=0; i< size; ++i){
                int pos = int(str[i]);
                
                if(char_set[pos] == 0){
                     
                     char_set[pos] = 1;
                     str[uniq_pos] =str[i]; 
                     uniq_pos++;

                }
        }
        
        str[uniq_pos] = '\0'; // terminate string
        cout << str <<endl;
}

string compressed(string &word){

      unordered_map<char,int> lookup; //O(n) extra space
      string comp;
     
      for(int i=0; i <word.size(); i++){
       
         auto val = lookup.find(word[i]); // O(1) amotised
          
         if(val == lookup.end()){ //only make comp string if we ddnt find the cur char in map
             comp += word[i];  
         }
         
       lookup.insert(make_pair(word[i],i));
      }
      
      
      return comp;

}


int main(){

      string sentence = "sf xx sff ";
      char str[] = "abb uyys";
            
     cmpressed(str);

}
