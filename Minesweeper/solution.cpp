#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int> > readBoard(int width, int height)
{
  vector<vector<int> > board(height, vector<int>(width,0)); 
  for (int i=0; i<height; i++) {
    string row;
    cin >> row;
    for (int j=0; j<row.length(); j++) {
      if (row[j] == '*') {
	board[i][j] = 1;
      }
    }
  }
  return board;
}

int getValueOfCell(int x, int y, vector<vector<int> >board)
{
  int result = 0;
  if (x > 0) { 
    result += board[x-1][y];
  }
  if (y > 0) {
    result += board[x][y-1];
  }
  if (x > 0 && y > 0) {
    result += board[x-1][y-1];
  }
  if (x < board.size()-1) {
    result += board[x+1][y];
  }
  if (y < board[x].size()-1) {
    result += board[x][y+1];
  }
  if (x < board.size()-1 && y < board[x].size()-1) {
    result += board[x+1][y+1];
  }
  if (x > 0 && y < board[x].size()-1) {
    result += board[x-1][y+1];
  }
  if (x < board.size()-1 && y > 0) {
    result += board[x+1][y-1];
  }

  return result;
}

void showBoard(int width, int height, vector<vector<int> >board)
{
  for(int i = 0; i < height; ++i) {
    for(int j = 0; j < width; ++j) {
      if (board[i][j] == 1) {
	cout << "*";
      }
      else {
	cout << getValueOfCell(i, j, board);
      }
    }
    cout << endl;
  }
}

int main(int argc, char **argv)
{
  int width, height;
  int fieldNumber = 1;

  while (true) {
    cin >> height >> width;
  
    if (height == width && width == 0) { break; }

    vector<vector<int> > board = readBoard(width, height);

    cout << endl << "Field #" << fieldNumber << ":" << endl;
    showBoard(width, height, board);
    fieldNumber++;
  }

  return 0;
}
