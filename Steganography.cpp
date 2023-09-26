/**
 * @file Steganography.cpp
 * @author Matthew Lannom
 * @date 2023-09-24
 * @brief Steganography
 * 
 * Contains the code for the methods in the Steganography class
 */

#include "Steganography.h"
#include <iostream>
#include <fstream>
#include <vector>

//Private Methods
int Steganography::getNthBit(char cipherChar, int n){
  int binary = (cipherChar>>n) % 2; //Finding the Nth binary bit of cipherChar 
  return binary;
}

int Steganography::getDecimal(vector<int>::iterator &it){
  //The following 8 variables represent the 8 bits of binary used to store one character
  int tenmil=*it; 
  it++;
  int mil=*it;
  it++;
  int hunthous=*it;
  it++;
  int tenthous=*it;
  it++;
  int thousand=*it;
  it++;
  int hundred=*it;
  it++;
  int ten=*it;
  it++;
  int ones=*it;
  //Converting binary to decimal by setting the 1 values equal to 2^n where n is which bit in the sequence it is 
  if(tenmil==1){
    tenmil=2*2*2*2*2*2*2; //This is the same as 2^7. It is written this way because we are not using the <cmath> library
  }
  if(mil==1){
    mil=2*2*2*2*2*2; //2^6
  }
  if(hunthous==1){
    hunthous=2*2*2*2*2; //2^5
  }
  if(tenthous==1){
    tenthous=2*2*2*2; //2^4
  }
  if(thousand==1){
    thousand=2*2*2; //2^3
  }
  if(hundred==1){
    hundred=2*2; //2^2
  }
  if(ten==1){
    ten=2; //2^1
  }
  if(ones==1){
    ones=1; //2^0
  }

  int dec=tenmil+mil+hunthous+tenthous+thousand+hundred+ten+ones;
  return dec;
}

//Public Methods
void Steganography::readImage(string fileName){
  ifstream Infile;
  Infile.open(fileName); //Opening file
  
  Infile>>magicNumber; //Reading in the P3 value (or other value for different PPM formats)
  Infile>>width>>height; //Reading in the width and height of the image
  Infile>>maxColor; //Reading in the maximum color depth of the image 

  int data;
  Infile>>data; //Priming read (Reading in the color values from a PPM file)
  
  while(Infile){
    colorData.push_back(data); //Filling in a vector with data from the file
    Infile>>data; //Reading in the color values from a PPM file
  }
  Infile.close(); //Closing file
}

void Steganography::readCipherText(string fileName){
  ifstream Infile;
  Infile.open(fileName); //Opening file
  string temp; //Temporary variable
  getline(Infile, temp); //Priming read (Reading in lines from a text file)
  cipherText=temp; 
  while(Infile){
    getline(Infile, temp); //Reading in lines from a text file
    cipherText+=temp; //Concatenating lines together and storing them in cipherText
  }
  Infile.close(); //Closing file
}

void Steganography::printImage(string fileName){
  ofstream outFile;
  outFile.open(fileName); //Opening file
  outFile << magicNumber << endl; //Writing the P3 value to the file
  outFile << width << " " << height << endl; //Writing the width and height to the file
  outFile << maxColor << endl; //Writing the max color depth to the file
  vector<int>::iterator it;
  for(it=colorData.begin(); it !=colorData.end();it++){
    outFile << *it << " "; //Writing the data stored in colorData into the file 
  }
  outFile.close(); //Closing file
}


void Steganography::printCipherText(string fileName){
  ofstream Outfile;
  Outfile.open(fileName); //Opening file
  Outfile << cipherText; //Writing the text that was deciphered from the PPM image into the text file
  Outfile.close(); //Closing file
}

void Steganography::cleanImage(){
  vector<int>::iterator it;
  for(it = colorData.begin(); it != colorData.end(); it++){
    if(*it % 2 != 0){
      *it -= 1; //Making all color values even by decrementing all odd values by one
   }
  }
}

void Steganography::encipher(){
  vector<int> binary; //A vector to hold the binary of cipherText
  
  for(int i = 0; i < cipherText.length(); i++){ 
    for(int j = 7; j >= 0; j--){
      binary.push_back(getNthBit(cipherText.at(i), j)); //Filling in the binary vector with binary retrieved with getNthbit
    }
  }
  
  cleanImage(); //Zeroing out the least significant bit

  for(int i = 0; i < cipherText.length() * 8; i++){
    colorData[i]+=binary[i]; //Adding the binary values to the color values of colorData to conceal the text
  }
}

void Steganography::decipher(){
  vector<int> binary; //A vector to hold the binary of colorData
  
  vector<int>::iterator it;
  for(it = colorData.begin(); it!=colorData.end(); it++){
    if(*it % 2 == 0){
      binary.push_back(0); //Filling the binary vector with zeroes when this value of colorData is even
    }
    else{
      binary.push_back(1); //Filling the binary vector with ones when this value of colorData is odd
    }
  }
  vector<int> decimal; //A vector to hold decimal values
  for(it = binary.begin(); it != binary.end(); it++){
    decimal.push_back(getDecimal(it)); //Filling the decimal vector with decimal values found using the helper method getDecimal to convert from binary to decimal
  }
  for(it = decimal.begin(); it != decimal.end(); it++){
    cipherText += *it; //Changing the decimal values back into string and storing it in cipherText
  }
}
