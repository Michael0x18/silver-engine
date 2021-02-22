#PYTHON 2.6, NOT 3
import sys
line1 = raw_input();
line2 = raw_input();
line1="["+line1[1:-1]+"]";
line2="["+line2[1:-1]+"]";
list1=eval(line1);
list2=eval(line2);
list3=list();
for i in range(len(list1)):
	list3.append(list1[i]);
	list3.append(list2[i]);

print("{"+str(list3)[1:-1]+"}")