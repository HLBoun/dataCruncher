/*
 * dataCruncher.cpp
 * Allows a user to enter in float values and automatically receive the min, max, and averages.
 * Huthsady Legend Boun
 * 20th October, 2024
 * Professor Victor Edwards
*/


#include <iostream>
#include <vector>
#include <fstream>

// Create the file we are gonna write to
std::ofstream report("report.txt"); 


// Global variable for how many numbers the user will put in 
int inputCounter;

// Variable for closing the program, if the user wants to
char progCloser = 'n';



// This vectors stores the data set.
std::vector<float> doubleVector{};





// Greets the user, gives instructions, and accepts inputs.
void promptFunc()
{
  std::cout << "Please tell me how many numbers you will be entering!" << std::endl;
  std::cin >> inputCounter;
  std::cout << "Now, please enter your data." << std::endl;
  for(int i = 0; i <inputCounter; i++)
  {
    float loopInput;
    std::cin >> loopInput;
    doubleVector.push_back(loopInput);
  }
  for (int i = 0; i < doubleVector.size(); i++)
  {
    report << doubleVector[i] << std::endl;
  }

}




// Calculates the minimum of two numbers (I didnt see how using only two parameters was useful)
double minCalc(float x, float y)
{
  if (x < y)
  {
    return y;
  }
  else 
  {
   return x; 
  }
}


// Calculates the maximum of two numbers (I didnt see how using only two parameters was useful)
double maxCalc(float x, float y)
{
  if(x > y)
  { 
    return x;
  }
  else
  {
    return y;
  }
}


// Calculates the running average of your data
double avgCalc()
{
  double avgNum = 0;

  for (int i = 0; i < doubleVector.size(); i++)
  {
    avgNum += doubleVector[i];
  }
  avgNum /= doubleVector.size();
  report << "Running average: " << avgNum << std::endl;
  std::cout <<  "Running average: " << avgNum << std::endl;
  return avgNum;
}


// Calculates the minimum by iterating over the entire vector
double minimumCalc()
{

  double min = doubleVector[0];

  for(int i = 0; i < doubleVector.size(); i++)
  {
    if(doubleVector[i] < min)
    {
      min = doubleVector[i];
    }
  }

  report << "Minimum: " << min << std::endl;
  std::cout <<  "Minimum: " << min << std::endl;
  return min; 
}



// Calculates the maximum of the data set
double maximumCalc()
{
  
  double max = doubleVector[0];

  for(int i = 0; i < doubleVector.size(); i++)
  {
    if(doubleVector[i] > max)
    {
      max = doubleVector[i];
    }
  }

  report << "Maximum: " << max << std::endl;
  std::cout <<  "Maximum: " << max << std::endl;
  return max; 
}






// Main function...every cpp program needs one.
int main()
{
  while(progCloser == 'n')
  {
    promptFunc();
    avgCalc();
    minimumCalc();
    maximumCalc();


    std::cout << "Would you like to close the program? ([y]es, [n]o)" << std::endl;
    std::cin  >> progCloser;
    if(progCloser != 'n')
    {
      std::cout << "Okay, your data will be stored in 'report.txt'. Thank you!" << std::endl;
    }
   
  }
}
