TreeNode* node = q.front().first;
q.pop(); // pop from the queue
// remember the formula we discussed
//width = (maximum index at level) - (minimum index at level) + 1
if(i == 0)
mn = curr_index; // minimum index at level
if(i == size - 1)
mx = curr_index; //maximum index at level
// push left and right for further calculation
if(node -> left != NULL) //2   * i
q.push({node -> left, 2LL * curr_index});
if(node -> right != NULL) //2   * i  + 1
q.push({node -> right, 2LL * curr_index + 1});
}
ans = max(ans, mx - mn + 1); // update our answer
}
return ans; // finally return our answer
}
};