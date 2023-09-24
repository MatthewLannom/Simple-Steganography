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
  outFile << magicNumber << endl;
  outFile << width << " " << height << endl;
  outFile << maxColor << endl;
  vector<int>::iterator it;
  for(it=colorData.begin(); it !=colorData.end();it++){
    outFile<<*it<<" ";
  }
  outFile.close();
}


void Steganography::printCipherText(string fileName){
  //Add code here
  ofstream Outfile;
  Outfile.open(fileName);
  Outfile<<cipherText;
  Outfile.close();
}
void Steganography::cleanImage(){
  //Add code here
  vector<int>::iterator it;
  for(it=colorData.begin(); it!=colorData.end(); it++){
    if(*it%2!=0){
      *it-=1;
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

  for(int i=0;i<cipherText.length()*8;i++){
    colorData[i]+=binary[i];
  }
}

void Steganography::decipher(){
  //Add code here
  vector<int> binary;
  
  vector<int>::iterator it;
  for(it=colorData.begin(); it!=colorData.end(); it++){
    if(*it%2==0){
      binary.push_back(0);
    }
    else{
      binary.push_back(1);
    }
  }
  vector<int> decimal;
  for(it=binary.begin(); it!=binary.end(); it+8){
    decimal.push_back(getDecimal(it));
  }
  cout<<"test"<<endl;
  for(it=decimal.begin(); it!=decimal.end(); it++){
    cipherText+=*it;
  }
  cout<<"test"<<endl;
}

int Steganography::getDecimal(vector<int>::iterator &it){
  cout<<"test1"<<endl;
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
  cout<<"test2"<<endl;
  if(tenmil==1){
    tenmil=2*2*2*2*2*2*2;
  }
  if(mil==1){
    mil=2*2*2*2*2*2;
  }
  if(hunthous==1){
    hunthous=2*2*2*2*2;
  }
  if(tenthous==1){
    tenthous=2*2*2*2;
  }
  if(thousand==1){
    thousand=2*2*2;
  }
  if(hundred==1){
    hundred=2*2;
  }
  if(ten==1){
    ten=2;
  }
  if(ones==1){
    ones=1;
  }

  int dec=tenmil+mil+hunthous+tenthous+thousand+hundred+ten+ones;
  cout<<*it;
  return dec;
}
