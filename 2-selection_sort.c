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
 * selection_sort - Sort an array using the Selection Sort algorithm
 * @array: Array to be sorted
 * @size: Size of the array
 */
void selection_sort(int *array, size_t size)
{
    size_t i, j, min_idx, k;

    for (i = 0; i < size - 1; i++)
    {
        min_idx = i;

        for (j = i + 1; j < size; j++)
        {
            if (array[j] < array[min_idx])
            {
                min_idx = j;
            }
        }

        /* Swap the found minimum element with the first element */
        swap(&array[min_idx], &array[i]);

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
