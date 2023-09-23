#ifndef STEGANOGRAPHY_H
#define STEGANOGRAPHY_H

#include <iostream>
#include <vector>

using namespace std;

class Steganography {
 private:
  string magicNumber;
  int width;
  int height;
  int maxColor;
  vector<int> colorData;
  string cipherText;
  int getNthBit(char cipherChar, int n);

 public:
  void readImage(string fileName);
  void printImage(string fileName);
  void printCipherText(string fileName);
  void readCipherText(string fileName);
  void cleanImage();
  void encipher();
  void decipher();
};
#endif
