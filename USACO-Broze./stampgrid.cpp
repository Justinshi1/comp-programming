using namespace std;
#include <iostream>

#include <cstring>
#include<algorithm>
extern "C" void rotate90Clockwise(int n, int** a1);
extern "C" int fillCanvas(int** canvas, int** blankCanvas, int** stamp, int stamDimentions, int canvasDimentions);
extern "C" bool stampedCanvas(int** canvas, int** stamp, int stamDimentions, int canvasDimention, int x, int y);
extern "C" int checkStamp(int** canvas, int** stamp, int stamDimentions, int canvasDimentions, int** resultStamp, int x, int y);
extern "C" void  fillTempDot(int x, int y, int** blankCanvas, int*** useStamp, int stampDimention, int canvasDimention);
const int STAR = 2;
const int DOT = 1;
const int TEMP_DOT = 3;
int main() {
    //first take input to number of test cases
    int testCases = 0;
    cin >> testCases;
    string* output = new string [testCases];
    for (int t = 0; t < testCases; t++) {
        int canvasDimentions = 0;
        cin >> canvasDimentions;
        int** canvas = new int* [canvasDimentions];
        for (int i = 0; i < canvasDimentions; i++) {
            canvas[i] = new int[canvasDimentions];
        }
        char tem = ' ';
        for (int i = 0; i < canvasDimentions; i++) {
            for (int j = 0; j < canvasDimentions; j++) {
                cin >> tem;
                if (tem == '*') {
                    canvas[i][j] = STAR;
                }
                else {
                    canvas[i][j] = DOT;
                }
            }
        }
        int stamDimentions = 0;
        cin >> stamDimentions;
        int** stamp = new int* [stamDimentions];
        for (int i = 0; i < stamDimentions; i++) {
            stamp[i] = new int[stamDimentions];
        }
        for (int i = 0; i < stamDimentions; i++) {
            for (int j = 0; j < stamDimentions; j++) {
                cin >> tem;
                if (tem == '*') {
                    stamp[i][j] = STAR;

                }
                else {
                    stamp[i][j] = DOT;
                }
            }
        }
        /*
        cout<<canvasDimentions<<endl;
        for(int i = 0; i<canvasDimentions; i++){
            for(int j = 0; j<canvasDimentions; j++){
                cout<<canvas[i][j]<<" ";
            }
            cout<<endl;
        } */



        //first generate blank canvas with all dots
        int** blankCanvas = new int* [canvasDimentions];
        for (int i = 0; i < canvasDimentions; i++) {
            blankCanvas[i] = new int[canvasDimentions];
        }
        for (int i = 0; i < canvasDimentions; i++) {
            for (int j = 0; j < canvasDimentions; j++) {
                blankCanvas[i][j] = DOT;
            }
        }
        //call fill canvas 
        //cout << "hi" << endl;
        if (fillCanvas(canvas, blankCanvas, stamp, stamDimentions, canvasDimentions) == 1) {
            //cout << "YES" << endl;
            output[t] = "YES";
        }
        else {
           // cout << "NO" << endl;
            output[t] = "NO";
        }
        for (int i = 0; i < canvasDimentions; i++) {
            delete[] canvas[i];
        }
        delete[] canvas;
        for (int i = 0; i < stamDimentions; i++) {
            delete[] stamp[i];
        }
        delete[] stamp;
        for (int i = 0; i < canvasDimentions; i++) {
            delete[] blankCanvas[i];
        }
        delete[] blankCanvas;
    }
    for (int i = 0; i < testCases; i++) {
        cout << output[i] << endl;
    }

    return 0;

}
void rotate90Clockwise(int n, int** a1)
{
    for (int i = 0; i < n / 2; i++)
    {
        for (int j = i; j < n - i - 1; j++)
        {
            int temp = a1[i][j];
            a1[i][j] = a1[n - 1 - j][i];
            a1[n - 1 - j][i] = a1[n - 1 - i][n - 1 - j];
            a1[n - 1 - i][n - 1 - j] = a1[j][n - 1 - i];
            a1[j][n - 1 - i] = temp;
        }
    }
}
int checkStamp(int** canvas, int** stamp, int stamDimentions, int canvasDimentions, int** resultStamp, int x, int y) {
    int ret = 2;
    //check if x y is a star then need to find stamp that starts with star
    if (canvas[x][y] == STAR && stamp[0][0] != STAR) {
        return 0;
    }
    //ret 1 = stamp can be used ret = 0 is stamp cannot be used ret = 2 perfect match 
    int endX = x + stamDimentions - 1;
    int endY = y + stamDimentions - 1;
    if (endX >= canvasDimentions || endY >= canvasDimentions) {
        return 0;
    }
    int row = 0;
    int col = 0;
    for (int i = x, row = 0; i <= endX; i++, row++) {
        for (int j = y, col = 0; j <= endY; j++, col++) {
            if (stamp[row][col] == STAR && canvas[i][j] == DOT) {
                return 0;
            }
            else if (stamp[row][col] == DOT && (canvas[i][j] == STAR || canvas[i][j] == TEMP_DOT)) {
                resultStamp[row][col] = TEMP_DOT;
                ret = 1;
            }
            else {
                resultStamp[row][col] = stamp[row][col];
            }
        }
    }
    return ret;
}
int fillCanvas(int** canvas, int** blankCanvas, int** stamp, int stamDimentions, int canvasDimentions) {
    int row = 0;
    int ret = 1;
    int col = 0;
    int** useStamp[8];   
    useStamp[0] = stamp;
    for (int i = 1; i <= 4; i++) {
        useStamp[i] = new int* [stamDimentions];
        for (int j = 0; j < stamDimentions; j++) {
            useStamp[i][j] = new int[stamDimentions];
        }
        // copy stamp to stamp1 with 
        if (i != 4) {
            for (int r = 0; r < stamDimentions; r++) {
                for (int c = 0; c < stamDimentions; c++) {
                    useStamp[i][r][c] = useStamp[i - 1][r][c];
                }
            }
            if (stamDimentions != 1) {
                rotate90Clockwise(stamDimentions, useStamp[i]);
            }
        }
    }
    int stampIdx = 0;
    while (row < canvasDimentions && col < canvasDimentions) {

        int retV[4];

        for (int i = 0; i < 4; i++)
            retV[i] = checkStamp(canvas, useStamp[i], stamDimentions, canvasDimentions,  useStamp[i+4], row, col);
        
        int chosen1  = 0;
        int chosen2 = 0;
        for (int i = 0; i < 4; i++) {
            if (retV[i] == 2) {
                chosen1 = i;
                break;
            }
            if (retV[i] == 1) {
                chosen2 = i;
            }
        }
        if (chosen1 != 0 || chosen2 != 0) { //exact match or temp match
        if (chosen1 != 0)
             stampedCanvas(blankCanvas, useStamp[chosen1+4], stamDimentions, canvasDimentions, row, col);
        else
            stampedCanvas(blankCanvas, useStamp[chosen2 + 4], stamDimentions, canvasDimentions, row, col);
            col = col + 1;
            if (col == canvasDimentions) {
                col = 0;
                row = row + 1;
            }
            stampIdx = 0; // reset stamp index and start from next position    
        }
        else { //no match try next stamp  i
            stampIdx++;
            //if all stamps have been tried and no match then return 0
            if (stampIdx == 4) {
                stampIdx = 0;
                col = col + 1;
                if (col == canvasDimentions) {
                    col = 0;
                    row = row + 1;

                }
            }
        }
    }
    //fill tem dots with stars
    //check results 

    for (int i = 0; i < canvasDimentions; i++) {
        for (int j = 0; j < canvasDimentions; j++) {
            if (blankCanvas[i][j] == TEMP_DOT) {
                fillTempDot(i, j, blankCanvas, useStamp, stamDimentions, canvasDimentions);
            }
            if (blankCanvas[i][j] != canvas[i][j]) {
                ret = 0;
                break;
            }
        }
    }
    //delete used stamps
    for (int i = 1; i < 5; i++) {
        for (int j = 1; j < stamDimentions; j++) {
            delete[] useStamp[i][j];
        }
        delete[] useStamp[i];
    }
    return ret;
}
bool stampedCanvas(int** canvas, int** stamp, int stamDimentions, int canvasDimention, int x, int y) {
    //calculate the end location of the canvas
    int endX = x + stamDimentions-1;
    int endY = y + stamDimentions-1;
    for (int i = x, row = 0; i <= endX; i++, row++) {
        for (int j = y,  col = 0; j <= endY; j++, col++) {
            //copy stamp to canvas
            canvas[i][j] = stamp[row][col];
        }
    }
    return true;
}
void  fillTempDot(int x, int y, int** blankCanvas, int*** useStamp, int stampDimention, int canvasDimention) {
    int startX, startY, endX, endY;

    for (int r =0; r<stampDimention; r++) {
        for (int w =0; w<stampDimention; w++) {
            startX = x -r;
            startY = y - w;
            endX = startX + stampDimention - 1;
                endY = startY + stampDimention - 1;
            if (startX<0 || startY<0 || endX>= canvasDimention || endY >= canvasDimention) {
                continue;
            }
            for (int idx = 0; idx < 4; idx++) {
                if (useStamp[idx][r][w] == STAR) {
                    blankCanvas[x][y] = STAR;
                }
            }
        }
    }
     
    }
