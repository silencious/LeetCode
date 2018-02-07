class HammingDistance {
public:
	int hammingDistance(int x, int y) {
		unsigned z=x^y,n=0;
		while(z){
			n+=(z&1);
			z>>=1;
		}
		return n;
	}
};