#include<iostream>
#include<vector> 
using namespace std;

class Solution {
public:
    //注意找到后一定要检查找到的值是不是真的是超过一半的数
    bool CheckMoreHalf(vector<int> &numbers,int num)
    {
        int count=0;
        int len = numbers.size();
        for(int i=0;i<len;i++)
        {
         if(numbers[i]==num)
             count++;
        }
        if(count*2>len)//超过一半
        {
            return true;
        }
        return false;
    }
    
    
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int dir=0;
        int left = 0;
        if(numbers.size()==0)
            return 0;
        int right = numbers.size()-1;
        int midindex = (right+1)/2;
        while(dir!=midindex)
        {
          dir = PartSort(numbers,left,right);
            if(dir>midindex)
            {
                right=dir-1;
            }
            else
            {
                left=dir+1;
            }
        }
             if(CheckMoreHalf(numbers,numbers[dir]))
                return numbers[dir];
            else
                return 0;
    }
    
    
    int PartSort(vector<int> &numbers,int left,int right)
    {
        int tmp = numbers[right];
       while(left<right)
       {
           while(left<right&&tmp>=numbers[left])
           left++;
           numbers[right]=numbers[left];
           while(left<right&&tmp<=numbers[right])
           right--;
           numbers[left]=numbers[right];
       }
       numbers[left] =tmp;
        return left;
    }
    
};
    
    


int main()
{
	vector<int> v;
	Solution s;
	for(int i=0;i<10;i++)
	{
		v.push_back(i);
	}
		for(int i=0;i<10;i++)
	{
		v.push_back(1);
	}
	int mid=s.MoreThanHalfNum_Solution(	v);
	cout<<mid<<endl;
	return 0;
 } 
