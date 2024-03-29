

// 꼬리재귀 함수로 표현한 factorial

unsigned int factorial(unsigned int n){
    return factorial_tail_rec(n, 1);
}
 
unsigned int factorial_tail_rec(unsigned int n, unsigned int acc){

    if( n == 1 ) return acc;
    return factorial_tail_rec(n-1, acc * n);
}


//========================================================
//일반적인 factorial
unsigned int factorial(unsigned int n){

	if (n == 0){
		return 1;
	}
    return factorial( n * factorial(n-1));
}