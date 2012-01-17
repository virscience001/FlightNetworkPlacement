//Name: Viraj Patel
//ID: 200801069
//College: DA-IICT, Gandhinagar

#include <cstdlib>
#include <cmath>
#include <iostream>

using namespace std;

public class stk
{
       private int data[10];
       private int* stkPtr = data;
       private int size;
       
       public stk()
       {}
       
       public void PUSH(int n)
       {
            data[size] = n;
            ++stkPtr;
            ++size;
       }
       
       public int POP()
       {
           int tmp = *stkPtr;
           --stkPtr;
           --size;
           return tmp;
       }
       
       public int getSize()
       {
              return size;
       }
}

int main(int argc, char *argv[])
{
    stk S = new stk();
    int A = {4,3,2,1,0,9,8,7,6,5};
    
    int index = 0, to = 0;
    for(int i = 0; i <= A[0]; ++i)
    {
            S.PUSH(i);
            S.POP();
    }
    for(int i = 0; i < sizeof(A); ++i)
    {
            
            
    }
    
    system("PAUSE");
    return EXIT_SUCCESS;
}
