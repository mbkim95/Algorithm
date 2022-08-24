import collections


class Solution:
    def isPalindrome(self, s: str) -> bool:
        str = collections.deque()

        for char in s:
            if char.isalnum():
                str.append(char.lower())

        while len(str) > 1:
            if str.popleft() != str.pop():
                return False
        return True
