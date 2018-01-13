/* Copyright (C) 2018 Neal Nicdao
 * 
 * Licensed under the Holy Open Software License of the Computer Gods V1
 * 
 * This software comes with ABSOLUTELY NO WARANTEEEEE. By plagiarizing the work,
 * you agree to the HIGHEST POSSIBLE PUNISHMENT from the the might of the
 * COMPUTER GODS through rolling the DICE.
 */

#include <cstdio>
#include <bitset>
#include <algorithm>
#include <cmath>

char* board;
int x, y, a, e, f, i, j, w, h, g, t;
int maxSizeX, maxSizeY, maxSize;
int repeats;

int main() {

  // Input
  printf("--SANITARY AXE PROGRAM--\nEnter Odd Number: ");
  scanf("%i", &maxSize);
  printf("Repetition: ");
  scanf("%i", &repeats);

  // Calculate and allocate the size for the largest possible axe
  maxSize = std::abs(maxSize) / 2;
  maxSizeY = 10 + std::max(0, maxSize - 2) + std::max(0, maxSize - 9);
  maxSizeX = std::max(2 + 2 * maxSize, 4);
  // Width x Height + space for indents and string terminator
  board = new char[maxSizeX * maxSizeY + maxSizeY + 1];

  // Repeat all operations for a better measurement of time
  for (j = 0; j < repeats; j ++) {
    // Draw all the axes from size 1 to specified size
    for (t = 1; t < maxSize + 2; t ++) {
      // Width and height for this specific axe
      w = std::max(2 + 2 * t, 4);
      h = 10 + std::max(0, t - 2) + std::max(0, t - 9);
      // Set y to zero when drawing a new axe
      y = 0;
      // Loop through the entire area like pixels
      for (i = 0; i < w * h; i ++) {
        // Calculate x
        x = i % w;
        // e and f is the y of the top and bottom of the axe handle
        e = std::max(0, t - 2);
        f = std::floor(std::abs(x * 2 - w + 1) / 2);
        // Set current pixel to a # or space, using axe calculation mess
        board[y * w + x + y] = ((e <= y && y <= e + 10
                                && (x == w / 2 || x == w / 2 - 1))
                                || (f >= 1 && std::abs(e + 1 - y) <= f - 1))
                                  ? '#' : ' ';
        // If x is on the edge of the image (last)
        if (x == w - 1) {
          // Either indent or add a string terminator
          board[y * w + x + y + 1] = (y == h - 1) ? '\0' : '\n';
          // Then increment y
          y ++;
        }
      }
      // Print the entire board once done
      printf("%s\n\n", board);
    }
    // Next axe is drawn but at a larger size
  }
  return 0;
}
