# Pawn.Sort
Sorting algorithms for Pawn 

### Author: Tornamic (Kirill Tymoshchenko)
    Discord: https://pastebin.com/raw/LMBNfFHE
    Github: https://github.com/Tornamic
    pawn.wiki https://pawn.wiki/i.php?/user/54232-tornamic/
### Installation
```pawn
#include <Pawn.Sort>
```
### Example
```pawn
main()
{
    new array[100];
    Array::FillRandomValues(array);
    print("Bubble sort:");
    Sort::Bubble(array);
    Array::Print(array);
}
```
#### Quadratic Sort Functions 
```pawn
Sort::Bubble(array[], const len = sizeof array)
Sort::Selection(array[], const len = sizeof array) 
Sort::Insertion(array[], const len = sizeof array)
Sort::Gnome(array[], const len = sizeof array)
Sort::Shaker(array[], len = sizeof array)
Sort::OddEven(array[], const len = sizeof array)
```
#### Logarithmic Sort Functions
```pawn
Sort::Quick(array[], left, right) 
Sort::Heap(array[], const len = sizeof array) 
Sort::Shell(array[], const len = sizeof array) 
```
#### Misc Functions
```pawn
Var::Swap(&value1, &value2)
Array::FillRandomValues(array[], const len = sizeof array, randmin = -10000, randmax = 10000)
Array::Print(array[], const len = sizeof array)
Array::Shuffle(array[], const len = sizeof array)
Array::IsSorted(const array[], const len = sizeof array)
```
### Speed (less is better)
<ul>
 <li>Quick sort: 4</li>
 <li>Shell sort: 5</li>
 <li>Heap sort: 9</li>
 <li>Insertion sort: 12</li>
 <li>Selection sort: 14</li>
 <li>Shaker sort: 25</li>
 <li>Gnome sort: 27 </li>
 <li>OddEven sort: 28</li>
 <li>Bubble sort: 44</li>
 <li>Bogo sort: Infinity</li>
</ul>
