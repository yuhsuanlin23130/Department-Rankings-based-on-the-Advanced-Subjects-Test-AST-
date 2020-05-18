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
	while( getline( inFile, line ,'\n')) //Ū�촫��r�� 
    {	
	  istringstream templine(line); //string�নstream
	  string data;
	  while( getline(templine,data,',')) // Ū�� , => ���P�x�s�� 
	    originData[cnt].push_back(data);
	  cnt++;
    }
    
    double finalForm[1874][11];
    string subject[11]={"��","�^","�ƥ�","�ƤA","��","�a","��","��","��","��","�N"};
    
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
	  	outFile<<finalForm[i][j]<<","; //","=>�k�䪺�x�s��
	  outFile<<"\n";	
	}
	     
	
	outFile.close();
	return 0;
}
//excel:
// c1 = OFFSET($A$1,(ROW(1:1)-1)*11+COLUMN(A:A)-1,,) 
