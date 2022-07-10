n, m = map(int, input().split(" "))
graph = list(map(str, range(n, m+1)))
resGraph = tuple()
for i in range(0, m-n+1):
    ans = ""
    for j in range(0, len(graph[i])):
        now = graph[i][j]
        if now == '0':
            ans += 'zero'
        elif now == '1':
            ans += 'one'
        elif now == '2':
            ans += 'two'
        elif now == '3':
            ans += 'three'
        elif now == '4':
            ans += 'four'
        elif now == '5':
            ans += 'five'
        elif now == '6':
            ans += 'six'
        elif now == '7':
            ans += 'seven'
        elif now == '8':
            ans += 'eight'
        elif now == '9':
            ans += 'nine'
        if j != len(graph[i]) - 1:
            ans += ' '
    graph[i] = ans
graph.sort()
for i in graph:
    strList = list(map(str, i.split(" ")))
    printAns = ""
    for j in strList:
        if j == 'zero':
            printAns += '0'
        elif j == 'one':
            printAns += '1'
        elif j == 'two':
            printAns += '2'
        elif j == 'three':
            printAns += '3'
        elif j == 'four':
            printAns += '4'
        elif j == 'five':
            printAns += '5'
        elif j == 'six':
            printAns += '6'
        elif j == 'seven':
            printAns += '7'
        elif j == 'eight':
            printAns += '8'
        elif j == 'nine':
            printAns += '9'
    print(printAns)
