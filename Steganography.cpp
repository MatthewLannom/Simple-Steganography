#include "Steganography.h"
#include <iostream>
#include <fstream>
#include <vector>

//Private Methods
int Steganography::getNthBit(char cipherChar, int n){
  char temp=cipherChar>>n;
  int bin=temp%2;
  return bin;
}

//Public Methods
void Steganography::readImage(string fileName){
  //Add code here
  ifstream Infile;
  Infile.open(fileName);
  
  Infile>>magicNumber;
  Infile>>width>>height;
  Infile>>maxColor;

  int temp=height*width;
  temp=temp*3;
  
  colorData.reserve(temp);

  int datatemp;
  Infile>>datatemp;
  
  while(Infile){
    colorData.push_back(datatemp);
    Infile>>datatemp;
  }
  Infile.close();
}

void Steganography::readCipherText(string fileName){
  ifstream Infile;
  Infile.open(fileName);
  string temp;
  getline(Infile, temp);
  cipherText=temp;
  while(Infile){
    getline(Infile, temp);
    cipherText+=temp;
  }
  Infile.close();
}

void Steganography::printImage(string fileName){
  //Add code here
  
}


void Steganography::printCipherText(string fileName){
  //Add code here
}
void Steganography::cleanImage(){
  //Add code here
  //Start here
}
void Steganography::encipher(){
  //Add code here
  vector<int> binary;
  
  for(int i=0;i<cipherText.length();i++){
    for(int j=7;j>=0;j--){
      binary.push_back(getNthBit(cipherText.at(i), j));
    }
  }
  for(int i=0;i<cipherText.length()*8;i++){
    if(i%8==0 && i>0){
      cout<<" ";
    }
    cout<<binary[i];
  }

  
}
void Steganography::decipher(){
//Add code here
}

