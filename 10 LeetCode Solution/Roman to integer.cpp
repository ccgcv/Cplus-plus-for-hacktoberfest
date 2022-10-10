class Solution {
public:
    int romanToInt(string s) {
        int result = 0; // to overwrite the garbage values
	int i = -1;
	while (s[++i])
	{
		if (s[i] == 'I')
			result += 1;
		else if (s[i] == 'V' && i != 0 && s[i-1] == 'I')
			result += 3;
		else if (s[i] == 'V')
			result += 5;

		else if (s[i] == 'X' && i != 0 && s[i - 1] == 'I') // IX=8
			result += 8;

		else if (s[i] == 'X') // X=10
			result += 10;
		else if (s[i] == 'L' && i != 0 && s[i - 1] == 'X')// XL = 30
			result += 30;
		else if (s[i] == 'L') // L =50
			result += 50;
		else if (s[i] == 'C' && i != 0 && s[i - 1] == 'X')// XC
			result += 80;
		else if (s[i] == 'C')
			result += 100;
		else if (s[i] == 'D' && i != 0 && s[i - 1] == 'C')// CD =30
			result += 300;
		else if (s[i] == 'D')
			result += 500;
		else if (s[i] == 'M' && i != 0 && s[i - 1] == 'C')// CM =800
			result += 800;
		else if (s[i] == 'M')
			result += 1000;
    }
        return result;
    }
};