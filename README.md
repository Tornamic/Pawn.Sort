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
native Sort::Bubble(array[], const len = sizeof array);
native Sort::Selection(array[], const len = sizeof array);
native Sort::Insertion(array[], const len = sizeof array);
native Sort::Gnome(array[], const len = sizeof array);
native Sort::Shaker(array[], len = sizeof array);
native Sort::OddEven(array[], const len = sizeof array);
```
#### Logarithmic Sort Functions
```pawn
native Sort::Quick(array[], left, right);
native Sort::Heap(array[], const len = sizeof array); 
native Sort::Shell(array[], const len = sizeof array); 
```
#### Weird Sort Functions
```pawn
native Sort::Bogo(array[], const len = sizeof array);
```
#### Misc Functions
```pawn
native Var::Swap(&value1, &value2);
native Array::FillRandomValues(array[], const len = sizeof array, randmin = -10000, randmax = 10000);
native Array::Print(array[], const len = sizeof array);
native Array::Shuffle(array[], const len = sizeof array);
native Array::IsSorted(const array[], const len = sizeof array);
```
### Tests (less is better)
```pawn
Quick Sort: 0.057900ms
Shell Sort: 0.098600ms
Heap Sort: 0.145300ms
Insertion Sort: 0.212200ms
Selection Sort: 0.273199ms
Shaker Sort: 0.442599ms
Gnome Sort: 0.470999ms
OddEven Sort: 0.514299ms
Bubble Sort: 0.783600ms
Bogo Sort: Infinity
```
