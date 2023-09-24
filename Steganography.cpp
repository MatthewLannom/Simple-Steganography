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
  ofstream outFile;
  outFile.open(fileName);
  int temp = width*height;
  temp *= 3;
  outFile << magicNumber << endl;
  outFile << width << " " << height << endl;
  outFile << maxColor << endl;
  for(int i = 0; i < temp; i++){
    outFile << colorData[i] << " ";
  }
  outFile.close();
}


void Steganography::printCipherText(string fileName){
  //Add code here
}
void Steganography::cleanImage(){
  //Add code here
  int temp = (width*height)*3;
  for(int i = 0; i < temp; i++){
    if(colorData[i]%2!=0){
      colorData[i]-=1;
    }
  }
}
void Steganography::encipher(){
  //Add code here
  vector<int> binary;
  
  for(int i=0;i<cipherText.length();i++){
    for(int j=7;j>=0;j--){
      binary.push_back(getNthBit(cipherText.at(i), j));
    }
  }
  cleanImage();

  for(int i=0; i < cipherText.length()*8; i++){
    colorData[i]+=binary[i];
  }
  
}
void Steganography::decipher(){
//Add code here
}

