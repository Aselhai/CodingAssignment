import stack
import sys

stk = stack.getStack()

lst = list(input('Enter parentheses and/or braces: '))

for k in range(len(lst)):
    if lst[k] == '(':
        stack.push(stk, lst[k])
    elif lst[k] == '{':
        stack.push(stk, lst[k])
    elif lst[k] == ')':
        if stack.isEmpty(stk):
            print('Not properly nested.')
            sys.exit()
        if stack.pop(stk) != '(':
            print('Not properly nested.')
            sys.exit()
    elif lst[k] == '}':
        if stack.isEmpty(stk):
            print('Not properly nested.')
            sys.exit()
        if stack.pop(stk) != '{':
            print('Not properly nested.')
            sys.exit()

if stack.isEmpty(stk):
    print('Nested properly.')
else:
    print('Not properly nested.')
