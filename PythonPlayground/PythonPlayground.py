import time
import sys
from decimal import *
getcontext().prec=28

N = 2

def escalonamentolouco(mat):
 
    aaa = forwardElim(mat)
    if (aaa != -1):
        print("singular")
        if (mat[aaa][N]):
            print("fucked up")
        else:
            print("infinite")
        return
    aac(mat)

def aab(mat, i, j):
    for k in range(N + 1):
        temp = mat[i][k]
        mat[i][k] = mat[j][k]
        mat[j][k] = temp
 
def forwardElim(mat):
    for k in range(N):
        i_max = k
        v_max = mat[i_max][k]
        for i in range(k + 1, N):
            if (abs(mat[i][k]) > v_max):
                v_max = mat[i][k]
                i_max = i
        if not mat[k][i_max]:
            return k   
        if (i_max != k):
            aab(mat, k, i_max)
        for i in range(k + 1, N):
            f = mat[i][k]/mat[k][k]
            for j in range(k + 1, N + 1):
                mat[i][j] -= mat[k][j]*f
            mat[i][k] = 0
    return -1
def aac(mat):
    x = [None for _ in range(N)]
    for i in range(N-1, -1, -1):
        x[i] = mat[i][N]
        for j in range(i + 1, N):
            x[i] -= mat[i][j]*x[j]
        x[i] = (x[i]/mat[i][i]) 

#def factorial():
    #b=100
    #a=1
    #c=1
    #for x in range(b):
        #a=a*c
        #c+=1

def factorial(n):
    res = [None]*500
    # Initialize result
    res[0] = 1
    res_size = 1
 
    # Apply simple factorial formula
    # n! = 1 * 2 * 3 * 4...*n
    x = 2
    while x <= n:
        res_size = multiply(x, res, res_size)
        x = x + 1
 
    i = res_size-1
    while i >= 0:
        #sys.stdout.write(str(res[i]))
        #sys.stdout.flush()
        i = i - 1

def multiply(x, res, res_size):
 
    carry = 0  # Initialize carry
 
    i = 0
    while i < res_size:
        prod = res[i] * x + carry
        res[i] = prod % 10  # Store last digit of

        carry = prod//10  # Put rest in carry
        i = i + 1
 
    # Put carry in res and increase result size
    while (carry):
        res[res_size] = carry % 10
        # make sure floor division is used
        # to avoid floating value
        carry = carry // 10
        res_size = res_size + 1
 
    return res_size

mat = [[3.0, 2.0, -4.0], [2.0, 3.0, 3.0]]

def Escalonamento20LinhasContado():
    writeplease = open("RawData.txt", "a")
    writeplease.write("All of the following numbers are in seconds"+"\n\n")
    writeplease.close()
    y=1
    for x in range (20):
        st=time.time()
        for x in range(1000000):
            escalonamentolouco(mat)
        et=time.time()
        tt=et-st
        tt=tt/1000000
        #print(tt)
        randomVariable = open("RawData.txt", "a")
        randomVariable.write("Matrix #"+str(y)+": "+str(tt)+"\n")
        y+=1

def Fatorial20LinhasContado():
    y=1
    for x in range (20):
        st=time.time()
        for x in range(1):
            factorial(100)
        et=time.time()
        tt=et-st
        tt=tt
        #print(tt)
        randomVariable = open("RawData.txt", "a")
        randomVariable.write("Factorial of 100 #"+str(y)+": "+str(tt)+"\n")
        y+=1

def WriteTextFunction():
    randomVariable = open("RickRolled.txt", "a")    
    randomVariable.write("We're no strangers to love You know the rules and so do I (do I) A full commitment's what I'm thinking of You wouldn't get this from any other guy I just wanna tell you how I'm feeling Gotta make you understand Never gonna give you up Never gonna let you down Never gonna run around and desert you Never gonna make you cry Never gonna say goodbye Never gonna tell a lie and hurt you We've known each other for so long Your heart's been aching, but you're too shy to say it (say it) Inside, we both know what's been going on (going on) We know the game and we're gonna play it And if you ask me how I'm feeling Don't tell me you're too blind to see Never gonna give you up Never gonna let you down Never gonna run around and desert you Never gonna make you cry Never gonna say goodbye Never gonna tell a lie and hurt you Never gonna give you up Never gonna let you down Never gonna run around and desert you Never gonna make you cry Never gonna say goodbye Never gonna tell a lie and hurt you We've known each other for so long Your heart's been aching, but you're too shy to say it (to say it) Inside, we both know what's been going on (going on) We know the game and we're gonna play it I just wanna tell you how I'm feeling Gotta make you understand Never gonna give you up Never gonna let you down Never gonna run around and desert you Never gonna make you cry Never gonna say goodbye Never gonna tell a lie and hurt you Never gonna give you up Never gonna let you down Never gonna run around and desert you Never gonna make you cry Never gonna say goodbye Never gonna tell a lie and hurt you Never gonna give you up Never gonna let you down Never gonna run around and desert you Never gonna make you cry Never gonna say goodbye Never gonna tell a lie and hurt you\n")

def WriteTextCounterTT():
    y=1
    for x in range (20):
        st=time.time()
        for x in range(10000):
            WriteTextFunction()
        et=time.time()
        tt=et-st
        tt=tt/10000
        #print(tt)
        randomVariable = open("RawData.txt", "a")
        randomVariable.write("TextWriter #"+str(y)+": "+str(tt)+"\n")
        y+=1

def VectorOperations():
    yaxis1=12
    xaxis1=21
    yaxis2=14
    xaxis2=123
    yaxisr=yaxis1+yaxis2
    xaxisr=xaxis1+xaxis2

def VectorCounterTT():
    y=1
    for x in range (20):
        st=time.time()
        for x in range(10000):
            VectorOperations()
        et=time.time()
        tt=et-st
        tt=tt/10000
        #print(tt)
        randomVariable = open("RawData.txt", "a")
        randomVariable.write("Vector Sum #"+str(y)+": "+str(tt)+"\n")
        y+=1

#were no strangers to love
#u kno the rules and so do i

Escalonamento20LinhasContado()
Fatorial20LinhasContado()
WriteTextCounterTT()
VectorCounterTT()

#1000000 range ==0.018 second to run in python