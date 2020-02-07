EXE := runTimeAssert.exe
EXE1 := compileTimeAssert.exe
EXE2 := dcompileTimeAssert.exe
EXE3 := dcompileTimeChecker.exe
TOCLEAN := $(EXE) $(EXE1) $(EXE2) $(EXE3)
CC = g++

myall:$(EXE3)
all:$(EXE2)
default:$(EXE) $(EXE1)

$(EXE):A_CompileTime_Assertions.cpp
	$(CC) -DRUNTIME_ASSERTION $< -o $@
$(EXE1):A_CompileTime_Assertions.cpp
	$(CC) -DCOMPILETIME_ASSERTION $< -o $@
$(EXE2):B_CompileTime_Assertions.cpp
	$(CC) -DCOMPILETIME_ASSERTION $< -o $@
$(EXE3):B_CompileTimeChecker.cpp
	$(CC) -DUSANDO_MAKE $< -o $@
clean:
	rm -v $(TOCLEAN)
