class Solution {
public:
int eraseOverlapIntervals(vector<Interval>& intervals) {
auto comp = [](const Interval& i1, const Interval& i2){ return i1.start < i2.start; };
sort(intervals.begin(), intervals.end(), comp);
int res = 0, pre = 0;
for (int i = 1; i < intervals.size(); i++) {
if (intervals[i].start < intervals[pre].end) {
res++;
if (intervals[i].end < intervals[pre].end) pre = i;
}
else pre = i;
}
return res;
}
};