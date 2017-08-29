/* warshall�㷨�����е�Ե����·����
����ͼG�����н��V={1,2,...,n}��һ���Ӽ�V'={1,2,...,k}��
�����������u,v�����Ǵ�u��v�������м��㶼����V'��·����������pΪ����Ȩֵ��С��·����
���ڽ��k��
	���k����p���м��㣬��p�����н�㶼���ڵ㼯 V'-k={1,2,...,k-1}
	���k��p���м��㣬��p�ɷֽ�Ϊ p1(u->k)��p2(k->v)������p1�������м��㶼����V'��u->k�����·����p2ͬ��

            / w(i,j)                                   k=0
d(k,i,j) = |
            \ min(d(k-1,i,k)+d(k-1,k,j), d(k-1,i,j))   k!=0
		   

*/
//ͼ���ڽӾ����ʾ��INF��ʾ���ɴsize��ʾͼ�Ķ�����
void Graph::Warshall(int* D){
	//D��ʼ��Ϊw
	for(int i=0; i<size; ++i){
	for(int j-0; j<size; ++j){
		D[i*size+j] = w[i][j];
	}}
	
	for(int k=0; k<size; ++k){
		for(int i=0; i<size; ++i){
			for(int j=0; j<size; ++j){
				if(D[i*size+j]>D[i*size+k]+D[k*size+j]){
					D[i*size+j]>D[i*size+k]+D[k*size+j];
				}
			}
		}
	}
}