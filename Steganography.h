/**
 * @file Steganography.h
 * @author Kevin Austin
 * @date 2023-09-24
 * @brief The function definitions for Steganography class
 * 
 * Contains the class defintion Steganography
 */
#ifndef STEGANOGRAPHY_H
#define STEGANOGRAPHY_H

#include <iostream>
#include <vector>

using namespace std;

class Steganography {
 private:
  string magicNumber;//The PPM format value
  int width;//The image width
  int height;//The image height
  int maxColor;//Maximum color depth
  vector<int> colorData;//The integers of each color value for the PPM
  string cipherText;//The text that is to either be encoded or has been decoded

/**
 * A method used to return the nth bit from a character to be encoded
 *
 * @param char cipherChar The character to retrieve the nth bit from
 * @param int n the nth bit
 * @pre readImage was called
 * @return int returns the binary value for the nth bit
 * @post 
 * 
 */
  int getNthBit(char cipherChar, int n);

/**
 * A helper method made to convert the binary of a character to the ASCII of a character
 *
 * @param vector<int>::iterator &it A referecend iterator that points to the binary to be used
 * @pre readImage was called
 * @return int Returns the ASCII for the letter
 * @post 
 * 
 */
  int getDecimal(vector<int>::iterator &it);
  
 public:

/**
 * Reads the PPM file provided by fileName and stores the data in the member variables.
 *
 * @param string fileName The ppm file
 * @pre 
 * @return void 
 * @post string magicNUmber, int width, int height, int maxColor, and vector<int>colorData have data in them now
 * 
 */
  void readImage(string fileName);

/**
 * Reads the to be encoded text from the given fileName
 *
 * @param string fileName the name of the to be encoded text
 * @pre 
 * @return void 
 * @post cipherText has data in it
 * 
 */
  void readCipherText(string fileName);
  
/**
 * Prints the encoded information the PPM file into either a new PPM file or a preexisting one
 *
 * @param string fileName the PPM file to be written on
 * @pre 
 * @return void 
 * @post PPM file created/changed
 * 
 */
  void printImage(string fileName);

/**
 * Prints the decoded text from the PPM file to the fileName
 *
 * @param string fileName The file to write the text on
 * @pre 
 * @return void 
 * @post txt file created/changed
 * 
 */
  void printCipherText(string fileName);

/**
 * Zeros out the least significant bit of each color value in colorData.
 *
 * @pre readImage was called
 * @return void 
 * @post colorData has changed data
 * 
 */
  void cleanImage();

/**
 * Encrptys cipherText into colorData
 *
 * @pre readImage was called
 * @return void 
 * @post colorData was changed
 * 
 */
  void encipher();

/**
 * Decrypts colorData retrieved from PPM file
 *
 * @pre 
 * @return void 
 * @post cipherText created with decoded message
 * 
 */
  void decipher();
};
#endif //STEGANOGRAPHY_H
