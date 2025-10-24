#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

#define N 500

bool isSafe(int labirinto[][N], int n, int m, int j, int h)
{
  if (j >= 0 && j < n && h >= 0 && h < m && labirinto[j][h] == 1)
    return true;
  return false;
}

bool backtracking(int labirinto[][N], int temp[][N], int n, int m, int j, int h)
{
  if (temp[3][3] == 1)
  {
    for (int i = 0; i < n; i++)
    {
      for (int k = 0; k < m; k++)
      {
        cout << temp[i][k] << " ";
      }
      cout << endl;
    }
  }

  if (isSafe(labirinto, n, m, j, h))
  {
    temp[j][h] = 1;
    backtracking(labirinto, temp, n, m, j + 1, h);
    backtracking(labirinto, temp, n, m, j, h + 1) ;
    temp[j][h] = 0;
  }
}

int main()
{
    int labirinto[N][N];
    int temp[N][N];
    int nTest = 0;
    int n, m;
    ifstream InFile;
    InFile.open("1.txt");
    InFile >> nTest;
    InFile >> n;
    InFile >> m;

    for (int y = 0; y < nTest; y++)
  {
    for (int i = 0; i < n; i++)
    {
      for (int k = 0; k < m; k++)
      {
        InFile >> labirinto[i][k];
      }
    }
    for (int i = 0; i < n; i++)
    {
      for (int k = 0; k < m; k++)
      {
        temp[i][k] = 0;
      }
    }
    backtracking(labirinto, temp, n,m,0,0);
}
    InFile.close();
}