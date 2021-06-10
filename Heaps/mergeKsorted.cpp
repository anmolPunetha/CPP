#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef pair<int, pair<int, int>> node;   //value, array index, element index
vector<int> mergeKsortedArrays(vector<vector<int>> v){
	vector<int> result;
	priority_queue<node, vector<node>, greater<node>> pq;

	//insert 0th elements of all
	for(int i=0;i<v.size();i++){
		pq.push({v[i][0], {i, 0}});
	}

	//remove one by one and add new
	while(!pq.empty()){
		node current = pq.top();   //gives the min ele so far
		pq.pop();
		int element = current.first;
		int x = current.second.first;
		int y = current.second.second;

		result.push_back(element);

		if(y+1<v[x].size()){
			pq.push({v[x][y+1], {x,y+1}});
		}
	}
	return result;
} 
int main() {
	int k, n;
	cin>>k>>n;
	vector<vector<int>> v;
	for(int i=0;i<k;i++){
		vector <int> row;
		for(int j=0;j<n;j++){
			int num;
			cin>>num;
			row.push_back(num);
		}
		v.push_back(row);
	}
	vector<int> result = mergeKsortedArrays(v);

	for(auto x:result){
		cout<<x<<" ";
	}
	return 0;
}
