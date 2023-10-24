#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <random>


using namespace std;


vector<int> patternFinderFunction(vector<int> aliveCellsVector)
{

    int i,c,p,checkAgain,t,tempI;
    bool searchBool = false;
    vector<int> patternFound;

    i = 1;
    p = 0;
    tempI = i;

    for(i; i<aliveCellsVector.size(); i++)
    {
        searchBool = false;
        checkAgain = 1;
        tempI = i;

        for(c=i-1; c>=1; c--)
        {
            if(searchBool)
            {
                i = tempI;
                break;
            }

            while(aliveCellsVector[c]==aliveCellsVector[i])
            {
                p++;
                searchBool = true;

                if(i-c-p<=0)
                {
                    if(checkAgain<2)
                    {
                        checkAgain++;
                        t = c;
                        c = i;
                        tempI = i;
                        i = 2*i - t;
                        p = 0;
                    }
                    else
                    {
                        p = 0;
                        for (p; i - c - p > 0; p++)
                        {
                            patternFound.push_back(aliveCellsVector[i + p]);
                        }
                        return patternFound;
                    }
                }

                //pattern with period of above 8 are not possible within a 30x30 grid, hence the i-c>8
                if(aliveCellsVector[c+p]!=aliveCellsVector[i+p] || i-c>8)
                {
                    p = 0;
                    i = tempI;
                    break;
                }
            }
        }
    }

    return patternFound;
}

int main() {
    srand(time(0));


    vector<int> aliveCellsVector;
    vector<int> mainPattern;

    int randomNumber;

    aliveCellsVector.push_back(6);
    aliveCellsVector.push_back(8);
    aliveCellsVector.push_back(9);
    aliveCellsVector.push_back(7);
    aliveCellsVector.push_back(8);
    aliveCellsVector.push_back(9);
    aliveCellsVector.push_back(4);
    aliveCellsVector.push_back(8);
    aliveCellsVector.push_back(9);
    aliveCellsVector.push_back(7);
    aliveCellsVector.push_back(6);



        mainPattern = patternFinderFunction(aliveCellsVector);

    for(int i=0; i<mainPattern.size(); i++)
    {
        cout<<mainPattern[i]<<" ";
    }


    return 0;
}
