

// 단방향 리스트에서 
// 뒤에서 K번째 원소를 찾는 알고리즘

// C++
node* nthToLast(node* head, int k, int & i){
	
	if(head == NULL){
		return NULL;
	}

	node * nd = nthToLast(head->next, i);

	i = i + 1;
	if(i == k){
		return head;
	}
	return nd;
}