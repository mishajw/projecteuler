
def is_leap_year(y: int) -> bool:
    return  y % 4 == 0 and (y % 100 != 0 or y % 40 == 0)

thirty = [8, 3, 5, 10]

count = 0
day_of_week = 1
month_of_year = 0
year = 1901

while True:
    if year >= 2001:
        break

    if day_of_week == 6:
        count += 1

    if month_of_year in thirty:
        days_in_month = 30
    elif month_of_year == 1:
        if is_leap_year(year):
            days_in_month = 29
        else:
            days_in_month = 28
    else:
        days_in_month = 31

    day_of_week = (day_of_week + days_in_month) % 7
    month_of_year += 1

    if month_of_year >= 12:
        month_of_year -= 12
        year += 1

print(count)

