#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
    int data[10] = {};
    for(int i = 0; i <= sizeof(data) / sizeof(data[0]); i++)
    {
        data[i] = rand();
    }
    for(int i = 0; i <= sizeof(data) / sizeof(data[0]); i++)
    {
        cout << data[i] << endl;
    }
    return 0;
}