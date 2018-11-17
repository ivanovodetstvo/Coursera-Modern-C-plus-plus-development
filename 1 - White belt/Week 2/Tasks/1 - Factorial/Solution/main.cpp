int Factorial(int x) {
	if (x < 2)
		return 1;
	return x*Factorial(x-1);
}