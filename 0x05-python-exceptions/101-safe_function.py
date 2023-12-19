#!/usr/bin/python3

import sys

def safe_function(fct, *args):
    try:
        result = fct(*args)
        return result
    except Exception as err:
        print("Exception: {}".format(err), file=sys.stderr)
        return None

# Example usage:
# Define a function to test
# def example_function(x, y):
#     return x + y

# Call the safe_function with the defined function and arguments
# result = safe_function(example_function, 3, 4)
# if result is not None:
#     print("Result:", result)
# else:
#     print("Function execution failed")
