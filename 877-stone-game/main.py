class Solution:
    def stoneGame(self, piles: List[int]) -> bool:
        # Since the constraint is that the pile length is even and sum of piles is odd
	# that means there cannot be a tie, and alice can pick whether to pick the even indexed or odd indexed.
	# only thing alice needs to do is to add up all the even indexed / odd indexed pile, and choose whatevery the highest
	# since alice is playing optimal and first, alice will always win no matter what.
	return True
