import random
import sys
def grab(seed,a,b,c,d,e):
    level =[a,b,c,d,e]
    random.seed(seed)
    print(seed)
    return random.sample(level, 1)[0]

