infix to postfix: traverse left to right, use stack for operands/operators based on precedence

infix to prefix: teverse infix, convert to postfix, then reverse the result

postfix to infix = iterate left to right and used '('+ t2 + s[i] + t1 + ')'

prefix to infix = iterate from right to left and used '(' + t1 + s[i] + t2 + ')'

postfix to prefix = iterate from left to right and used  operator + t2 + t1

prefix to postfix = iterate from right to left and used t1 + t2 + operator 