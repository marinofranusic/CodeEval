def main():
    for i in range(1,13):
        for j in range(1,13):
            print(str(i*j).rjust(4),end="")
        print("")
main()