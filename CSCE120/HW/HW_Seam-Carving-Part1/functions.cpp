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
    unsigned int pixel;

    for(i = 0; i < height; ++i)
    {
      for(j = 0; j < width; ++j)
      {
        //fileStream >> red >> green >> blue;
       
        if (!(fileStream >> red >> green >> blue)) 
        {
          // If not, throw an exception indicating too few values
          throw std::runtime_error("Invalid color value");
        }
        
        if((red < 256 && red >= 0)
        && (green < 256 && green >= 0) 
        && (blue < 256 && blue >= 0))
        {
          image[j][i].r = red;
          image[j][i].g = green;
          image[j][i].b = blue;
        
          //pixel++;
        }
        else
        {
          throw std::runtime_error("Invalid color value");
        }

      }
      
    }
    if (fileStream >> red) 
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
  std::ofstream outFile;
  std::string outFileType = "P3";
  int maxColor = 255;

  outFile.open(filename);

  if(!outFile.is_open())
  {
    throw std::runtime_error("Failed to open " + filename);
  }
  //outFile << "P3\n" << width << " " << height << "\n255\n";
  
  outFile << outFileType << '\n';
  outFile << width << " " << height << " " << '\n';
  outFile << maxColor << '\n';

  for(unsigned int i = 0; i < height; ++i)
  {
    for(unsigned int j = 0; j < width; ++j)
    {
      outFile << image[j][i].r << " ";
      outFile << image[j][i].g << " ";
      outFile << image[j][i].b << " ";
    }
    outFile << '\n';
    
  }
  

  outFile.close();
}

unsigned int energy(Pixel image[][MAX_HEIGHT], unsigned int x, unsigned int y, unsigned int width, unsigned int height) {
    int Rx, Ry, Gx, Gy, Bx, By;
    unsigned int delta_x, delta_y;

    if (x == 0) // Left border
    {
        Rx = image[(x + 1) % width][y].r - image[width - 1][y].r;
        Gx = image[(x + 1) % width][y].g - image[width - 1][y].g;
        Bx = image[(x + 1) % width][y].b - image[width - 1][y].b;
    }
    else if (x == width - 1) // Right border
    {
        Rx = image[0][y].r - image[x - 1][y].r;
        Gx = image[0][y].g - image[x - 1][y].g;
        Bx = image[0][y].b - image[x - 1][y].b;
    }
    else // Non-border case
    {
        Rx = image[x + 1][y].r - image[x - 1][y].r;
        Gx = image[x + 1][y].g - image[x - 1][y].g;
        Bx = image[x + 1][y].b - image[x - 1][y].b;
    }

    if (y == 0) // Top border
    {
        Ry = image[x][(y + 1) % height].r - image[x][height - 1].r;
        Gy = image[x][(y + 1) % height].g - image[x][height - 1].g;
        By = image[x][(y + 1) % height].b - image[x][height - 1].b;
    }
    else if (y == height - 1) // Bottom border
    {
        Ry = image[x][0].r - image[x][y - 1].r;
        Gy = image[x][0].g - image[x][y - 1].g;
        By = image[x][0].b - image[x][y - 1].b;
    }
    else // Non-border case
    {
        Ry = image[x][(y + 1) % height].r - image[x][(y - 1)].r;
        Gy = image[x][(y + 1) % height].g - image[x][(y - 1)].g;
        By = image[x][(y + 1) % height].b - image[x][(y - 1)].b;
    }

    delta_x = Rx * Rx + Gx * Gx + Bx * Bx;
    delta_y = Ry * Ry + Gy * Gy + By * By;

    return delta_x + delta_y;
}


// uncomment functions as you implement them (part 2)

unsigned int loadVerticalSeam(Pixel image[][MAX_HEIGHT], unsigned int start_col, unsigned int width, unsigned int height, unsigned int seam[]) 
{
    int totEnergy = 0;
    int current = start_col;
    int y = 0;

    for(y = 0; y < height - 1; ++y)
    {
        seam[y] = current;
        totEnergy += energy(image, current, y, width, height);

        int below = energy(image, current, y + 1, width, height);
        int belowRight = 999999999;
        int belowLeft = 999999999;

        if (current + 1 < width) {
            belowRight = energy(image, current + 1, y + 1, width, height);
        }

        if (current > 0) {
            belowLeft = energy(image, current - 1, y + 1, width, height);
        }

        int nextColumn = current;
        if (below < belowRight && below < belowLeft)
        {
            nextColumn = current;
        }
        else if (belowRight < below && belowRight < belowLeft)
        {
            nextColumn = current + 1;
        }
        else if (belowLeft < below && belowLeft < belowRight)
        {
            nextColumn = current - 1;
        }
        else
        {
            if (below <= belowLeft && below <= belowRight)
            {
                nextColumn = current;
            }
            else if (belowLeft <= below && belowLeft <= belowRight)
            {
                nextColumn = current - 1;
            }
            else if (belowRight <= below && belowRight <= belowLeft)
            {
                nextColumn = current + 1;
            }
        }

        //seam[y + 1] = nextColumn;
        //std::cout << seam[y];
        current = nextColumn;
    }

    totEnergy += energy(image, current, height - 1, width, height);

    return totEnergy;
}
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
