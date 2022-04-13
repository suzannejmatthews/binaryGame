import random
import sys
def main(seed):

    # Level1 c file generator based on some random seed
    def level1(seed):
        random.seed(seed) 
        strings = ["Assembly is so cool!",
        "DiveIntoSystems",
        "armAssembly",
        "iLoveEECS",
        "crackTheCode"]

        with open("template_level_1.c", "r") as f:
            readData = f.read()
            replacement = random.sample(strings,1)[0]
            readData = readData.replace('stub_level_1',replacement) 

        with open("level_1.c", "w") as f:
            f.write(readData)
    level1(seed)

    def level2(seed):
        random.seed(seed) 
        strings = ["42", "47", "59", "67", "79"]

        with open("template_level_2.c", "r") as f:
            readData = f.read()
            replacement = random.sample(strings,1)[0]
            readData = readData.replace('stub_level_2',replacement) 

        with open("level_2.c", "w") as f:
            f.write(readData)
    level2(seed<<2)
    
    def level3(seed):
        random.seed(seed) 
        strings = ["5", "7", "11", "13", "17"]

        with open("template_level_3.c", "r") as f:
            readData = f.read()
            replacement = random.sample(strings,1)[0]
            readData = readData.replace('stub_level_3',replacement) 

        with open("level_3.c", "w") as f:
            f.write(readData)
    level3(seed<<3)

main(232)
if (len(sys.argv) == 2):
    main(int(sys.argv[1]))
else:
    print("Error - Fromat: ./python3 generator.py 'seed'")
