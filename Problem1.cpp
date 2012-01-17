//Name: Viraj Patel
//ID: 200801069
//College: DA-IICT, Gandhinagar

#include <cstdlib>
#include <cmath>
#include <iostream>
using namespace std;

class stk                      // Stack Class using Array
{
       private:
               int data[10];
               int size;
       
       public:
              stk()               // Constructor
              {size = 0;}
              void PUSH(int n)    // PUSH function
              {
                   if(size == 10)
                   {
                           cout << "Stack is Full.";
                   }
                   else
                   {
                       //cout << "PUSH" << n << "\n";
                       data[size] = n;
                       ++size;
                   }
              }
              int POP()           // POP function
              {
                  if(size != 0)
                  {
                          int tmp = data[--size];
                          cout << tmp << "  ";
                          return tmp;
                  }
                  else
                  {
                      cout << "Stack is Empty.";
                      return -1;
                  }
              }
              int getSize()     // return Size of the Stack Array
              {
                     return size;
              }
};

int main(int argc, char *argv[])
{
    stk S;                       //Stack member
    bool flag = 0;               // flag, if TRUE then Pattern is not achievable, else it is achievable
    int A[] = {5,6,7,8,4,0,9,2,1,3};      // Input Sequence, please enter the sequence here...
    
    int i, max = 0;                       // 'i' is loop counter, 'max' is maximum number that is PUSHed onto the stack
    for(i = 0; i <= A[0]; ++i)            // PUSH all numbers between 0 and first number on the sequence 
    {
            max = A[0];
            S.PUSH(i);
    }
    S.POP();                              // POP the first number on sequence
    
    for(i = 1; i < sizeof(A); ++i)        // Loop for rest of the sequence..
    {
            if(A[i] > max)                // If current element is greater than maximum no. pushed in stack then
            {                             // PUSH numbers between 'max' and current element
                    for(int j = max+1; j <= A[i]; ++j)
                            S.PUSH(j);        
                    max = A[i];               //Set 'max' to new maximum number
                    S.POP();                  // POP operation for current element
            }
            else if(A[i] < A[i-1])            //  If current element is less than previous element then,
            {
                    if(S.POP() != A[i])       // POP the stack and if the value is not same to the current element then
                    {                         // pattern is not achievable.
                    
                               cout << "\nInput pattern is not achievable.";
                               flag = 1;
                               break;           
                    }
                    else
                        continue;
            }
            if(A[i] == 9)                       // If current element processed was 9 then Empty the stack outside the loop
                    break;
    }
    
    while(S.getSize() != 0 && flag == 0)          // While emptying the stack check if the pattern is still achievable.
            if(S.POP() != A[++i])
            {
                   cout << "\nInput pattern is not achievable.";
                   break;
            }

    cout << "\n";
    system("PAUSE");
    return 0;
}
