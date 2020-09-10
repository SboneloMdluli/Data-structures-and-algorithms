#include <iostream>

using namespace std;

//a^n in log (n)

long long binpow(long long a, long long b){
    
    long long res = 1;
    
    while(b>0){
        
        if(b%2 !=0)
             res *= a;
             
        a *= a; 
        b /= 2;
    }
    
    return res;
}

int main()
{
    cout<<binpow(3,3);

    return 0;
}

