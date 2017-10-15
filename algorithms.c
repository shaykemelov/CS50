#include <stdio.h>
#include <stdlib.h>
#include "algorithms.h"

void merge_sort(int* arr, int size)
{
    if (size < 2)
    {
        return;
    }
    
    int left = size / 2;        
    int left_arr[left];
    for (int i = 0; i < left; i++)
    {
        left_arr[i] = *(arr + i);
    }    
    
    int right = size - left;
    int right_arr[right];
    for (int i = left; i < size; i++)
    {
        right_arr[i - left] = *(arr + i);
    }
    
    merge_sort(left_arr, left);
    merge_sort(right_arr, right);
    
    int l = 0;
    int r = 0;
    for (int i = 0; i  < size; i++)
    {
        if ((r >= right) && (l < left))
        {
            *(arr + i) = left_arr[l++];
        }
        else if ((l >= left) && (r < right))
        {
            *(arr + i) = right_arr[r++]; 
        }
        else
        {
            if (left_arr[l] < right_arr[r])
            {
                *(arr + i) = left_arr[l++]; 
            }
            else
            {
                *(arr + i) = right_arr[r++];
            }
        }
    }
}

void insertion_sort(int* arr, int size)
{
    int total = 0;
    while (total < size)
    {
        total++;
        for (int i = 0; i < total; i++)
        {
            if (arr[i] > arr[total])
            {
                swap(&*(arr + i), &*(arr + total));
            }
        }
    }
}

void selection_sort(int* arr, int size)
{
    int total = 0;
    while (total < size - 1)
    {
        int index_min = find_min(arr, total, size - 1);
        swap(&*(arr + index_min), &*(arr + total));
        total++;
    }
}

void bubble_sort(int* arr, int size)
{    
    int swaps = -1;
    int total = 1;
    while (swaps != 0)
    {
        swaps = 0;
        for (int i = 0; i < size - total; i++)
        {
            if (*(arr + i) > *(arr + i + 1))
            {
                swap(&*(arr + i), &*(arr + i + 1));
            }
        }
        total++;
    }
}

int linear_search(int* arr, int size, int x)
{
    for (int i = 0; i < size; i++)
    {
        if (*(arr + i) == x)
        {
            return i;
        }
    }
    return -1;
}

int binary_search(int* arr, int l, int r, int x)
{
    if (r >= l)
    {
        int mid = (l + r) / 2;
        if (*(arr + mid) == x)
        {
            return mid;
        }
        else if (*(arr + mid) > x)
        {
            return binary_search(arr, l, mid - 1, x);
        }
        else if (*(arr + mid) < x)
        {
            return binary_search(arr, mid + 1, r, x);
    
        }
        else
        {
            return -1;
        }
    }
}

int find_min(int* arr, int start, int end)
{
    int min = arr[start];
    int index = start;
    for (int i = start + 1; i <= end; i++)
    {
        if (min > *(arr + i))
        {
            min = *(arr + i);
            index = i;
        }
    }
    
    return index;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int* get_array(int size)
{
    int *arr = malloc(size * sizeof(int));
    for (int i = 0; i < size; i++)
    {
        *(arr + i) = i;
    }
    return arr;
}

void display_array(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%i ", *(arr + i));
    }
    printf("\n");
}
