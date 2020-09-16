class Solution {
    public int maxDiff(int num) {
		String str1 = Integer.toString(num); // Max
		String str2 = Integer.toString(num); // Min

		// Finding out the first character which is not '9' and replacing all it's occurrences
		for(int i=0; i<str1.length(); i++) {
			if(str1.charAt(i) != '9') {
				str1 = str1.replaceAll(str1.charAt(i)+"", "9");
				break;
			}
		}

		// If the first digit itself not '1' then replace the occurrences of it with '1'
		// As there are no trailing zeros allowed.
		if(str2.charAt(0) != '1') {
			str2 = str2.replaceAll(str2.charAt(0)+"", "1");
		} else {
			// Find out the first occurrence which is neither 1 nor 0. and replace it with zero			
			for(int i=1; i<str2.length(); i++) {
				if(!"01".contains(str2.charAt(i)+"")) {
					str2 = str2.replaceAll(str2.charAt(i)+"", "0");
					break;
				}
			}
		}

		return Integer.parseInt(str1) - Integer.parseInt(str2); 
    }
}