# This code is contributed by
# visheshdvivedi (https://github.com/visheshdvivedi)

# Rotate array by a certain amount
def rotate_array(array, amount):

    # Store the array length in a variable
    length = len(array)

    # Perform rotation 'amount' number of times
    for _ in range(amount):

        # Store the array's first index value in temp variable
        temp_num = array[length - 1]

        # For each index, set the next index value to be
        # the previous index value, starting from 0
        for i in range(length - 1, -1, -1):
            array[i] = array[i-1]

        # Finally, set the first index value the temp_num value
        array[0] = temp_num


if __name__ == "__main__":
    array = [1, 2, 3, 4, 5, 6, 7, 8]
    print(f"Input array: {array}")
    amount = int(input("Enter the amount of rotation: "))
    rotate_array(array, amount)
    print(f"Rotated array: {array}")
