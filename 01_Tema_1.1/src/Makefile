EXE:= test_g.exe
EXE1:=TEST_MCD.exe
EXE2:=TEST_SIM.exe
EXE3:=TESTCONV.exe
MY_TOCLEAN := $(EXE) $(EXE1) $(EXE2) $(EXE3)
CC=g++
MYCXXFLAGS = -DUSING_SIMPLIFICAR -DSECONDS_TO_MINS_PLUS_SECONDS -I./

all:$(EXE) $(EXE1) $(EXE2) $(EXE3)
segundosAMinutosMasSegundos:$(EXE3)
simplificar:$(EXE2)
default:$(EXE1)

#SOURCE:=$(wildcard *.cpp)

$(EXE): TestFunciong.cpp funciong.cpp
	$(CC) $^ -o $@
$(EXE1):mcd.cpp testMcd.cpp
	$(CC) $^ -o $@
$(EXE2):mcd.cpp testMcd.cpp
	$(CC) -DUSING_SIMPLIFICAR $^ -o $@
$(EXE3):mcd.cpp testMcd.cpp
	$(CC) $(MYCXXFLAGS) $^ -o $@
clean:
	rm -v $(MY_TOCLEAN)

