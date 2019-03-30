/*
剑指offer 1-10题
@Author: wangli
@Date: 2019-03-30
*/

/* 
1. 二维数组中的查找
题目描述:
在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，
每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
*/

#include<vector>
using namespace std;

class Solution1{
public:
    bool Find(int target, vector<vector<int> > array){
        int i = 0;
        int j = array[0].size() - 1;
        while(i<array.size() && j>=0){
            if(array[i][j] < target){
                i++;
            }
            else if(array[i][j] > target){
                j--;
            }
            else{
                return true;
            }
        }
        return false;
    }
};

/*
2. 替换空格
题目描述:
请实现一个函数，将一个字符串中的每个空格替换成“%20”。
例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
*/

class Solution2{
public:
    void replaceSpace(char *str, int length){
        int orilength = 0;
        int countblank = 0;
        for(int i=0; str[i]!='\0'; i++){
            orilength++;
            if(str[i]==' '){
                countblank++;
            }
        }
        int len = orilength + 2 * countblank;
        char *p1 = str + orilength;
        char *p2 = str + len;
        while(p1<p2){
            if(*p1 == ' '){
                *p2-- = '0';
                *p2-- = '2';
                *p2-- = '%';
            }
            else{
                *p2-- = *p1;
            }
            --p1;
        }
    }
};

/*
3. 从尾到头打印链表
题目描述:
输入一个链表，按链表值从尾到头的顺序返回一个ArrayList。
*/

#include<stack>

struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL){
    }    
};

class Solution3{
public:
    vector<int> printListFromTailToHead(ListNode* head){
        vector<int> out;
        stack<int> arr;
        ListNode* p = head;
        while(p!=NULL){
            arr.push(p->val);
            p = p-> next;
        }
        int len = arr.size();
        for(int i=0; i<len; i++){
            out.push_back(arr.top());
            arr.pop();
        }
        return out;
    }
};

/*
5. 用两个栈实现队列
问题描述:
用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。
*/
class Solution5{
public:
    void push(int node){
        stack1.push(node);
    }

    int pop(){
        if(stack2.empty()){
            while(!stack1.empty()){
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        int out = stack2.top();
        stack2.pop();
        return out;
    }
private:
    stack<int> stack1;
    stack<int> stack2;
};

/*
6. 旋转数组的最小数字
题目描述:
把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。 
输入一个非减排序的数组的一个旋转，输出旋转数组的最小元素。 
例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。 
NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。
*/
class Solution6{
public:
    int minNumberInRotateArray(vector<int> rotateArray){
        int length = rotateArray.size();
        int fir = rotateArray[0];
        if(length == 1){
            return fir;
        }
        int left = 0;
        int right = length - 1;
        int mid = left;
        while(left < right){
            if((right - left) == 1){
                mid = right;
                break;
            }
            else{
                mid = (left + right) / 2;
                if(rotateArray[mid] < fir){
                    right = mid;
                }
                else{
                    left = mid;
                }
            }
        }
        return rotateArray[mid];
    }
};

/*
7. 斐波拉契数列
题目描述:
大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项（从0开始，第0项为0）。
n<=39
*/
class Solutioin7{
public:
    int Fibonacci(int n){
        int fir = 0;
        int sec = 1;
        int tmp = sec;
        if(n==0) return 0;
        if(n==1) return 1;
        for(int i=1; i<n; i++){
            tmp = sec;
            sec = fir + sec;
            fir = tmp;
        }
        return sec;
    }
};

/*
8. 跳台阶
题目描述:
一只青蛙一次可以跳上1级台阶，也可以跳上2级。
求该青蛙跳上一个n级的台阶总共有多少种跳法（先后次序不同算不同的结果）。
*/
class Solutioin8{
public:
    int Fibonacci(int n){
        int fir = 0;
        int sec = 1;
        int tmp = sec;
        if(n==0) return 0;
        if(n==1) return 1;
        for(int i=0; i<n; i++){
            tmp = sec;
            sec = fir + sec;
            fir = tmp;
        }
        return sec;
    }
};

/*
9. 变态跳台阶
题目描述:
一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。
求该青蛙跳上一个n级的台阶总共有多少种跳法。
*/
class Solution {
public:
    int jumpFloorII(int number) {
        int res = 1;
        for(int i=1; i<number; i++){
            res = res * 2;
        }
        return res;
    }
};
