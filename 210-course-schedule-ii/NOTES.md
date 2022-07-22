// If the indegree becomes 0 of a course then again add them into DFS and start DFS call from that course .
for(int i = 0; i < numCourses; i++)
if(indegree[i] == 0) dfs(i);
//In the end return `result` if it contains all `numCourses` else return  []
if(size(result) == numCourses) return result;
return {};
}
};
Time Complexity : O(N + E) [O(E) to form adjacency list and O(N + E) for our DFS ].
Space Complexity : O(N + E), [Used by recursive stack and prerequisites as adjacency list graph in graph]
​
.......Continuation from previous posts..
Till now in the Dr.Cheems Doge ancient ruins arc phase 2, "Doggo,Dogenderous,Dogelina,Yomru and JThree all were trying to open the door of ancient ruin by their own ways .After failing several times they all took a pause while JThree started to circulate around the doors. After investigating the doors he found some clues based on an ancient story of four cardinal seasons. He referenced this theory as 'Celestial dogemon', JThree told others about it but rest felt a bit uneasy after listening the story . So to verify this, they called a chopper and a chopper picked them up and fleed towards the sky right above the ceiling they all verified theory and all were amazed by the view of Ancient laboratory..."
Phase 3 to be continued in the next post...........
​
Feel free to comment or upvote if you liked the post
Special thanks to @archit91 :)