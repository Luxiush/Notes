

typedef int Key_type

Node{
public:
	int n;			//当前关键字数
	Key_type* key;	//关键字数组（or链表）首地址
	Node** 	child;	//子节点数组（or链表）首地址
	bool leaf;	//是否为叶节点
	
	Node(){
		n = 0;
		key = NULL;
		child = NULL;
		leaf = true;
	}
	
	~Node(){
		Free();
	}
	
	/*
	为key和child分配空间, (或者为每个节点创建一个文件？？)
	输入：t, 最小度数
	*/
	bool Allocate(int t){
		if(key == NULL){
			key = new Key_type[2*t-1];
		}
		if(!leaf && child == NULL){
			child = new Node[2*t];
		}
	}
	
	Free(){
		if(key != NULL){
			delete [] key;
			key = NULL;
		}
		if(child != NULL){
			delete [] child;
			child = NULL;
		}
	}
	
private:

}


B_Tree{
public:
	int t;		//最小度数
	Node* root;	//根节点指针
	
	B_Tree(int t){
		this->t = t;
		Create();
	}
	
	~B_Tree(){
		////////
		
	}

	/*创建一个空的根节点*/
	bool Create(){
		root = new Node;
		root->Allocate();
	}
	
	
	/*将关键字key插入树中*/
	bool Insert(key){
		if(root->n == 2*t-1){
			Node* s = new Node;
			s->Allocate();
		}
		else{
			InsertNonfull(key);
		}
	}
	
	/*输入：要查找的关键字 
	  输出：关键字所在节点，在key数组中的下标*/
	pair<Node_ptr, pos_in_key_array> Search(k){
		
	}
	
	/*删除关键字*/
	bool Delete(key){
		
	}

private:
	/*分裂root的第i个子节点*/
	SplitChild(Node* root, int i){
		Node* y = root->child[i];
		Node* z = new Node;
		z.leaf = y->leaf;
		z->Allocate();
		z->n = t-1;
		
		//copy key:     0...t-2, t-1, t...2*t-2
		for(int j=0; j<=t-2; ++j){
			z->key[j] = y->key[t+j];
		}
		//copy child:	0...t-1, t...2*t-1
		if(!y->leaf){
			for(int j=0; j<=t-1; ++j){
				z->child[j] = y->child[j+t];
			}
		}
		y->n = t-1;
		
		//move key  

		
		//move child
		
		
		root->n += 1;

		
	/**/
	InsertNonfull(int key){
		
	}
}








