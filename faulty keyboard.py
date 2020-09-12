T = input()
S = input()
op = 0

for j in range(len(S)):
    a = T.count(S[j])
    op += ((2*(j+1))*a)
if S in T:
    b = T.count(S)
    op -= ((len(S)*(len(S)+1))*b)
    op += b
print(op)





