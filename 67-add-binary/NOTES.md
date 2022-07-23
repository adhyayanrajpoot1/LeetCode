Adding 2 binary bits :
0 + 0 = 0
1 + 0 = 1
0 + 1 = 1
1 + 1 = 10
​
string addBinary(string a, string b) {
int i = a.length()-1;
int j = b.length()-1;
string ans;
int carry = 0;
while(i>=0 || j>=0 || carry){
if(i>=0){
carry += a[i] - '0';
i--;
}
if(j>=0){
carry += b[j] - '0';
j--;
}
ans += (carry%2 + '0');
carry = carry/2;
}
reverse(ans.begin(),ans.end());
return ans;
}
Important point to note: (Reference - here)
​
a = a + "xy" is O(N) while a += "xy" is O(1) (amortized).
​
a = a + "xy" creates a copy of a, appends "xy" and then assigns it back to a.
​
a += "xy" just appends "xy" to a.
​
Therefore the time complexity of this approach is O(n).