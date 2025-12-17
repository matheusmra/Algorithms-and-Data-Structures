while True:
    L, R = map(int, input().split())
    if L == 0 and R == 0:
        break
    if L >= 1 and L <= 5 and R >= 1 and R <= 5:
        print(L + R)
