int reversePairCount = 0;
for(int i=0; i<nums.size(); i++) {
	for(int j=i+1; j<nums.size(); j++) {
		if( nums[i] > 2*nums[j]) reversePairCount++;
	}
}
return reversePairCount;
