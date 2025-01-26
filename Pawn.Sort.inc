/*

Copyright (C) 2023-2025 Tornamic
This file is part of a project licensed under GNU LGPL v2.1.

Author: Tornamic (Kirill Tymoshchenko)
    Discord: https://pastebin.com/raw/LMBNfFHE
    Github: https://github.com/Tornamic
    pawn.wiki https://pawn.wiki/i.php?/user/54232-tornamic/


# Quadratic Sort Functions 
native Sort::Bubble(array[], const len = sizeof array) https://en.wikipedia.org/wiki/Bubble_sort
native Sort::Selection(array[], const len = sizeof array) https://en.wikipedia.org/wiki/Selection_sort
native Sort::Insertion(array[], const len = sizeof array) https://en.wikipedia.org/wiki/Insertion_sort
native Sort::Gnome(array[], const len = sizeof array) https://en.wikipedia.org/wiki/Gnome_sort
native Sort::Shaker(array[], len = sizeof array) https://en.wikipedia.org/wiki/Cocktail_shaker_sort
native Sort::OddEven(array[], const len = sizeof array) https://en.wikipedia.org/wiki/Odd%E2%80%93even_sort

# Logarithmic Sort Functions
native Sort::Quick(array[], left, right) https://en.wikipedia.org/wiki/Quicksort
native Sort::Heap(array[], const len = sizeof array) https://en.wikipedia.org/wiki/Heapsort
native Sort::Shell(array[], const len = sizeof array) https://en.wikipedia.org/wiki/Shellsort

# Weird Sort Functions
native Sort::Bogo(array[], const len = sizeof array) https://en.wikipedia.org/wiki/Bogosort

# Misc Functions
native Var::Swap(&value1, &value2)
native Array::FillRandomValues(array[], const len = sizeof array, randmin = -10000, randmax = 10000)
native Array::Print(array[], const len = sizeof array)
native Array::Shuffle(array[], const len = sizeof array)
native Array::IsSorted(const array[], const len = sizeof array)
*/

#if defined TORT_PAWN_SORT
	#endinput
#endif
#define TORT_PAWN_SORT

#define _PAWN_SORT_VERSION                            (2.1)

#define Sort::                                        PSS_T_ 
#define Var::                                         PSV_T_ 
#define Array::                                       PSA_T_ 

stock Var::Swap(&value1, &value2)
{
	#emit lref.s.pri value1
	#emit lref.s.alt value2
	#emit sref.s.pri value2
	#emit sref.s.alt value1
}

stock Array::FillRandomValues(array[], const len = sizeof array, randmin = -10000, randmax = 10000)
{
    for(new i = 0; i < len; i++)
    {
        array[i] = random(randmax - randmin) + randmin;
    }
}

stock Array::Shuffle(array[], const len = sizeof array)
{
    for(new i = len - 1; i >= 1; i--)
    {
        Var::Swap(array[i], array[random(i + 1)]);
    }
}

stock Array::Print(array[], const len = sizeof array)
{
    for(new i; i != len; ++i)
    {
        printf("%i", array[i]);
    }
}

stock Array::IsSorted(const array[], const len = sizeof array)
{
    for (new i = 0; i < len - 1; i++)
    {
        if (array[i] > array[i + 1])
            return 0;
    }
    return 1;
}


///////////////////////////////////
//           Quadratic           //
///////////////////////////////////

stock Sort::Bubble(array[], const len = sizeof array)
{
    for(new i = 0; i < len; i++)
	{
		for(new j = 0; j < len - 1; j++)
		{
			if(array[j] > array[j + 1])
			{

				Var::Swap(array[j], array[j + 1]);
			}
		}
	}
}

stock Sort::Selection(array[], const len = sizeof array)
{
    for(new i = 0; i < len - 1; i++) 
    {
        new m = i;
        for(new j = i + 1; j < len; j++) 
        {
            if(array[j] < array[m])
                m = j;
        }
        Var::Swap(array[m], array[i]);
    }
}

