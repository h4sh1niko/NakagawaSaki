#include <iostream>
#include <cstdlib> 

using namespace std;

int main()
{
    const int size = 100;
    int data[size] = {};
    int n = sizeof(data) / sizeof(data[0]);
    int valueA, valueB;
    int max, min;

    for(int i = 0; i < n; i++)
    {
        data[i] = rand();
        cout << data[i] << " ";
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = n - 1; j >= i + 1; j--)
        {
            valueA = data[j - 1];
            valueB = data[j];

            if(valueA > valueB)
            {
                max = valueA;
                min = valueB;
                data[j - 1] = min;
                data[j] = max;
            }
        }
    }

    cout << endl;
    cout << "Sorted Data:" << endl;
    cout << endl;
    
    for(int i = 0; i < n; i++)
    {
        cout << data[i] << " ";
    }

    return 0;
}