/**AddressTranslationArchitecture.cpp*/
#include <AddressTranslationArchitecture.h>

unsigned int AddressTranslationArchitecture::calculatePhysAddress(
             unsigned int basePhysAddr,unsigned int displ){
  return (basePhysAddr+displ);                                  
}

unsigned int AddressTranslationArchitecture::getBasePhysAddress(
             unsigned int pageI){
  return pageTable[pageI];
}

