# Truth_Table_Generator
Small C++ code that generates an ASCII Truth Table for any Boolean Expression

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
