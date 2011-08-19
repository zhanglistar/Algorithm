/** 
*  author: lee 
*/  
#include <iostream>  
#include <sstream>
#include <vector>  
#include <string>  
using namespace std;  
  
//vector  
void multiply(const vector<int>& a, const vector<int>& b, vector<int>& result); 
void factor(int n, vector<int> &re);

int main(void)  
{  
    //int i;  
    //string s;  
    //vector<int> a, b;  
    //cout << "please input two big integers: \n";  
    //cin >> s;  
    ////reserve places to avoid vector frequent expending  
    //a.reserve(s.size());  
    ////get the integer from string  
    //for (i = 0; i < s.size(); ++i)  
    //{  
        //a.push_back(s[i] - '0');  
    //}  

    ////vector<int>::iterator iter;
    ////for (iter = a.begin(); iter != a.end(); iter++) {
        ////cout << *iter << " ";
    ////}
    ////cout << endl;
  
    //cin >> s;  
    //b.reserve(s.size());  
    //for (i = 0; i < s.size(); ++i)  
    //{  
        //b.push_back(s[i] - '0');  
    //}  
    ////create the result vector and initialize it with 0  
    //vector<int> c(a.size() + b.size() - 1, 0);  
  
    //multiply(a, b, c);  
    ////print the result  
    //for (i = 0; i < c.size(); ++i)  
    //{  
        //cout << c[i];  
    //}  
    int n;
    cin >> n;
    vector<int> result(100, 0);
    result.reserve(100);

    factor(n, result);

    vector<int>::iterator iter;
    for (iter = result.begin(); iter != result.end(); iter++) {
        cout << *iter << " ";
    }

    cout << endl;  
    return 0;  
}  

void factor(int n, vector<int> &re)
{
    vector<int> temp(100, 0);
    temp.reserve(100);
    stringstream ss;
    string s;
    
    int i, j;
    re.push_back(1);
    for (i = 2; i <= n; i++) {
        ss << i;
        s = ss.str();
        for (j = 0; j < s.size(); j++) {
            temp.push_back(s[j]-'0');
        }
        multiply(re, temp, re);
    }
    
}
  
void multiply(const vector<int>& a, const vector<int>& b, vector<int>& result)  
{  
    int i, j, k;  
    int tmp;  
  
    for (i = 0; i < a.size(); ++i)   
    {  
        k = i;  
        for (j = 0; j < b.size(); ++j)  
        {  
            result[k++] += a[i] * b[j];  
        }  
    }  
      
    for (k = result.size() - 1;  k >= 0; --k)   
    {  
        if (result[k] > 9)   
        {  
            if (k != 0)  
            {  
                  
                result[k-1] += result[k] / 10;  
                result[k] %= 10;  
            }  
            else   
            {     
                tmp = result[k] / 10;  
                result[k] %=10;  
                result.insert(result.begin(), tmp);  
            }  
        }  
    }  
}  
