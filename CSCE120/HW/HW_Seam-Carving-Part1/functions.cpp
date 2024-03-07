#include <iostream>
#include <sstream>
#include <fstream>
#include <cmath>
#include "functions.h"

using std::cout, std::endl, std::string;

void initializeImage(Pixel image[][MAX_HEIGHT]) 
{
  // iterate through columns
  for (unsigned int col = 0; col < MAX_WIDTH; col++) 
  {
    // iterate through rows
    for (unsigned int row = 0; row < MAX_HEIGHT; row++) 
    {
      // initialize pixel
      image[col][row] = {0, 0, 0};
    }
  }
}

void loadImage(string filename, Pixel image[][MAX_HEIGHT], unsigned int& width, unsigned int& height) 
{
  // TODO: implement (part 1)
  
  //Opening File
  std::ifstream fileStream;
  std::string fileType;
  int red;
  int green;
  int blue; 
  int maxColor;

  fileStream.open(filename);

  if(!fileStream.is_open())
  {
    throw std::runtime_error("Failed to open " + filename);
  }
  //Validate Type
  fileStream >> fileType;
 
  if((fileType == "P3") || (fileType == "p3"))
  {
    //Run through file
    fileStream >> width >> height >> maxColor;

    if((width <= 0 || height <= 0))
    {
      throw std::runtime_error("Invalid dimensions");
    }

    if((width > MAX_WIDTH) || (height > MAX_HEIGHT))
    {
      throw std::runtime_error("Invalid dimensions");
    }

    unsigned int i;
    unsigned int j;

    for(i = 0; i < height; ++i)
    {
      for(j = 0; j < width; ++j)
      {
        fileStream >> red >> green >> blue;
        /*
        if (!(fileStream >> red >> green >> blue)) 
        {
          // If not, throw an exception indicating too few values
          throw std::runtime_error("Invalid color value");
        }
        */
        if((red < 256 && red > 0)
        && (green < 256 && green > 0) 
        && (blue < 256 && blue > 0))
        {
          image[j][i].r = red;
          image[j][i].g = green;
          image[j][i].b = blue;
        
        }
        else
        {
          throw std::runtime_error("Invalid color value");
        }

      }
      
    }
    
    if(((j * i) < (width * height)) && ((j * i) % 3 != 0))
    {
      throw std::runtime_error("Invalid color value");
    }
    else if(((j * i) > (MAX_WIDTH * MAX_HEIGHT)) && ((j * i) % 3 != 0))
    {
      throw std::runtime_error("Too many values");
    }
    
  }
  else
  {
    throw std::runtime_error("Invalid type " + fileType);
  }

  fileStream.close();

}

void outputImage(string filename, Pixel image[][MAX_HEIGHT], unsigned int width, unsigned int height) 
{
  // TODO: implement (part 1)
}

unsigned int energy(Pixel image[][MAX_HEIGHT], unsigned int x, unsigned int y, unsigned int width, unsigned int height) 
{
  // TODO: implement (part 1)
  return 0;
}

// uncomment functions as you implement them (part 2)

// unsigned int loadVerticalSeam(Pixel image[][MAX_HEIGHT], unsigned int start_col, unsigned int width, unsigned int height, unsigned int seam[]) {
//   // TODO: implement (part 2)
//   return 0;
// }

// unsigned int loadHorizontalSeam(Pixel image[][MAX_HEIGHT], unsigned int start_row, unsigned int width, unsigned int height, unsigned int seam[]) {
//   // TODO: implement (part 2)
//   return 0;
// }

// void findMinVerticalSeam(Pixel image[][MAX_HEIGHT], unsigned int width, unsigned int height, unsigned int seam[]) {
//   // TODO: implement (part 2)
// }

// void findMinHorizontalSeam(Pixel image[][MAX_HEIGHT], unsigned int width, unsigned int height, unsigned int seam[]) {
//   // TODO: implement (part 2)
// }

// void removeVerticalSeam(Pixel image[][MAX_HEIGHT], unsigned int& width, unsigned int height, unsigned int verticalSeam[]) {
//   // TODO: implement (part 2)
// }

// void removeHorizontalSeam(Pixel image[][MAX_HEIGHT], unsigned int width, unsigned int& height, unsigned int horizontalSeam[]) {
//   // TODO: implement (part 2)
// }
