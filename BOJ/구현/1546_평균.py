n = int(input())
scoreList = list(map(int, input().split(" ")))
maxScore = max(scoreList)
total = 0
for i in range(n):
    total += scoreList[i]/maxScore*100
print(total/n)
