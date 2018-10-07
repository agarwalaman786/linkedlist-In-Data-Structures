#using lambda fn tomake the program in only one line 
# we can make it in more than one line but we will try 
# it to make as simple as possible

l1 = [1,2,3]
l2 =[4,5,6]
# l3 = [7,8,9]

# l  = list(zip(l1,l2,l3))

# a1,a2,a3 = list(zip(*l))
# for i in l:
#     print(i[0]+i[1]+i[2]//3)


# def avarage_finder(l1,l2):
#     average = []
#     for pair in zip(l1,l2):
#         average.append(sum(pair)/len(pair))
#     return average

# print(avarage_finder([1,2,3],[4,5,6])) 

# average  = [lambda l1,l2:sum(pair)/len(pair) for pair in zip(l1,l2)]
# print(average)


# def avarage_finder(*args):
#     average = []
#     for pair in zip(*args):
#         average.append(sum(pair)/len(pair))
#     return average

#the same code in one line can be write as following:


avarage_finder = lambda *args:[sum(pair)/len(pair) for pair in zip(*args)]
print(avarage_finder([1,2,3],[4,5,6],[7,8,9])) 
