prerequisites = [[1,0],[0,1]]
combi = [list(x) for x in set(frozenset(item) for item in prerequisites)]

print(combi)