class PowerOfFour {
public:
	bool isPowerOfFour(int num) {
		if(num<=0) return false;
		if(num==1) return true;
		return !(num%4) && isPowerOfFour(num/4);
	}
	bool isPowerOfFour2(int num){
		return num>0 && (num&(num-1))==0 && num&0x55555555;
	}
};