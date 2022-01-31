EXE0:=00_Test_ATA.exe
LIMPIEZA:=*.o $(EXE0)
CC=g++
default:$(EXE0)
$(EXE0):test_ATA.o AddressTranslationArchitecture.o
	$(CC) $^ -o $@
test_ATA.o:test_ATA.cpp
	$(CC) -I./include -c $< -o $@
AddressTranslationArchitecture.o:AddressTranslationArchitecture.cpp
	$(CC) -I./include -c $< -o $@
clean:
	rm -v $(LIMPIEZA)
