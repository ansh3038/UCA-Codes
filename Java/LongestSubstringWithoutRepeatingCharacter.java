class Solution {
    public int lengthOfLongestSubstring(String s) {
        int len = 0;
        HashMap<Character, Integer> map = new HashMap<>();
        int i = 0;
        int curr = 0;
        while(i<s.length()){
            if(map.containsKey(s.charAt(i))){
                i = map.get(s.charAt(i));
                if(curr>len){
                    len = curr;
                }
                curr=0;
                map.clear();
            }
            else{
                map.put(s.charAt(i),i);
                curr++;
            }
            i++;
        }
        return Math.max(len,curr);
        
    }
}