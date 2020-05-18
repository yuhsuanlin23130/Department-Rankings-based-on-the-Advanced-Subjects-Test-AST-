#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

int main()
{
  	ifstream inFile;
  	inFile.open("108-1.csv");
  
	int cnt=0;
	vector<string> originData[1874];
	string line;
	while( getline( inFile, line ,'\n')) //讀到換行字元 
    {	
	  istringstream templine(line); //string轉成stream
	  string data;
	  while( getline(templine,data,',')) // 讀到 , => 不同儲存格 
	    originData[cnt].push_back(data);
	  cnt++;
    }
    
    double finalForm[1874][11];
    string subject[11]={"國","英","數甲","數乙","歷","地","公","物","化","生","術"};
    
    for(int i=0;i<1874;i++)
	{
      for(int k=0; k<11;k++)
	  {
           bool has = false;
	       for(int j=0; j<originData[i].size(); j+=2)
    	    if(originData[i][j]==subject[k]){
    		   finalForm[i][k] = stof(originData[i][j+1]);
    		   has=true;
    		   break;
	       }
           if(has==false) finalForm[i][k] = 0;	  
	  }
	}

	inFile.close();
	
	ofstream outFile;
	outFile.open("108-2.csv");
	
	for(int i=0;i<1874;i++){
	  for(int j=0;j<11;j++)
	  	outFile<<finalForm[i][j]<<","; //","=>右邊的儲存格
	  outFile<<"\n";	
	}
	     
	
	outFile.close();
	return 0;
}
//excel:
// c1 = OFFSET($A$1,(ROW(1:1)-1)*11+COLUMN(A:A)-1,,) 
