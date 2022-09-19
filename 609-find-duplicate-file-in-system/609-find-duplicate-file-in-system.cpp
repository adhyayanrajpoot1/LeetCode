class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
	unordered_map<string, vector<string>> Files;
	vector<vector<string> > ans;
	for(auto& path : paths) {
		stringstream ss(path);
		string s, dir, file, content;
		ss >> dir;
		while(ss >> s) {
			auto it = s.find('(');
			file = s.substr(0, it);
			content = s.substr(it);
			Files[content].push_back(dir + '/' + file);
		}
	}
	for(auto& content : Files) 
		if(size(content.second) > 1) 
			ans.push_back(content.second); 
	return ans;
}
};