stock Sort::Insertion(array[], const len = sizeof array)
{
    new k, j;
    for(new i = 1; i < len; i++)
    {
        k = array[i];
        j = i - 1;
        while(j >= 0 && array[j] > k)
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = k;
    }
}

stock Sort::Gnome(array[], const len = sizeof array)
{
    new i = 0;
    while(i < len)
    {
        if(i == 0) i++;
        if(array[i] >= array[i - 1])
        { 
            i++;
        } 
        else 
        {
            Var::Swap(array[i], array[i - 1]);
            i--;
        }
    }
}
stock Sort::Shaker(array[], len = sizeof array)
{
    new i, j, k;
    for(i = 0; i < len;) 
    {
        for(j = i + 1; j < len; j++) 
        {
            if(array[j] < array[j - 1])
                Var::Swap(array[j], array[j - 1]);
        }
        len--;
        for(k = len - 1; k > i; k--) 
        {
            if(array[k] < array[k - 1])
                Var::Swap(array[k], array[k - 1]);
        }
        i++;
    }
}

stock Sort::OddEven(array[], const len = sizeof array)
{
    new isSorted = 0;
    while (!isSorted) 
    {
        isSorted = 1;
        for (new i = 1; i <= len - 2; i += 2) 
        {
            if (array[i] > array[i + 1]) 
            {
                Var::Swap(array[i], array[i + 1]);
                isSorted = 0;
            }
        }
        for (new i = 0; i <= len - 2; i += 2) 
        {
            if (array[i] > array[i + 1]) 
            {
                Var::Swap(array[i], array[i + 1]);
                isSorted = 0;
            }
        }
    }
}
stock Sort::Shell(array[], const len = sizeof array)
{
    new i, j, k;
    for (i = len / 2; i > 0; i = i / 2) 
    {
        for (j = i; j < len; j++) 
        {
            for(k = j - i; k >= 0; k = k - i) 
            {
                if (array[k + i] >= array[k])
                    break;
                else 
                {
                    Var::Swap(array[k], array[k + i]);
                }
            }
        }
    }
}

///////////////////////////////////
//          Logarithmic          //
///////////////////////////////////

stock Sort::Quick(array[], left, right)
{
    new tempLeft = left,
        tempRight = right,
        pivot = array[(left + right) / 2],
        tempVar;
    while(tempLeft <= tempRight)
    {
        while(array[tempLeft] < pivot) tempLeft++;
        while(array[tempRight] > pivot) tempRight--;
        if(tempLeft <= tempRight)
        {
            tempVar = array[tempLeft], array[tempLeft] = array[tempRight], array[tempRight] = tempVar;
            tempLeft++, tempRight--;
        }
    }
    if(left < tempRight) Sort::Quick(array, left, tempRight);
    if(tempLeft < right) Sort::Quick(array, tempLeft, right);
}

stock Sort::Heap(array[], const len = sizeof array)
{
    for (new i = len / 2 - 1; i >= 0; i--)
        PS_H_Heapify(array, len, i);
    for (new i = len - 1; i >= 0; i--)
    {
		Var::Swap(array[0], array[i]);
        PS_H_Heapify(array, i, 0);
    }
}

stock PS_H_Heapify(array[], n, i)
{
   	new largest = i;
    new l = 2 * i + 1;  
    new r = 2 * i + 2;  
    if (l < n && array[l] > array[largest])
        largest = l;

    if (r < n && array[r] > array[largest])
        largest = r;
    if (largest != i)
    {
        Var::Swap(array[largest], array[i]);
        PS_H_Heapify(array, n, largest);
    }
}

///////////////////////////////////
//             Weird             //
///////////////////////////////////

stock Sort::Bogo(array[], const len = sizeof array)
{
    while(!Array::IsSorted(array, len))
        Array::Shuffle(array, len);
}
