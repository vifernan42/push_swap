# push_swap

### Description

An algorithm to sort int values between 2 stacks with a set of instructions to manipulate both stacks.
  - Stack a contains a random amount of negative and/or positive numbers which cannot be duplicated.
  - Stack b is empty.

### Goal

The goal is to sort in ascending order numbers into stack a with no more than:
  - 5 moves with 3 values
  - 12 moves with 5 values
  - 800 moves with 100 values
  - 8000 moves with 500 values

### Instructions

| Moves | Description |
| - | - |
| sa | swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements) |
| sb | swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements) |
| ss | sa and sb at the same time |
| pa | push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty |
| pb | push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty |
| ra | rotate a - shift up all elements of stack a by 1. The first element becomes the last one |
| rb | rotate b - shift up all elements of stack b by 1. The first element becomes the last one |
| rr | ra and rb at the same time |
| rra | reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one |
| rrb | reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one |
| rrr | rra and rrb at the same time |
