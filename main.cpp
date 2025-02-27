#include<iostream>
#include<vector>
using namespace std;

vector<int> multiplyBigNumber(const vector<int>& num1, const vector<int>& num2) {
    vector<int> result(num1.size() + num2.size()+1, 0);
    int carry = 0;
    for (int i = 0; i<num1.size(); i++) {
        int carry = 0;
        for (int j = 0 ; j<num2.size(); j++) {
            int sum = num1[i] * num2[j] + result[i + j] + carry;
            result[i+j]=sum%10;
            carry = sum/10;
        }
        if (carry) {
            if(carry < 10){
                result[i + num2.size()] += carry;
            }else if(carry >=10){
                result[i+num2.size()]+=carry%10;
                result[i+num2.size()+1]+=carry/10;
            }
        }
    }
    while (result.size() > 1 && result.back() == 0) {
            result.pop_back();
        }
    return result;
}

vector<int> addBigNumber(const vector<int>& num1,const vector<int>& num2){
    vector<int> result;
    int carry = 0; //进位
    int size = max(num1.size(),num2.size());
    for(int i = 0; i<size || carry ;i++){
        int sum = carry;
        if (i < num1.size()) sum += num1[i];
        if (i < num2.size()) sum += num2[i];
        carry = sum/10;
        result.push_back(sum%10);
    }
    return result;
}

int main(){
    int n;
    cin>>n;
    vector<int> factorial1(1, 1);
    vector<int> sum(1, 0);
    for (int i = 1; i<=n; i++) {
        vector<int> temp(1, i);
        factorial1 = multiplyBigNumber(factorial1,temp);
        sum = addBigNumber(sum, factorial1);
    }
    for (int i = sum.size() - 1; i >= 0; --i) {
            cout << sum[i];
        }
    return 0;
}
