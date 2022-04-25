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
        f.close()

        with open("level_1.c", "w") as f:
            f.write(readData)
        f.close()
    level1(seed)

    def level2(seed):
        random.seed(seed) 
        strings = ["42", "47", "59", "67", "79"]
        strings2 = ["+", "-", "*"]

        with open("template_level_2.c", "r") as f:
            readData = f.read()
            replacement_1 = random.sample(strings2,1)[0]
            replacement_2 = random.sample(strings,1)[0]
            readData = readData.replace('stub_level_2_1',replacement_1) 
            readData = readData.replace('stub_level_2_2',replacement_2) 
        f.close()

        with open("level_2.c", "w") as f:
            f.write(readData)
        f.close()
    level2(seed<<2)
    
    def level3(seed):
        random.seed(seed) 
        strings = ["5", "7", "11", "13", "17"]
        strings2 = ["+", "-", "*"]

        with open("template_level_3.c", "r") as f:
            readData = f.read()
            replacement = random.sample(strings,1)[0]
            replacement2 = random.sample(strings2,1)[0]
            replacement3 = random.sample(strings2,1)[0]
            readData = readData.replace('stub_level_3',replacement) 
            readData = readData.replace('1_operand',replacement2) 
            readData = readData.replace('2_operand',replacement3) 
            readData = readData.replace('1_operand',replacement2) 
        f.close()

        with open("level_3.c", "w") as f:
            f.write(readData)
        f.close()
    level3(seed<<3)

    def level4(seed):
        random.seed(seed) 
        strings = ["2", "4", "8", "16", "32"]

        with open("template_level_4.c", "r") as f:
            readData = f.read()
            replacement = random.sample(strings,1)[0]
            readData = readData.replace('stub_level_4',replacement) 
        f.close()

        with open("level_4.c", "w") as f:
            f.write(readData)
        f.close()
    level4(seed<<4)

    def level5(seed):
        random.seed(seed) 
        strings = ["2", "3", "4", "5", "6"]

        with open("template_level_5.c", "r") as f:
            readData = f.read()
            replacement = random.sample(strings,1)[0]
            readData = readData.replace('stub_level_5',replacement) 
        f.close()

        with open("level_5.c", "w") as f:
            f.write(readData)
        f.close()
    level5(seed<<5)

    def level6(seed):
        random.seed(seed) 
        strings = ["7", "8", "9", "10", "11"]

        with open("template_level_6.c", "r") as f:
            readData = f.read()
            replacement = random.sample(strings,1)[0]
            readData = readData.replace('stub_level_6',replacement) 
        f.close()

        with open("level_6.c", "w") as f:
            f.write(readData)
        f.close()
    level6(seed<<6)

    def level7(seed):
        random.seed(seed) 
        strings = ["3", "5", "7", "9", "11"]

        with open("template_level_7.c", "r") as f:
            readData = f.read()
            replacement = random.sample(strings,1)[0]
            readData = readData.replace('stub_level_7',replacement) 
        f.close()

        with open("level_7.c", "w") as f:
            f.write(readData)
        f.close()
    level7(seed<<7)


    def level8(seed):
        random.seed(seed) 
        strings = ["5", "13", "19", "21", "24"]

        with open("template_level_8.c", "r") as f:
            readData = f.read()
            replacement = random.sample(strings,1)[0]
            readData = readData.replace('stub_level_8',replacement) 
        f.close()

        with open("level_8.c", "w") as f:
            f.write(readData)
        f.close()
    level8(seed<<8)
    
    def level9(seed):
        random.seed(seed) 
        strings = ["procrastination", "the firstie", "eecs", "the supe tax", "tours"]

        with open("template_level_9.c", "r") as f:
            readData = f.read()
            replacement = random.sample(strings,1)[0]
            readData = readData.replace('stub_level_9',replacement) 
        f.close()

        with open("level_9.c", "w") as f:
            f.write(readData)
        f.close()
    level9(seed<<8)

if (len(sys.argv) == 2):
    main(int(sys.argv[1]))
else:
    print("Error - Fromat: ./python3 generator.py 'seed'")
