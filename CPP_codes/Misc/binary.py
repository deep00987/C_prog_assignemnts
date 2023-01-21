input = int(input("Enter Binary string length: "))

def solution(input):
    M = 1000000007
    ele = [0, 1]
    res = []
    count = [0]

    helper([0], 0, -1, ele, res, count, 2, input)
    helper([1], 1, -1, ele, res, count, 2, input)

    print(res, count[0] % M)

def helper(num_str, parent, grand_parent, elem , res, count, curr_lvl, max_lvl):
    if len(num_str) == max_lvl:
        res.append(num_str[:])
        count[0] += 1
        return
    
    if curr_lvl == 2:
        if parent == 0:
            num_str.append(1)
            helper(num_str, 1, parent, elem, res, count, curr_lvl + 1, max_lvl)
            num_str.pop()
        else:
            num_str.append(0)
            helper(num_str, 0, parent, elem, res, count, curr_lvl + 1, max_lvl)
            num_str.pop()
    elif curr_lvl == max_lvl:
        if parent == 0:
            num_str.append(1)
            helper(num_str, 1, parent, elem, res, count, curr_lvl + 1, max_lvl)
            num_str.pop()
        else:
            num_str.append(0)
            helper(num_str, 0, parent, elem, res, count, curr_lvl + 1, max_lvl)
            num_str.pop()
    else:
        for e in elem:
            if e == parent and e == grand_parent:
                continue
            else:
                num_str.append(e)
                helper(num_str, e, parent, elem, res, count, curr_lvl + 1, max_lvl)
                num_str.pop()
        return

solution(input)