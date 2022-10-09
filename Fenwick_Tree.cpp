#include <iostream>

using namespace std;

int getSum(int BITree[], int index)
{
    int sum = 0;

    index = index + 1;

    while (index > 0)
    {

        sum += BITree[index];

        index -= index & (-index);
        // index = index & (index-1);
    }
    return sum;
}

void updateBIT(int BITree[], int n, int index, int val)
{

    index = index + 1;

    while (index <= n)
    {

        BITree[index] += val;

        index += index & (-index);
    }
}

int *constructBITree(int arr[], int n)
{

    int *BITree = new int[n + 1];
    for (int i = 1; i <= n; i++)
        BITree[i] = 0;

    for (int i = 0; i < n; i++)
        updateBIT(BITree, n, i, arr[i]);

    return BITree;
}

int main()
{
    int freq[] = {10, 20, 30, 40, 50, 60, 70, 80, 90};
    int n = sizeof(freq) / sizeof(freq[0]);
    int *BITree = constructBITree(freq, n);
    cout << "Sum of elements in arr[0..5] is "
         << getSum(BITree, 5);

    return 0;
}
