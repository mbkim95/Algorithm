def solution(p):
    if is_correct(p):
        return p

    u, v = divide_string(p)

    if is_correct(u):
        return u + solution(v)
    else:
        temp = '(' + solution(v) + ')'
        u = list(u[1:-1])
        for i in range(len(u)):
            if u[i] == '(':
                u[i] = ')'
            else:
                u[i] = '('
        return temp + "".join(u)


def is_correct(p):
    stack = []
    for i in p:
        if i == '(':
            stack.append(i)
        else:
            if len(stack) == 0:
                return False
            stack.pop()
    if len(stack) == 0:
        return True
    return False


def divide_string(p):
    idx = 0
    count = 0
    for i in range(len(p)):
        idx += 1
        if p[i] == '(':
            count += 1
        else:
            count -= 1
        if count == 0:
            break
    u = p[:idx]
    v = p[idx:]
    return (u, v)
