Monty is a Monty Language bytecode interprater implementation written in C
Monty is a stack based vitual machine.

#Language reference
The following opcodes or instructions are implement
- push
push an integer to the top of stack
syntax; `push integer`
Example; `push 2`

- pop
Remove the element at the top of the stack
syntax; `pop`

- pint
Print the element at the top of stack
syntax; `pint`

- pall
Print all the elements in the stack one element par line
syntax `pall`

- nop
Do nothing
syntax; `nop`

- add
Add the top element to the second top element and remove the top element
syntax `add`
Example;
```monty
push 1
push 2
add
```
- sub
Subtract the top element from the second top element and remove the top element
syntax; `sub`
Example;
```monty
push 6
push 2
sub
```
- mul
Multiply the second top element by the top element and remove the top element
syntax; `mul`
Example
```monty
push 10
push 2
mul
```
- div
Divide the second top element by the top element and remove the top element
syntax; `div`
Example;
```monty
push 8
push 4
div
```
- mod
Replace the second top element with the remainder of dividing the second 
top element by the top element and remove the top element
syntax; `mod`
```monty
push 9
push 2
mod
```
- pchar
Print the char symbol for the integer value of the top element
syntax; `pchar`
Example;
```monty
push 67
pchar
```  
Usage: monty filename

