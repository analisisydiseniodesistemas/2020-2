EXE:=TestPlaneacionBasadaNCalendar.exe
EXE1:=CalendarTestDriver.exe
EXE2:=ADS_Planning_EJ2020.exe
EXE3:=ADS_TestingFecha.exe
OBJETOS:=Calendario.o Asignacion.o Dia.o
OBJETOSA:=CalendarioA.o AsignacionA.o DiaA.o util.o
CC=g++
#CXXFLAGS +=-DUSING_ARREGLO
CXXFLAGS +=-DCAL_GREGORIANO 
MYCXXFLAGS=-DUSING_ARREGLO
#all:$(EXE) $(EXE1)
all:$(EXE2)
default:$(EXE3)
$(EXE):$(OBJETOS) InVdOpS_AD2019.o 
	$(CC) $(MYCXXFLAGS) $^ -o $@
Calendario.o:../CommonFiles/Calendario.cpp
	$(CC) $(MYCXXFLAGS) -c $^ -o $@
Asignacion.o:../CommonFiles/Asignacion.cpp
	$(CC) $(MYCXXFLAGS) -c $^ -o $@
Dia.o:../CommonFiles/Dia.cpp
	$(CC) $(MYCXXFLAGS) -c $^ -o $@
InVdOpS_AD2019.o:InVdOpS_AD2019.cpp
	$(CC) $(MYCXXFLAGS) -c $^ -o $@
util.o:../CommonFiles/util.cpp
	$(CC) -DLEAPYEAR -c $^ -o $@
$(EXE2):$(OBJETOSA) test_Calendario.o bubbles.o
	$(CC) $^ -o $@
CalendarioA.o:../CommonFiles/Calendario.cpp
	$(CC) -DLEAPYEAR -c $^ -o $@
AsignacionA.o:../CommonFiles/Asignacion.cpp
	$(CC)  -c $^ -o $@
DiaA.o:../CommonFiles/Dia.cpp
	$(CC)  -c $^ -o $@
#test_Calendario.o:test_Calendario.cpp
#	$(CC)  -c $^ -o $@
Dummy.exe:dummy.o $(OBJETOSA)
	$(CC) -o $@ $^
CalendarioA.prep:../CommonFiles/Calendario.cpp
	$(CC) -DLEAPYEAR -E $^ -o $@
TestFechaPrep:TestFecha.cpp
	$(CC) -H -E $< -o $@
TestFecha.o:TestFecha.cpp
	$(CC) -I../CommonFiles/ -c $<
gettingdate.o:../CommonFiles/gettingdate.c
	$(CC) -c $^ -o $@
bubbles.o:../CommonFiles/bubbles.cpp
	$(CC) -I../CommonFiles/ -c $^ -o $@
$(EXE3):$(OBJETOSA) TestFecha.o gettingdate.o bubbles.o
	$(CC) $^ -o $@
clean:
	rm -v *.o *.exe *.stackdump
