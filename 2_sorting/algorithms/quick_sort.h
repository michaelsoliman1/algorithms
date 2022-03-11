#include <vector>

class QuickSort{
public:
    static int _partition(int* list, int left,int right)
    {
        int pivot = list[right];
        int storeIndex = left - 1;
        for (int i = left; i <= right -1; i++) {
            if(list[i] < pivot)
            {
                storeIndex++;
                //swap
                int temp = list[i];
                list[i] = list[storeIndex];
                list[storeIndex] = temp;
            }
        }
        int temp = list[storeIndex + 1];
        list[storeIndex + 1] = list[right];
        list[right] = temp;
        return storeIndex +1;
    };
    static void sort(int* list, int left, int right)
    {
        if(left < right)
        {
            int pivot = _partition(list, left, right);
            sort(list, left, pivot - 1);
            sort(list, pivot +1 , right);
        }
    };
};