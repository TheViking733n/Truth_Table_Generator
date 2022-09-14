# Truth_Table_Generator
#### ASCII Truth Table Generator program written purely in C++


## Implementation details:
First the user input parsed by converting it into lowercase, removing spaces, inserting '.' operator in appropiate places, and the number of distinct variables are computed and stored in a string. Then the boolean expression is converted into postfix notation. Now the postfix expression can be easily evaluated, so bruteforce on all variables is applied to generate and print the Truth Table.


## Example Outputs:

```
Truth Table Generator

Use ' for NOT
Use + for OR
Use . for AND (optional)
Use () for grouping
Example: (A' + B)C'+(D' + E)

Enter any boolean expression (case-insensitive):
F = A + (B)

+-----+---+
| a b | F |
+-----+---+
| 0 0 | 0 |
| 0 1 | 1 |
| 1 0 | 1 |
| 1 1 | 1 |
+-----+---+
```

```
Truth Table Generator

Use ' for NOT
Use + for OR
Use . for AND (optional)
Use () for grouping
Example: (A' + B)C'+(D' + E)

Enter any boolean expression (case-insensitive):
F = (X' + Y)Z'

+-------+---+
| x y z | F |
+-------+---+
| 0 0 0 | 1 |
| 0 0 1 | 0 |
| 0 1 0 | 1 |
| 0 1 1 | 0 |
| 1 0 0 | 0 |
| 1 0 1 | 0 |
| 1 1 0 | 1 |
| 1 1 1 | 0 |
+-------+---+
```

```
Truth Table Generator

Use ' for NOT
Use + for OR
Use . for AND (optional)
Use () for grouping
Example: (A' + B)C'+(D' + E)

Enter any boolean expression (case-insensitive):
F = a.((b + c)a + b)   

+-------+---+
| a b c | F |
+-------+---+
| 0 0 0 | 0 |
| 0 0 1 | 0 |
| 0 1 0 | 0 |
| 0 1 1 | 0 |
| 1 0 0 | 0 |
| 1 0 1 | 1 |
| 1 1 0 | 1 |
| 1 1 1 | 1 |
+-------+---+
```

