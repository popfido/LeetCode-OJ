#include <iostream>

using namespace std;

class disjointSet{
private: 
	int* id;
	int count;
	int* size;

public:
	disjointSet(int N){
		count = N;
		id = new int[N];
		size = new int[N];
		for (int i=0;i<N;i++){
			id[i] = i;
			size[i] =1;
		}
	}

	~disjointSet(){delete id; delete size;}
	int disjointunit(){return count;}
	bool connected(int x, int y){return find(x) == find(y);}
	int find(int p){
		while(p != id[p]){
			id[p] = id[id[p]];
			p = id[p];
		}
		return p;
	}
	void ds_union(int p, int q){
		int i = find(p);
		int j = find(q);
		if (i == j) return;
		if(size[i] < size[j]) {id[i] = j; size[j] += size[i];}
		else {id[j]=i; size[i] += size[j];}
		count --;
	}
	int get_size(int p){return size[p];}
};

int main()
{
	int M,N;
	cin >> N >> M;
	while(M!=0 && N!=0){
		disjointSet* uf =  new disjointSet(N);
		while(M--){
			int x,y;
			cin >> x >> y;
			uf->ds_union(x,y);
		}
		cout << uf->get_size(1)-1 << endl;
		cin >> N >> M;
	}
	return 0;
}