/**test_ATA.cpp*/
#include <stdio.h>
#include <AddressTranslationArchitecture.h>

int main(){
  struct AddressTranslationArchitecture ATA;
  ATA.pageTable.push_back(0x0);
  ATA.pageTable.push_back(0x100);
  ATA.pageTable.push_back(0x200);

  return 0;
}/*end main()*/
