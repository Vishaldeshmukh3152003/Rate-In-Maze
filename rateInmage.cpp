#include<iostream>
#include<vector>
using namespace std;
bool isSafe(int newx,int newy,int row,int col ,int maze[][3],vector<vector<bool>>&visited)
{
 
 	if(
		(newx >=0 && newx <row) &&
		(newy >=0 && newy < col) &&
		maze[newx][newy] == 1 &&
		visited[newx][newy] == false
		) {
		return true;
		}
	else {
		return false;
	}
}
void printAllWays(int maze[][3],int srow,int scol,int row,int col,string& output,vector<vector<bool>>&visited)
{
    
  if(srow==row-1&&scol==col-1)
  {
    cout<<output<<endl;
    return;
  }

  //up
  int newx=srow-1;
  int newy=scol;
  if(isSafe(newx,newy,row,col,maze,visited))
  {
    visited[newx][newy]=true;
    output.push_back('U');
    printAllWays(maze,newx,newy,row,col,output,visited);
    output.pop_back();
    visited[newx][newy]=false;
  }

  //down
  newx=srow+1;
  newy=scol;
    if(isSafe(newx,newy,row,col,maze,visited))
  {
    visited[newx][newy]=true;
    output.push_back('D');
    printAllWays(maze,newx,newy,row,col,output,visited);
    output.pop_back();
    visited[newx][newy]=false;
  }
  //left
  newx=srow;
  newy=scol-1;  
    if(isSafe(newx,newy,row,col,maze,visited))
  {
    visited[newx][newy]=true;
    output.push_back('L');
    printAllWays(maze,newx,newy,row,col,output,visited);
    output.pop_back();
    visited[newx][newy]=false;
  }
  //right
  newx=srow;
  newy=scol+1;  
    if(isSafe(newx,newy,row,col,maze,visited))
  {
    visited[newx][newy]=true;
    output.push_back('R');
    printAllWays(maze,newx,newy,row,col,output,visited);
    output.pop_back();
    visited[newx][newy]=false;
  }


}
int main()
{
    int maze[3][3] = {
	{1,1,0},
	{1,1,1},
	{0,0,1}
	};
	int row = 3;
	int col = 3;

	int srcx = 0;
	int srcy = 0;
	string output = "";
vector<vector<bool > > visited(row, vector<bool>(col, false));
	
    if(maze[0][0]==0)
    {
        cout<<"can't find the routs"<<endl;
    }
    else{
        	visited[srcx][srcy] = true;
   printAllWays(maze,srcx,srcy,row,col,output,visited);
    }
}