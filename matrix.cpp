public:
 bool find(int idx, int t, int b, vector<vector<int>> mx, int tgt) {
       if(t > b) {return false;}
       int md = t +(b-t) /2;
       if(mx[idx][md] == tgt) { return true;}     
       else if(mx[idx][md] < tgt) {
           return (idx, md+1, b,mx,tgt);
       } else {
           return (idx, t, md-1,mx,tgt);
       }
   }
    
    public:
   bool search(int t, int b, vector<vector<int>> mx, int C, int tgt) {
        if(t > b) {return false;}
       
       int md = t + (b-t) /2;
       if(mx[md][0] <= tgt && mx[md][C-1] >= tgt) {
           //find on md's row
         return find(md, 0, C-1, mx, tgt);
       } else if(mx[md+1][0] < tgt && mx[md+1][C-1] < tgt) {
           //is on lower section
         return  search(md+1, b, mx, C,tgt);
       } else if (mx[md+1][0] < tgt && mx[md+1][C-1] > tgt) {
           return find(md+1, 0, C-1,mx,tgt);
       } else {
      //upper section
         return  search(t, md-1, mx, C,tgt);
       }
   } 
    
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        if(matrix.empty()) {return false;}
         int R = matrix.size(); int C = matrix[0].size();

        return search(0, R-2, matrix, C, target);
    }

    int main() {
        vector<vector<int>> vc =
    }