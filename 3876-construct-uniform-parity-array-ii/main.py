class Solution:
    def uniformArray(self, nums1: list[int]) -> bool:
        # so what we need here, is to first check if an array is all odds or all even
        # if yes, we js return true
        # odd - odd = even
        # even - even = even
        # odd - even = odd
        # even - odd = odd

        # we can only transform numbers if there's a number lower than it
        # that means the lowest value parity should be the answer, if not, it's false
        # we need to determine if we can transform all the numbers' parity into the lowest number parity

        minnum1 = min(nums1)
        even = (minnum1 % 2 == 0) 
        if even == True:
            for key, val in enumerate(nums1):
                if val % 2 == 1:
                    return False
        return True
            
        
