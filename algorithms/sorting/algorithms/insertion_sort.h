#include <vector>

class InsertionSort {
public:
    static void sort(std::vector<int> list)
    {
        int val, j;
        for (size_t i = 0; i < list.size(); i++)
        {
            val = list[i];
            j = i - 1;

            while (j>0 && list[j] > val)
            {
                list[j + 1] = list[j];
                j--;
            }
            list[i + 1] = val;
        }
        
    };
};