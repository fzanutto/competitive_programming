def main():
    for i in range(1,6):
        a = input().split()
        for j in range(1,6):
            if a[j-1] == '1':
                print(abs(3-i)+abs(3-j))
                return
                
main()
