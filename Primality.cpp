#include <iostream>
#include <climits>
#include <chrono>
#include <cmath>

using namespace std;
using namespace std::chrono;
int I;
bool naive (int N)
{
    I=0;
    int i;
for(i=2;i<N;i++)
    if(N%i == 0){
        I = i;
        return false;
    }
I = i-3;
return true;
}

bool optimised(int N)
{
if(N <= 1) {return false;}
       
if(N <= 3) {return true;}
// If a number leaves a remainder of 0, 2 or 4 when divided by 6, then it is even and therefore non-prime (unless it is 2)
// If it leaves a remainder of 3 when divided by 6 then it is divisible by 3 and therefore non-prime (unless it is 3)
if(N%2 == 0 || N%3 == 0) {return false;}
// remainders 1 and 5, or in other words, numbers of the form  6k±1 i.e Prime number      
if(N%6 == 1 || N%6 == 5) {return true;}
return false;
}

int main ()
{
  auto start_N = high_resolution_clock::now();
  int N = naive(INT_MAX);
  auto end_N = high_resolution_clock::now();
  auto Time_N = duration_cast<microseconds>(end_N - start_N); 
  cout << "Naive Approach (BruteForce): \nIs_Prime: " << N <<"\nIterations: " << I <<" <= O(N)"<<(INT_MAX)<<"\nTime: "<<Time_N.count()<<endl;

  auto start_O = high_resolution_clock::now();
  int O = optimised(INT_MAX);
  auto end_O = high_resolution_clock::now();
  auto Time_O = duration_cast<microseconds>(end_O - start_O); 
  cout << "Optimised Approach: \nIs_Prime: " << O <<"\ncomplexity: O(1)"<<"\nTime: "<<Time_O.count()<<endl;
  
  return 0;
}
