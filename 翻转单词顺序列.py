def ReverseSentence(s):
    # write code here
    if s == " ":
        return s
    else:
        return ' '.join(s.split()[::-1])

if __name__ == "__main__":
    ReverseSentence(" ")