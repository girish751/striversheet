class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
         int left[8]={-1,-1,0,1,1,1,0,-1};
            int right[8]={0,1,1,1,0,-1,-1,-1};
        int n=board.size();int m=board[0].size();
        queue<pair<int,int>>q;
        if(board[click[0]][click[1]]=='M'){
            board[click[0]][click[1]]='X';
            return board;
        }
        if(board[click[0]][click[1]]=='E'){q.push(make_pair(click[0],click[1]));
        board[click[0]][click[1]]='B';}
        while(!q.empty()){
            
            pair<int,int>temp=q.front();q.pop();
            int count=0;
           
            for(int i=0;i<8;i++){
                int row=temp.first+left[i];
                int col=temp.second+right[i];
                
                if(row>=0&&row<n&&col>=0&&col<m){
                    if(board[row][col]=='M')count++;
                }
            }
            if(count==0){
                  for(int i=0;i<8;i++){
                int row=temp.first+left[i];
                int col=temp.second+right[i];
                
                if(row>=0&&row<n&&col>=0&&col<m&&board[row][col]=='E'){
                    board[row][col]='B';    
                    q.push(make_pair(row,col));
                }
            }
                
            }
            else board[temp.first][temp.second]=count+'0';
            
            
            
        }
        return board;
    }
};