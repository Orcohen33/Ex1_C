CC = gcc
AR = ar
FLAGS = -Wall -g
BASIC = basicClassification.o
ADVANCEDLOOP = advancedClassificationLoop.o
ADVANCEDRECURSIVE = advancedClassificationRecursion.o
MAIN =main.o


all: mains maindloop maindrec libclassrec.a libclassrec.so libclassloops.a libclassloops.so

loops: libclassloops.a
loopd: libclassloops.so
recursives: libclassrec.a
recursived: libclassrec.so




mains: $(MAIN) libclassrec.a 
	$(CC) $(FLAGS) -o mains $(MAIN) ./libclassrec.a -lm

maindloop: $(MAIN) libclassloops.so
	$(CC) $(FLAGS) -o maindloop $(MAIN) ./libclassloops.so -lm

maindrec: $(MAIN) libclassrec.so
	$(CC) $(FLAGS) -o maindrec $(MAIN) ./libclassrec.so -lm


#static library
libclassloops.a: $(BASIC) $(ADVANCEDLOOP)
	$(AR) -rcs libclassloops.a $(BASIC) $(ADVANCEDLOOP)

libclassrec.a: $(BASIC) $(ADVANCEDRECURSIVE)
	$(AR) -rcs libclassrec.a $(BASIC) $(ADVANCEDRECURSIVE)
#dynamic library
libclassloops.so: $(BASIC) $(ADVANCEDLOOP)
	$(CC) -shared -o libclassloops.so $(BASIC) $(ADVANCEDLOOP)

libclassrec.so: $(BASIC) $(ADVANCEDRECURSIVE)
	$(CC) -shared -o libclassrec.so $(BASIC) $(ADVANCEDRECURSIVE)






#objects
basicClassification.o: basicClassification.c NumClass.h
	$(CC) $(FLAGS) -c basicClassification.c

advancedClassificationLoop.o: advancedClassificationLoop.c NumClass.h
	$(CC) $(FLAGS) -c advancedClassificationLoop.c

advancedClassificationRecursion.o: advancedClassificationRecursion.c NumClass.h
	$(CC) $(FLAGS) -c advancedClassificationRecursion.c

main.o: main.c NumClass.h
	$(CC) $(FLAGS) -c main.c


clean:
	rm -f *.o *.a *.so mains maindloop maindrec

