We count consequitive zeros (i - j + 1).
​
For each zero, we add (i - j + 1) subarrays:
​
0 -> +1
00 -> +2 (_0 and 00)
000 -> +3 (__0, _00, and 000)
and so on...