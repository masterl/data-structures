# Stack

## Summary

A stack is (as it's name implies) a stack of data.
Just like a stack of plates, you can only put or remove from top.

Of course, in reality you could lift some of the plates and insert one in the middle if you are careful enough.
But the goal of a stack in programming is to guarantee that something can only be placed on the top and if we want something in the middle, we need to first remove all the other on top of it before accessing it.

The act of putting something on the stack is named `push`.
So we say that we push a value into the stack.
The value will be placed on the top.

The act of removing something from the stack is named `pop`.
So we say that we pop an item from the stak.
Obviously, the previously second item is now on the top of the stack.

One use example would be trying to validate if a program has any errors regarding the amount of opening and closing braces, parenthesis or brackets.

Say we had this snippet:

```cpp
if ((a > b) == c && (c < a)
{
  // some code
}
```

We could use a stack to check if the amount of opening and closing parenthesis are correct in the if line using the following simple algorithm:

- For each character (on the if line):

  1. If it's a opening parenthesis, put it on the stack

  2. If it's a closing parenthesis, remove one item from the stack

    2.1. If the stack is empty, throw a syntax error

- After going through the whole line, if the stack isn't empty, throw syntax error

#### Exemple

- Step 1

```
if ((a > b) == c && (c < a)
   ^



Stack:
```

It's an opening parenthesis, so we put on the stack.

- Step 2

```
if ((a > b) == c && (c < a)
    ^



Stack: (
```

It's an opening parenthesis, so we put on the stack.

- Step 3

```
if ((a > b) == c && (c < a)
          ^


       (
Stack: (
```

It's a closing parenthesis, so we look at the stack.
The stack isn't empty, so we just remove the top item.

- Step 4

```
if ((a > b) == c && (c < a)
                    ^



Stack: (
```

It's an opening parenthesis, so we put on the stack

- Step 5

```
if ((a > b) == c && (c < a)
                          ^


       (
Stack: (
```

It's a closing parenthesis, so we look at the stack.
The stack isn't empty, so we just remove the top item.

- Step 6

```
if ((a > b) == c && (c < a)




Stack: (
```

We finished processing the if line.
The stack isn't empty, this means that a parenthesis was opened but wasn't closed and we throw this error.

Of course this was a simple example, assuming the if can only be contained on a line and only looking for parenthesis, but we could check for square brackets and curly braces too.
