# 강제 종료를 위하여 sys 모듈을 불렀습니다.
import stack
import sys

# 입력값이 한 글자일 때 프로그램의 종료를 판단하는 함수 Q
def Q(lst):
    A = True
    B = True
    if len(lst) == 1:
        A = ('0' < lst and lst < '9')
        B = (lst == '+' or lst == '-' or lst == '*' or lst == '/' or lst == '=')
    if A or B:
        return True
    else:
        return False
    
lst = input('Enter an RPN expression: ')

while Q(lst):
    stk = stack.getStack()
    
    lst = lst.strip()
    lst = lst.split(' ')
    lst = list(lst)

    # 마지막 리스트 칸이 등호('=')가 아닐 경우
    if lst[len(lst) - 1] != '=':
        print('Evaluation error')
        sys.exit()

    # 리스트 칸이 피연산자일 때 마다 x, 연산자일 때 마다 y에 숫자를 더합니다.
    # x는 0, y는 1부터 시작하였습니다.
    x = 0
    y = 1

    for k in range(len(lst)):
        if '0' <= lst[k] and lst[k] <= '9':
            stack.push(stk, int(lst[k]))
            x = x + 1
        elif lst[k] == '+':
            # 피연산자가 1개 뿐인 경우
            if len(stk) == 1:
                print('Evaluation error')
                sys.exit()
            a = stack.pop(stk)
            b = stack.pop(stk)
            stack.push(stk, b + a)
            y = y + 1
        elif lst[k] == '-':
            # 피연산자가 1개 뿐인 경우
            if len(stk) == 1:
                print('Evaluation error')
                sys.exit()
            a = stack.pop(stk)
            b = stack.pop(stk)
            stack.push(stk, b - a)
            y = y + 1
        elif lst[k] == '*':
            # 피연산자가 1개 뿐인 경우
            if len(stk) == 1:
                print('Evaluation error')
                sys.exit()
            a = stack.pop(stk)
            b = stack.pop(stk)
            stack.push(stk, b * a)
            y = y + 1
        elif lst[k] == '/':
            # 피연산자가 1개 뿐인 경우
            if len(stk) == 1:
                print('Evaluation error')
                sys.exit()
            a = stack.pop(stk)
            b = stack.pop(stk)
            stack.push(stk, b / a)
            y = y + 1
        
    # 피연산자와 연산자의 갯수가 맞지 않는 경우
    if x != y:
        print('Evaluation error')
        sys.exit()
   
    stk = float(stk[0])

    # 소숫점 아래가 0이 아니라면 실수 처리(파이썬 특성상 오차가 생길 수 있음)
    if stk.is_integer():
        print('Value of expression:', int(stk))
    else:
        print('Value of expression:', format(stk, '.2f'))
        
    lst = input('Enter an RPN expression: ')
