class Solution {
    public List<List<Integer>> threeSum(int[] arr) {
        Arrays.sort(arr);
        Set<List<Integer>> ans = new HashSet<>();
        for(int i = 0; i<arr.length; i++){
            if(i>0 && arr[i]==arr[i-1]){
                continue;
            }

            int j = i+1;
            int k = arr.length-1;
            while(j<k){
                int b = arr[i]+arr[j]+arr[k];
                if(b==0){
                    List<Integer> a = new ArrayList<>();
                    a.add(arr[i]);
                    a.add(arr[j]);
                    a.add(arr[k]);
                    ans.add(a);
                    j++;
                    k--;
                }
                else if(b>0){
                    k--;
                }
                else{
                    j++;
                }
            }
        }
        return new ArrayList<>(ans);
        
    }
}