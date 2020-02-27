/**test_ATA.cpp*/
#include <stdio.h>
#include <AddressTranslationArchitecture.h>

int main(){
  struct AddressTranslationArchitecture ATA;
  ATA.pageTable.push_back(0x0);   /*page index 0*/
  ATA.pageTable.push_back(0x300); /*page index 1*/
  ATA.pageTable.push_back(0x200); /*page index 2*/
  /**Calcular la direcci\'on f\'isica correspondiente 
   * a la direcci\'on virtual 0x01:0x40 */
  unsigned int pba=ATA.getBasePhysAddress(0x01);
  unsigned int pa=ATA.calculatePhysAddress(pba,0x40);
  printf("V2P(0x01:0x40)=%p\n",pa);

  return 0;
}/*end main()*/
