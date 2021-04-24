#include <vector>

class MergeSort {
public:
    static void sort(int * list ,int start ,int end ) //end is length)
    {
        // 9
        int Half_length = (end-start)/2; // 4
        int mid = (end-start) - ((end-start)/2); // 5

        if ((end-start) == 1)
            return;

        sort(list,start,Half_length); // 1 : 4
        sort(list,Half_length+1,end); // 5 : 9

        int * list1 = new int [Half_length]; // list of 4
        int * list2 = new int [mid]; // list of 5

        for (int i = 0; i <Half_length ; i++)
        {
            list1[i]=list[start+i]; // copy from start of the array
        }

        for (int i = 0; i <mid; i++)
        {
            list2[i]=list[i+ Half_length+1];
        }


        int i = 0,j = 0,k = 0;
        while(i<Half_length && j < (end-start) - (Half_length)){
            if (list1[i] < list2[j])
            {
                list[start+k] = list1[i];
                i++;
            }else{
                list[start+k] = list2[j];
                j++;
            }
            k++;
        }

        while (i < Half_length)
        {
            list[start+k] = list1[i];
            i++;
            k++;
        }
        while (j <  (end-start) - (Half_length))
        {
            list[start+k] = list2[j];
            j++;
            k++;
        }

    };
};