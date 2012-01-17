//Name: Viraj Patel
//ID: 200801069
//College: DA-IICT, Gandhinagar

#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    struct kid                      // structure kid (Node for the Link list)
    {
           int pos;
           struct kid* next;
    } *current, *prev;
    int M, N;
    struct kid *first= new kid();
    
    first->pos = 1;              // Assigning values for First position
    first->next = first;
    current = first;
    prev = current;
    
    cout << "M = ";              // Input values for M and N
    cin >> M;
    cout << "N = ";
    cin >> N;
    while(N >= M)                // Assuring that N is less than M. If not then ask to re-input
    {
         cout << "N must be less then M.\nN = ";
         cin >> N;
    }
    
    for(int i = 2; i <= M; ++i)    // Creating Circulat Link List for all kids
    {
            prev = current;
            current = new kid();
            current->pos = i;
            prev->next = current;
            current->next = first;
    }
    
    current = first;              // setting 'current' and 'prev' to first position
    prev = current;
    int count = 1, no_of_kids = M; // setting counter and total no. of kids
    while(1)
    {
            if(count == N)         // if the count is equal to N then remove the kid at current position
            {
                     count = 1;
                     prev->next = current->next;
                     current = current->next;
                     --no_of_kids;           // decrease no. of kids
                     if(no_of_kids == 1)     // if there is only 1 kid left then he is the winner
                     {
                                   cout << "Winner is position " << current->pos << "\n";
                                   break;
                     }
            }
            else
            {
                prev = current;          // counting...
                current = current->next;
                ++count;
            }
    }
    
    system("PAUSE");
    return EXIT_SUCCESS;
}
