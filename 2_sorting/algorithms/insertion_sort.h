#include <vector>

class InsertionSort {
public:
    static void sort(int* list, int size)
    {
        int val, j;
        for (int i = 1; i < size; i++)
        {
            val = list[i];
            j = i - 1;

            while (j>=0 && list[j] > val)
            {
                list[j + 1] = list[j];
                j--;
            }
            list[j + 1] = val;
        }
    };
};