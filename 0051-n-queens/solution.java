class Solution {
    public List<List<String>> solveNQueens(int n) {
        List<List<String>> ans = new ArrayList<>();
        char[][] board =new char[n][n];
        for(int i=0;i<n;i++){
            Arrays.fill(board[i],'.');
        }
        solve(0,board,ans,n);
        return ans;
    }
    public void solve(int row, char[][] board,List<List<String>> ans,int n){

        if(row==n){
            List<String> temp =new ArrayList<>();
            for(int i=0; i<n; i++){
            temp.add(new String(board[i]));}
            ans.add(temp);
            return;
        }

        for(int col=0; col<n;col++){
        if(isSafe(board,row,col,n)){
            board[row][col]='Q';
            solve(row+1,board,ans,n);
            board[row][col]='.';
        }
     }

    }
   private boolean isSafe(char[][] board, int row, int col, int n){

        for(int j = 0; j < n; j++){
            if(board[row][j] == 'Q') return false;
        }

        for(int i = 0; i < n; i++){
            if(board[i][col] == 'Q') return false;
        }

        int i = row, j = col;
        while(i >= 0 && j >= 0){
            if(board[i][j] == 'Q') return false;
            i--; j--;
        }

        i = row; j = col;
        while(i >= 0 && j < n){
            if(board[i][j] == 'Q') return false;
            i--; j++;
        }

        return true;
    }
}
