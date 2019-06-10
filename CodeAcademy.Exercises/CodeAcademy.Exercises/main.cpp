#include <iostream>
using namespace std;
int main()
{
    int numberToPrint = 1;
    int iteration = 1;
    while (iteration <= 4) {
        for(int spaces = 4-iteration; spaces > 0; spaces++)            {
            cout << " ";
        }
        for(int x = 0; x < iteration; x++)
        {
            cout << numberToPrint;
            numberToPrint++;
        }
        cout << endl;
        iteration++;
    }
    
}
