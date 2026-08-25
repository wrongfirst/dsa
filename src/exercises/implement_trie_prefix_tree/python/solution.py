class PrefixTreeNode:
    def __init__(self):
        self.children: list[Optional['PrefixTreeNode']] = [None] * 26
        self.end = False


class PrefixTree:
    def __init__(self):
        self.root = PrefixTreeNode()

    def insert(self, word: str) -> None:
        curr = self.root
        for c in word:
            i = ord(c) - ord("a")
            if curr.children[i] is None:
                curr.children[i] = PrefixTreeNode()
            child = curr.children[i]
            assert child is not None
            curr = child
        curr.end = True

    def search(self, word: str) -> bool:
        curr = self.root
        for c in word:
            i = ord(c) - ord("a")
            child = curr.children[i]
            if child is None:
                return False
            curr = child
        return curr.end

    def startsWith(self, prefix: str) -> bool:
        curr = self.root
        for c in prefix:
            i = ord(c) - ord("a")
            child = curr.children[i]
            if child is None:
                return False
            curr = child
        return True
