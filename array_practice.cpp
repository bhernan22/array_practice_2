//Nicole Hipolito & Bianca Hernandez
//November 17, 2015
//Array Practice
//
//********************************************************************

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const int ROWS = 20;
const int COLS = 11;

void printArray(double ary[][COLS]);
void fillArray(ifstream& finA, double ary[][COLS]);
double averageArray(double ary[][COLS]);
double maxArray(double ary[][COLS]);
void sortArray(double aray[][COLS]);

int main()
{
    ifstream fin;
    double array[ROWS][COLS];
    
    fin.open("values.txt");
   
    if(fin.fail())
    {
        cout << "Error Opening Input File " << endl;
    }
    
    fillArray(fin,array);
    printArray(array);
    cout << left << setw(10) << "Average: " << averageArray(array) << endl;
    cout << setw(10) << "Max:" << maxArray(array) << endl;
    sortArray(array);
    cout << right;
    printArray(array);
    
    
    fin.close();
    return 0;
}// End of main()
//******************************************************************
void printArray(double ary[][COLS])
{
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            cout << setw(7) << ary[i][j];
        }
        cout << endl;
    }
}
//******************************************************************
void fillArray(ifstream& finA, double ary[][COLS])
{
    double num;
    cout << fixed << setprecision(2);
        for(int i = 0; i < ROWS; i++)
        {
            for(int j = 0; j < COLS; j++)
            {
                finA >> num;
                ary[i][j] = num;
            }
        }

}// End of fillArray()
//******************************************************************
double averageArray(double ary[][COLS])
{
    double sum = 0;
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            sum += ary[i][j];
        }
    }
    
    return sum / (ROWS * COLS);
}// End of averageArray
//******************************************************************
double maxArray(double ary[][COLS])
{
    double max = ary[0][0];
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS - 1; j++)
        {
            if(ary[i][j] > max)
            {
                max = ary[i][j];
            }
        }
    }
    return max;
}
//******************************************************************
void sortArray(double ary[][COLS])
{
    double temp;
    double max = ary[0][0];
    
    for(int x = 0; x < ROWS * COLS; x++)
    {
        for(int i = 0; i< ROWS; i++)
        {
            for(int j = 0; j< COLS; j++)
            {
                if(j == COLS -1)
                {
                    if(ary[i][j] > ary[i+1][0])
                    {
                        temp = ary[i][j];
                        ary[i][j] = ary[i+1][0];
                        ary[i+1][0] = temp;
                    }
                }
                
                else if(ary[i][j] > ary[i][j+1])
                {
                    temp = ary[i][j];
                    ary[i][j] = ary[i][j+1];
                    ary[i][j+1] = temp;
                }
            }
        }
      
    }
    return; 
}
