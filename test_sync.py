from sync_leetcode import slugify

def test():
    assert slugify("Two Sum") == "two-sum"
    assert slugify("Palindrome Number!!") == "palindrome-number"
    assert slugify("N-Queens II") == "n-queens-ii"
    print("ok")

if __name__ == "__main__":
    test()
