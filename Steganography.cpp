#include "Steganography.h"
#include <iostream>
#include <fstream>
#include <vector>

//Private Methods
int Steganography::getNthBit(char cipherChar, int n){
  //Add code here
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
  cout<<cipherText;
}

void Steganography::printImage(string fileName){
  //Add code here
  
}


void Steganography::printCipherText(string fileName){
  //Add code here
}
void Steganography::cleanImage(){
  //Add code here
}
void Steganography::encipher(){
  //Add code here
  
}
void Steganography::decipher(){
//Add code here
}

