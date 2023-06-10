 bool isvalid(int matrix[9][9],int row,int col,int c){
          for(int i=0;i<9;i++){
             if(matrix[row][i]==c) return false;
             if(matrix[i][col]==c) return false;
              
             if(matrix[3*(row/3)+i/3][3*(col/3)+i%3]==c) return false;
          }
        return true;
}

bool solver(int i,int j,int matrix[9][9]){
    if(i==9) return true;
    else if(j==9){
        return solver(i+1,0,matrix);
    }else if(matrix[i][j]!=0){
        return solver(i,j+1,matrix);
    }

        for(int val=1;val<=9;val++){
            if(isvalid(matrix,i,j,val)){
                matrix[i][j]=val;
                if(solver(i,j,matrix)) return true;
                matrix[i][j]=0;
            }
       }
       return false;
    }


bool isItSudoku(int matrix[9][9]) {
    // Write your code here.
    return solver(0,0,matrix);

}
