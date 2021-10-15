.PHONY: run build rebuild clean

#The FILE_NAME variable contains the filename
FILE_NAME = MyPtrs

run: build
	./MyPtrs

build: MyPtrs

MyPtrs: MyPtrs.o
	g++ -o MyPtrs MyPtrs.o

MyPtrs.o: MyPtrs_Test.cpp MyUnique_ptr/MyUnique_ptr.cpp MyUnique_ptr/MyUnique_ptr.h MyShared_ptr/MyShared_ptr.cpp MyShared_ptr/MyShared_ptr.h
	g++ -o MyPtrs.o -c MyPtrs_Test.cpp

rebuild: clean build

clean: 
	rm -vf MyPtrs.o MyPtrs