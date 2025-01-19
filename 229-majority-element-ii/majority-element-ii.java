class Solution {
    public List<Integer> majorityElement(int[] nums) {
        int cnt1 = 0, num1 = 0, cnt2 = 0, num2=0;
        int n = nums.length;
        for(int i=0;i<nums.length;i++){
            if(cnt1==0 && nums[i]!=num2){
                num1 = nums[i];
                cnt1 = 1;
            }else if(cnt2==0 && nums[i]!=num1){
                num2 = nums[i];
                cnt2 = 1;
            }else if(nums[i]==num1){
                cnt1++;
            }else if(nums[i]==num2){
                cnt2++;
            }else{
                cnt1--;
                cnt2--;
            }
        }
        List<Integer> arr = new ArrayList<>();
        int acnt1=0, acnt2=0;
        for(int i=0;i<nums.length;i++){
            if(nums[i]==num1){
                acnt1++;
            }
            if(nums[i]==num2) acnt2++;
        }
        if(acnt1>n/3) arr.add(num1);
        if(acnt2>n/3 && num1!=num2) arr.add(num2);
        return arr;
    }
}