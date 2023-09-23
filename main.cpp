#include <iostream>
#include <fstream>
#include <vector>

#include "Steganography.h"

using namespace std;

int main() {
  //Add code here
  Steganography Steg;
  string opchoice;
  string filename;
  
  cout<<"Do you want to encode a ppm or decode a ppm?"<<endl;
  cin>>opchoice;

  cout<<"Which file do you want to "<<opchoice<<"?"<<endl;
  cin>>filename;

  Steg.readImage(filename);
  
  return 0;
}
