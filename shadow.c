//#include<stdio.h>
//#include <stdlib.h>
//#include <string.h>
#include <Foundation/Foundation.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main(int argc, const char * argv[]) {
    int W; // width of the building.
    int H; // height of the building.
    scanf("%d%d", &W, &H);
    int N; // maximum number of turns before game over.
    scanf("%d", &N);
    int X0;
    int Y0;
    scanf("%d%d", &X0, &Y0);
    int x = X0; 
    int y = Y0;
    int min_x = 0;
    int max_x = W-1;
    int min_y = 0;
    int max_y = H-1;
    // game loop
    while (1) {
        char bombDir[4]; // the direction of the bombs from batman's current location (U, UR, R, DR, D, DL, L or UL)
        scanf("%s", bombDir);
        // Write an action using printf(). DON'T FORGET THE TRAILING NEWLINE \n
        // To debug: fprintf(stderr, [@"Debug messages\n" UTF8String]);

        for(int i=0;i<strlen(bombDir);i++){
            
            if(bombDir[i]=='D'){ // the target area is below
                min_y=y+1;   // lower y should be updated
            }
            if(bombDir[i]=='U'){ // the target area is above
                max_y=y-1;  // higher y should be updated
            }
            if(bombDir[i]=='R'){ // the target area is on right
                min_x=x+1; // lower x should be updated
            }
            if(bombDir[i]=='L'){ // the target area is on left 
                max_x=x-1; // higher x should be updated
            }
        }
        x = min_x + (max_x-min_x)/2;
        y = min_y + (max_y-min_y)/2;
        printf("%i %i\n", x, y);
        
        // the location of the next window Batman should jump to.
        //printf([@"0 0\n" UTF8String]);
    }
}