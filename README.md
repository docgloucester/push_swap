# push_swap
My take at the dreaded push_swap project from the 42 Common Core.

# Objective

push_swap is an algorithmics project that allows one to become familiar with sorting algorithms and the notion of algorithmic complexity.

The context of the projets obeys the following rules :
- You have two stacks named A and B
- You are given a certain set of integer values that are all different, that initially populates the stack A
- You have at your disposal 11 operations on the stacks : rotate A (ra), rotate B (rb), rotate both (rr), their reverse counterparts (rra, rrb, rrr), switch the first two elements of A (sa), B (sb) or both (ss), pop the first element of B and push it on top of A (pa) and the opposite (pb)

You have to write in C a program named push_swap that will take as arguments an initial stack A and which will output a series of these 11 instructions that sorts this stack in ascending order.

What's interesting is that push_swap _isn't_ a sorting algorithm per se, but **an actual generator of sorting algorithms**!
You are expected to tweak it in order for it to be as efficient as possible in terms of number of operations in any given situation.

As such, the focus on complexity that you'll have to have won't be about your program in itself, but on its output in different scenarii :)

# Notes
I have also written a program that checks if the instructions output by push_swap actually sort the initially given stack

Here's an example of use on Linux:
```bash
# make both push_swap and checker
make full

# generate an array if STACKSIZE different integers, feeds it to push_swap, then pipe its output into checker, feeds it again to push_swap then count the number of instructions
ARG=$(shuf -i 0-10000 -n STACKSIZE | tr '\n' ' '); ./push_swap $ARG | ./checker $ARG; ./push_swap $ARG | wc -l
> OK # result of checker : the sorting algorithm output by push_swap is valid for the ARG stack
> NB_OPERATIONS # result of wc -l : the number of instructions of the generated sorting algorithm
```
