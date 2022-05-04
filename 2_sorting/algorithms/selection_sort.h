#include <vector>

class SelectionSort {
private:

public:
    static void sort(int* list, int size)
    {
        int min;
        for(int i = 0 ; i < size-1 ; i++)
        {
            min = i;
            for (int j = i+1; j <  size; j++) {
                if(list[j] < list[min])
                {
                    min = j;
                }
            }
            // swap list[min] with list[i]
            if(min != i)
            {
                int temp = list[i];
                list[i] = list[min];
                list[min] = temp;
            }
        }
    };
};