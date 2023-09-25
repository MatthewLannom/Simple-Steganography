/**
 * @file main.cpp
 * @author Kevin Austin
 * @date 2023-09-24
 * @brief Encodes or decodes ppm files
 * 
 * Takes the given ppm file and depending on whether the user wants to encode or decode, will act respectively
 */

#include <iostream>
#include <fstream>
#include <vector>

#include "Steganography.h"

using namespace std;

int main() {
  Steganography Steg;
  char opchoice;
  string ppmfile;
  string textfile;
  
  int c=0;
  while(c!=1){
    cout<<"Do you want to encode a ppm or decode a ppm? Use e or d"<<endl;
    cin>>opchoice;
    
    if(opchoice=='e'){
      cout<<"Enter ppm file name to encode"<<endl;
      cin>>ppmfile;
      cout<<"Enter a text file name"<<endl;
      cin>>textfile;
  
      Steg.readImage(ppmfile);
      cout<<"PPM file Read"<<endl;
      Steg.readCipherText(textfile);
      cout<<"Text file Read"<<endl;
      Steg.encipher();
      
      cout<<"Enter the ppm file you want to write into or create?"<<endl;
      string ppmfile2;
      cin>>ppmfile2;

      Steg.printImage(ppmfile2);
      
      c=1;
    }
    else if(opchoice=='d'){
      cout<<"Enter ppm file name"<<endl;
      cin>>ppmfile;
      Steg.readImage(ppmfile);
      cout<<"File Read"<<endl;

      Steg.decipher();
      cout<<"Enter text file to write into or create?"<<endl;
      cin>>textfile;

      Steg.printCipherText(textfile);

      c=1;
    }
    else{
      cout<<"Input must be e or d"<<endl;
	}
  }
  
  
  return 0;
}
