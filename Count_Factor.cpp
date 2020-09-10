#include <iostream>
#include <climits>
#include <chrono>
#include <cmath>

using namespace std;
using namespace std::chrono;
int I;
int naive (int N)
{
    I=0;
    int c=0, i;
for(i=1;i<=N;i++)
    if(N%i == 0)
        c++;
I = i--;
return c;
}

int optimised(int N)
{
    I=0;
    int c=0, i;
for(i=1;i*i<=N;i++)
    if(N%i == 0){
        c++;
        if(i != N/i)
            c++;
    }
I = i--;
return c;
}

int main ()
{
  auto start_N = high_resolution_clock::now();
  int N = naive(INT_MAX/100);
  auto end_N = high_resolution_clock::now();
  auto Time_N = duration_cast<microseconds>(end_N - start_N); 
  cout << "Naive Approach (BruteForce): \ncount of Factors: " << N <<"\nIterations: " << I <<" <= O(N)"<<((INT_MAX/100)+1)<<"\nTime: "<<Time_N.count()<<endl;

  auto start_O = high_resolution_clock::now();
  int O = optimised(INT_MAX/100);
  auto end_O = high_resolution_clock::now();
  auto Time_O = duration_cast<microseconds>(end_O - start_O); 
  cout << "Optimised Approach: \ncount of Factors: " << O <<"\nIterations: " << I <<" <= O(rootN)"<<((int)sqrt(INT_MAX/100)+1)<<"\nTime: "<<Time_O.count()<<endl;
  
  return 0;
}
