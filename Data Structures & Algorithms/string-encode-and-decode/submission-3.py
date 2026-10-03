class Solution:

    def encode(self, strs: List[str]) -> str:
        string = ''
        for x in strs:
            string += (x + '}')
        return string

    def decode(self, s: str) -> List[str]:
        list = []
        string = ''
        for x in s:
            if (x != '}'):
                string += x
            else:
                list.append(string)
                string = ''
        return list
