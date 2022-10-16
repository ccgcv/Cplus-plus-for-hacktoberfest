# binary sreach in python

#note: input array must be sorted.
 
a=[2,4,7,11,16,17,23,25,29,33,36,38,42,45,47,51,55,59,62,67,69,73,75,77,83,86,89,91,94,99]


def search(l,h,a,key):
    if l<=h:
        m=int((l+h)/2)
        if a[m]>key:
            return search(l,m-1,a,key)
        elif a[m]<key:
            return search(m+1,h,a,key)
        else:
            print(key," is preant at location ",m)
            

    else:
        print(key," is absent.")





def main():

    key=int(input("Enter the element you want to search: "))

    l=0
    h=len(a)-1

    search(l,h,a,key)

main()
