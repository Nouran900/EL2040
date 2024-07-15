import sys
import os

def main():
    count = 0
    arguments = sys.argv[1:]  # Exclude the script name
    
    # Get the base name of the script
    script_name = os.path.basename(sys.argv[0])
    print('This is the name of the script:', script_name)
    
    # Print the list of command-line arguments
    print("Command-line arguments in list format:")
    print(arguments)
    
    # Print each command-line argument
    print("Command-line arguments individually:")
    for arg in arguments:
        print(arg)
        count += 1
    
    print(f"The number of arguments is {count}")

if __name__ == "__main__":
    main()
