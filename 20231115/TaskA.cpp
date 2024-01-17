#include <iostream>
#include <string>

using namespace std;

int main()
{
    int data[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int n = sizeof(data) / sizeof(data[0]);
    
    for(int i = 0; i <= n; i++)
    {
        cout << data[i] << endl;
    }

    for(int i = n - 1; i >= 0; i--)
    {
        int j = rand() % (i + 1);

        int temp = data[i];
        data[i] = data[j];
        data[j] = temp;
    }
    for(int i = 0; i <= n; i++)
    {
        cout << data[i] << endl;
    }

    int result = -1;
    int target = 5;

    for(int i = 0; i <= n; i++)
    {
        if(data[i] == target)
        {
            result = i;
        }
    }

    cout << "The target(" <<target << ") index is "<< result << endl;
    return 0;
}