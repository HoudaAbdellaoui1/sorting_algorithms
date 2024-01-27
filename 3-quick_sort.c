#include <stdio.h>

/**
 * swap - Swap two integers
 * @a: First integer
 * @b: Second integer
 */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * lomuto_partition - Lomuto partition scheme for Quick Sort
 * @array: Array to be partitioned
 * @low: Low index of the partition
 * @high: High index of the partition
 * @size: Size of the array
 * Return: Index of the pivot element
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
    int pivot = array[high];
    int i = low - 1, j = low;
    size_t k = 0;

    for (j = low; j < high; j++)
    {
        if (array[j] <= pivot)
        {
            i++;
            swap(&array[i], &array[j]);

            /* Print the array after each swap */
            for (k = 0; k < size; k++)
            {
                if (k == size - 1)
                    printf("%d", array[k]);
                else
                    printf("%d, ", array[k]);
            }
            printf("\n");
        }
    }

    swap(&array[i + 1], &array[high]);

    /* Print the array after each swap */
    for (k = 0; k < size; k++)
    {
        if (k == size - 1)
            printf("%d", array[k]);
        else
            printf("%d, ", array[k]);
    }
    printf("\n");

    return i + 1;
}

/**
 * quick_sort_recursive - Recursive function for Quick Sort
 * @array: Array to be sorted
 * @low: Low index of the partition
 * @high: High index of the partition
 * @size: Size of the array
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
    if (low < high)
    {
        int pivot = lomuto_partition(array, low, high, size);

        quick_sort_recursive(array, low, pivot - 1, size);
        quick_sort_recursive(array, pivot + 1, high, size);
    }
}

/**
 * quick_sort - Sort an array using the Quick Sort algorithm (Lomuto partition scheme)
 * @array: Array to be sorted
 * @size: Size of the array
 */
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    quick_sort_recursive(array, 0, size - 1, size);
}
