# This code is contributed by
# visheshdvivedi (https://github.com/visheshdvivedi)

# Function to reverse array/string
def reverse_array(string):

    # variable to store output string
    output_string = ""

    # length of the input string
    length = len(string)

    # run a for loop that runs from the last character of the input
    # string to the first character of the input string
    for iter in range(length-1, -1, -1):

        # add characters to the output string
        output_string += string[iter]

    # return the output string
    return output_string

if __name__ == "__main__":

    # driver code
    string = input("Enter string: ")
    string = reverse_array(string)
    print("Output:", string)