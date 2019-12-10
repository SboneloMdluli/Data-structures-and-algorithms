//algorithm to check if string is 1 edit distance away

#include<iostream>
#include<string>
#include<cstdlib>

using namespace std;

bool is_edit_1(string s1, string s2)
{

        // O(m+n)
	int m = s1.length();
	int n = s2.length();
	int visited[256] ={0}; //O(1) space
	
	if (abs(m-n) > 1)
	     return false;
	
        for (int i =0;i<m;i++){
		visited[s1[i]]++;
	}

	for (int i =0;i<n;i++){
		visited[s2[i]]--;
	}

	int count =0;
	for (int i =0;i<256;i++){
		if(visited[i] !=0)
			count++;
	}

	return count==1|| count ==2;
}

int main(){

     string a = "ove";
     string b = "one";

     if(is_edit_1(a,b)){
        cout <<"one distance edit"<<endl;
     }else{
        cout <<"false"<<endl;
     }

}
