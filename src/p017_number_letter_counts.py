known = {
    1: "one",
    2: "two",
    3: "three",
    4: "four",
    5: "five",
    6: "six",
    7: "seven",
    8: "eight",
    9: "nine",
    10: "ten",
    11: "eleven",
    12: "twelve",
    13: "thirteen",
    14: "fourteen",
    15: "fifteen",
    16: "sixteen",
    17: "seventeen",
    18: "eighteen",
    19: "nineteen",
    20: "twenty",
    30: "thirty",
    40: "forty",  # Check!
    50: "fifty",
    60: "sixty",
    70: "seventy",
    80: "eighty",
    90: "ninety",
    1000: "onethousand"
}

def to_words(n: int) -> str:
    if n in known:
        return known[n]

    elif n < 100:
        tens = (n // 10) * 10
        units = n % 10
        return to_words(tens) + to_words(units)

    elif n < 1000:
        hundreds_unit = n // 100
        tens = n % 100

        hundreds_part = to_words(hundreds_unit) + "hundred"
        if tens == 0:
            return hundreds_part
        else:
            return hundreds_part + "and" + to_words(tens)

    else:
        raise ValueError()

print(sum(len(to_words(i)) for i in range(1, 1001)))

