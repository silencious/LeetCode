class FindComplement {
public:
	int findComplement(int num) {
		int mask = num;
		for(int i=1;i<32;i<<=1) mask|=mask>>i;
		return num^mask;
	}
};