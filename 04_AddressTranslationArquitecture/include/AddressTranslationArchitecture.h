/**AddressTranslationArchitecture.h*/
#ifndef ATA_H 
#define ATA_H
#include <vector>
using std::vector;

struct AddressTranslationArchitecture{
  unsigned int pageIndex;
  unsigned int displacement;
  vector<unsigned int> pageTable;
  
  unsigned int getBasePhysAddress(unsigned int pageI);
  unsigned int calculatePhysAddress(
               unsigned int basePhysAddr,
               unsigned int displ);
};/*end struct AddressTranslationArchitecture*/
#endif /*ATA_H*/
