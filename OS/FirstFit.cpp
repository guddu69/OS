#include <iostream>
using namespace std;
void first_fit(int block_size[], int process_size[], int m, int n)
{
    int i, j;
    int allocation[n];
    for (i = 0; i < n; i++)
        allocation[i] = -1;
    for (i = 0; i < n; i++)
    {
        int index = -1;
        for (j = 0; j < m; j++)
        {
            if (block_size[j] >= process_size[i])
            {
                index = j;
                break;
            }
        }
        if (index != -1)
        {
            allocation[i] = index;
            block_size[index] = block_size[index] - process_size[i];
        }
    }
    cout << "Process No.\tProcess Size\tBlock No." << endl;
    for (i = 0; i < n; i++)
    {
        cout << "  " << i + 1 << "\t\t" << process_size[i] << "\t\t";
        if (allocation[i] != -1)
            cout << allocation[i] + 1;
        else
            cout << "Not allocated";
        cout << endl;
    }
}
int main()
{
    int block_size[] = {100, 500, 200, 300, 600};
    int process_size[] = {212, 417, 112, 426};
    int m = sizeof(block_size) / sizeof(block_size[0]);
    int n = sizeof(process_size) / sizeof(process_size[0]);
    first_fit(block_size, process_size, m, n);
    return 0;
}