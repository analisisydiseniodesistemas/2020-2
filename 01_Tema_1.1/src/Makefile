EXE:= test_g.exe
EXE1:=TEST_MCD.exe
CC=g++

default:$(EXE1)

SOURCE:=$(wildcard *.cpp)

$(EXE):$(SOURCE)
	$(CC) $^ -o $@
$(EXE1):mcd.cpp testMcd.cpp
	$(CC) $^ -o $@
clean:
	rm -v $(EXE) $(EXE1)

