import io
import argparse
import array

# Set up parser
parser = argparse.ArgumentParser()
parser.add_argument("filename", help="Name of the file containing input data")
args = parser.parse_args()

fp = open(file=args.filename, mode='r')

print("Reading input from " + args.filename)
input_nums = array.array('i')
length = 0
for line in fp:
    print('added ' + line, end="")
    input_nums.append(int(line))
    length += 1

print("\nFinal Array length: " + str(length))

fp.close()