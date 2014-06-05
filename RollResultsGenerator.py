#python RollResultsGenerator.py > RollResults.txt
def creator(n):
        if (n!=0):
                c = creator(n-1)
                r = []
                f = []
                l = []
                for i in c:
                        r.append("r"+i)
                        f.append("f"+i)
                        l.append("l"+i)
                return r+l+f
        else:
                return [""]

maxim = 10
allMoves = [[],[],[]]
for i in range(maxim+1):
        c = creator(i)
        for j in c:
                allMoves[0].append(j) 

#0 = Green
#1 = Red
#2 = White
#3 = Orange
#4 = Yellow
#5 = Blue

def transform(string, cube):
        if(len(string)>1):
                return transform(string[1:], transform(string[0:1], cube))
        elif(len(string)==1):
            if (string == "r"):
                if (cube[0] == 0 and cube[1] == 1):
                        return [0,2]
                if (cube[0] == 0 and cube[1] == 2):
                        return [0,3]
                if (cube[0] == 0 and cube[1] == 3):
                        return [0,4]
                if (cube[0] == 0 and cube[1] == 4):
                        return [0,1]
                if (cube[0] == 1 and cube[1] == 0):
                        return [1,4]
                if (cube[0] == 1 and cube[1] == 2):
                        return [1,0]
                if (cube[0] == 1 and cube[1] == 4):
                        return [1,5]
                if (cube[0] == 1 and cube[1] == 5):
                        return [1,2]
                if (cube[0] == 2 and cube[1] == 0):
                        return [2,1]
                if (cube[0] == 2 and cube[1] == 1):
                        return [2,5]
                if (cube[0] == 2 and cube[1] == 3):
                        return [2,0]
                if (cube[0] == 2 and cube[1] == 5):
                        return [2,3]
                if (cube[0] == 3 and cube[1] == 0):
                        return [3,2]
                if (cube[0] == 3 and cube[1] == 2):
                        return [3,5]
                if (cube[0] == 3 and cube[1] == 4):
                        return [3,0]
                if (cube[0] == 3 and cube[1] == 5):
                        return [3,4]
                if (cube[0] == 4 and cube[1] == 0):
                        return [4,3]
                if (cube[0] == 4 and cube[1] == 1):
                        return [4,0]
                if (cube[0] == 4 and cube[1] == 3):
                        return [4,5]
                if (cube[0] == 4 and cube[1] == 5):
                        return [4,1]
                if (cube[0] == 5 and cube[1] == 1):
                        return [5,4]
                if (cube[0] == 5 and cube[1] == 2):
                        return [5,1]
                if (cube[0] == 5 and cube[1] == 3):
                        return [5,2]
                if (cube[0] == 5 and cube[1] == 4):
                        return [5,3]
            elif (string == "l"):
                if (cube[0] == 0 and cube[1] == 1):
                        return [0,4]
                if (cube[0] == 0 and cube[1] == 2):
                        return [0,1]
                if (cube[0] == 0 and cube[1] == 3):
                        return [0,2]
                if (cube[0] == 0 and cube[1] == 4):
                        return [0,3]
                if (cube[0] == 1 and cube[1] == 0):
                        return [1,2]
                if (cube[0] == 1 and cube[1] == 2):
                        return [1,5]
                if (cube[0] == 1 and cube[1] == 4):
                        return [1,0]
                if (cube[0] == 1 and cube[1] == 5):
                        return [1,4]
                if (cube[0] == 2 and cube[1] == 0):
                        return [2,3]
                if (cube[0] == 2 and cube[1] == 1):
                        return [2,0]
                if (cube[0] == 2 and cube[1] == 3):
                        return [2,5]
                if (cube[0] == 2 and cube[1] == 5):
                        return [2,1]
                if (cube[0] == 3 and cube[1] == 0):
                        return [3,4]
                if (cube[0] == 3 and cube[1] == 2):
                        return [3,0]
                if (cube[0] == 3 and cube[1] == 4):
                        return [3,5]
                if (cube[0] == 3 and cube[1] == 5):
                        return [3,2]
                if (cube[0] == 4 and cube[1] == 0):
                        return [4,1]
                if (cube[0] == 4 and cube[1] == 1):
                        return [4,5]
                if (cube[0] == 4 and cube[1] == 3):
                        return [4,0]
                if (cube[0] == 4 and cube[1] == 5):
                        return [4,3]
                if (cube[0] == 5 and cube[1] == 1):
                        return [5,2]
                if (cube[0] == 5 and cube[1] == 2):
                        return [5,3]
                if (cube[0] == 5 and cube[1] == 3):
                        return [5,4]
                if (cube[0] == 5 and cube[1] == 4):
                        return [5,1]
            else:
                if (cube[0] == 0 and cube[1] == 1):
                        return [3,0]
                if (cube[0] == 0 and cube[1] == 2):
                        return [4,0]
                if (cube[0] == 0 and cube[1] == 3):
                        return [1,0]
                if (cube[0] == 0 and cube[1] == 4):
                        return [2,0]
                if (cube[0] == 1 and cube[1] == 0):
                        return [5,1]
                if (cube[0] == 1 and cube[1] == 2):
                        return [4,1]
                if (cube[0] == 1 and cube[1] == 4):
                        return [2,1]
                if (cube[0] == 1 and cube[1] == 5):
                        return [0,1]
                if (cube[0] == 2 and cube[1] == 0):
                        return [5,2]
                if (cube[0] == 2 and cube[1] == 1):
                        return [3,2]
                if (cube[0] == 2 and cube[1] == 3):
                        return [1,2]
                if (cube[0] == 2 and cube[1] == 5):
                        return [0,2]
                if (cube[0] == 3 and cube[1] == 0):
                        return [5,3]
                if (cube[0] == 3 and cube[1] == 2):
                        return [4,3]
                if (cube[0] == 3 and cube[1] == 4):
                        return [2,3]
                if (cube[0] == 3 and cube[1] == 5):
                        return [0,3]
                if (cube[0] == 4 and cube[1] == 0):
                        return [5,4]
                if (cube[0] == 4 and cube[1] == 1):
                        return [3,4]
                if (cube[0] == 4 and cube[1] == 3):
                        return [1,4]
                if (cube[0] == 4 and cube[1] == 5):
                        return [0,4]
                if (cube[0] == 5 and cube[1] == 1):
                        return [3,5]
                if (cube[0] == 5 and cube[1] == 2):
                        return [4,5]
                if (cube[0] == 5 and cube[1] == 3):
                        return [1,5]
                if (cube[0] == 5 and cube[1] == 4):
                        return [2,5]
            elif (string == "f"):
                if (cube[0] == 0 and cube[1] == 1):
                        return [3,0]
                if (cube[0] == 0 and cube[1] == 2):
                        return [4,0]
                if (cube[0] == 0 and cube[1] == 3):
                        return [1,0]
                if (cube[0] == 0 and cube[1] == 4):
                        return [2,0]
                if (cube[0] == 1 and cube[1] == 0):
                        return [5,1]
                if (cube[0] == 1 and cube[1] == 2):
                        return [4,1]
                if (cube[0] == 1 and cube[1] == 4):
                        return [2,1]
                if (cube[0] == 1 and cube[1] == 5):
                        return [0,1]
                if (cube[0] == 2 and cube[1] == 0):
                        return [5,2]
                if (cube[0] == 2 and cube[1] == 1):
                        return [3,2]
                if (cube[0] == 2 and cube[1] == 3):
                        return [1,2]
                if (cube[0] == 2 and cube[1] == 5):
                        return [0,2]
                if (cube[0] == 3 and cube[1] == 0):
                        return [5,3]
                if (cube[0] == 3 and cube[1] == 2):
                        return [4,3]
                if (cube[0] == 3 and cube[1] == 4):
                        return [2,3]
                if (cube[0] == 3 and cube[1] == 5):
                        return [0,3]
                if (cube[0] == 4 and cube[1] == 0):
                        return [5,4]
                if (cube[0] == 4 and cube[1] == 1):
                        return [1,4]
                if (cube[0] == 4 and cube[1] == 3):
                        return [1,4]
                if (cube[0] == 4 and cube[1] == 5):
                        return [0,4]
                if (cube[0] == 5 and cube[1] == 1):
                        return [3,5]
                if (cube[0] == 5 and cube[1] == 2):
                        return [4,5]
                if (cube[0] == 5 and cube[1] == 3):
                        return [1,5]
                if (cube[0] == 5 and cube[1] == 4):
                        return [2,5]
            else:
                if (cube[0] == 0 and cube[1] == 1):
                        return [0,4]
                if (cube[0] == 0 and cube[1] == 2):
                        return [0,1]
                if (cube[0] == 0 and cube[1] == 3):
                        return [0,2]
                if (cube[0] == 0 and cube[1] == 4):
                        return [0,3]
                if (cube[0] == 1 and cube[1] == 0):
                        return [1,2]
                if (cube[0] == 1 and cube[1] == 2):
                        return [1,5]
                if (cube[0] == 1 and cube[1] == 4):
                        return [1,0]
                if (cube[0] == 1 and cube[1] == 5):
                        return [1,4]
                if (cube[0] == 2 and cube[1] == 0):
                        return [2,3]
                if (cube[0] == 2 and cube[1] == 1):
                        return [2,0]
                if (cube[0] == 2 and cube[1] == 3):
                        return [2,5]
                if (cube[0] == 2 and cube[1] == 5):
                        return [2,1]
                if (cube[0] == 3 and cube[1] == 0):
                        return [3,4]
                if (cube[0] == 3 and cube[1] == 2):
                        return [3,0]
                if (cube[0] == 3 and cube[1] == 4):
                        return [3,5]
                if (cube[0] == 3 and cube[1] == 5):
                        return [3,2]
                if (cube[0] == 4 and cube[1] == 0):
                        return [4,1]
                if (cube[0] == 4 and cube[1] == 1):
                        return [4,5]
                if (cube[0] == 4 and cube[1] == 3):
                        return [4,0]
                if (cube[0] == 4 and cube[1] == 5):
                        return [4,3]
                if (cube[0] == 5 and cube[1] == 1):
                        return [5,2]
                if (cube[0] == 5 and cube[1] == 2):
                        return [5,3]
                if (cube[0] == 5 and cube[1] == 3):
                        return [5,4]
                if (cube[0] == 5 and cube[1] == 4):
                        return [5,1]
        else:
                return cube

for i in range(len(allMoves[0])):
        allMoves[1].append(transform(allMoves[0][i],[0,1]))
        for j in range(i+1):
                if(allMoves[1][j] == allMoves[1][i]):
                        allMoves[2].append(allMoves[0][j])
                        break

for i in range(len(allMoves[0])):
        print allMoves[0][i]+"->"+allMoves[2][i]
