import sys;
import re;


def main():
  input = sys.argv[1].split("\n")
  print("Hi, this is the output of the analysis:")
  functions = re.findall("([0-9a-z]{16} <[a-zA-Z_@.]+>:)", sys.argv[1])
  instructions=re.findall("([0-9a-z]{4}:(	)+([0-9a-z]{2} ){1,7} *	[a-z0-9]+)", sys.argv[1])
  instructionsCounter = {}
  for instruction in instructions:
    temp = instruction[0].replace(" ","").split("\t")
    if(temp[2] in instructionsCounter.keys()):
      instructionsCounter[temp[2]]+=1
    else:
      instructionsCounter[temp[2]]=1
  # print(instructionsCounter)
  print("You have %d kind of instructions in this object file:" % (len(instructionsCounter)))
  for key in instructionsCounter:
    print("%s     : Executed %d times" % (key ,instructionsCounter[key]))
  print("You have %d functions" % len(functions));
  for function in functions:
    temp = function.split();
    functionName = temp[1]
    print("%s : Located at %s addr" % (functionName[1:-2], temp[0]))
main();
