class Solution {
public:
    vector<vector<int> > insert(vector<vector<int> > &A, vector<int> &a) {
		vector<vector<int> > v;
		auto i=A.begin();
		for(; i!=A.end() && a[0]>(*i)[1]; v.push_back(*i++));
		for(; i!=A.end() && a[1]>=(*i)[0]; ++i)
			a={min(a[0],(*i)[0]), max(a[1],(*i)[1])};
		v.push_back(a);
		v.insert(v.end(),i,A.end());
		return v;
    }
};
