class Heap{
private:
	vector<ll>v;
public:
	Heap(){
		v.push_back(-1);
	}
	void heapify(ll idx){
		ll left=2*idx;
		ll right=left+1;
		ll min_idx=idx;
		ll last=v.size()-1;		
		if(left<=last and v[left]<v[idx]){
			min_idx=left;
		}
		if(right<=last and v[right]<v[min_idx]){
			min_idx=right;
		}
		if(min_idx!=idx){
			swap(v[min_idx], v[idx]);
			heapify(min_idx);
		}
	}
	void push(ll d){
		v.push_back(d);
		ll idx=v.size()-1;
		ll parent=idx/2;
		while(idx>1 and v[idx]<v[parent]){
			swap(v[idx], v[parent]);
			idx=parent;
			parent/=2;
		}
	}
	ll top(){
		return v[1];
	}
	ll size(){
		return v.size()-1;
	}
	bool empty(){
		return v.size()==1;
	}
	void pop(){
		ll last=v.size()-1;
		swap(v[1], v[last]);
		v.pop_back();
		heapify(1);
	}
};
