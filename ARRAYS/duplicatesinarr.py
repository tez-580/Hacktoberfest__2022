from collections import Counter
 
l1 = [1,2,1,3,5,9,,2,3,4,5,1,1,2,5,6,7,8,9,9]
d = Counter(l1)
print(d)
 #KUSHAL SINH VAGHELA
new_list = list([item for item in d if d[item]>1])
print(new_list)
