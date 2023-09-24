#include <iostream>
#include <fstream>
#include <vector>

#include "Steganography.h"

using namespace std;

int main() {
  //Add code here
  Steganography Steg;
  string opchoice;
  string ppmfile;
  string textfile;

  int c=0;
  while(c!=1){
    cout<<"Do you want to encode a ppm or decode a ppm? Use e or d"<<endl;
    cin>>opchoice;
    
    if(opchoice=="e"){
      cout<<"Enter ppm file name to encode"<<endl;
      cin>>ppmfile;
      cout<<"Enter a text file name"<<endl;
      cin>>textfile;
      
      Steg.readImage(ppmfile);

      Steg.readCipherText(textfile);
      Steg.encipher();
      c=1;
    }
    else if(opchoice=="d"){
      cout<<"Enter ppm file name"<<endl;
      cin>>ppmfile;
      c=1;
    }
    else{
      cout<<"Input must be e or d"<<endl;
	}
  }
  
  
  return 0;
}
