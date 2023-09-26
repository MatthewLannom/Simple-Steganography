/**
 * @file README.md
 * @author Kevin Austin
 * @date 2023-09-25
 * @brief Describes how program works
 * 
 * This README goes into some detail on how the program works and how to use it.
 */

How to call the program?
-The makefile compiles the program under the name Steg. So just issue ./Steg to run the program.

How we shared work?
-We decided to meet up in the lab to work on the project in person. That way we could talk and discuss how to go about programming it and how to troubleshoot any problems.
Because of that we did the same amount of work, but made chantes to files on seperate lab computers so whenever something worked on on of ours the other would get pull that working version.

Design choice
-For the most part we used the functions given. However, we made our own function for the Steg class that takes the deciphered binary from the colorData and changes it to the corresponding letters ASCII values
and returns it into a int vector. We have a while loop in main that runs as long as the user doesn't enter the appropiate choice. There are if and else statements in that while loop.
First is an if that runs the encoder if the user wanted to. The second runs decoder if user wanted. Third one runs if previous two didn't and tells the user to enter a correct choice and starts the loop over.

Challenges
-We ran into a few problems. The first being readImage because we were a bit confused on how to use it. Second being getNthbit for the same reason. Third being decipher because we set up one of
the loops to run to hard by accident. That really all there was to it.