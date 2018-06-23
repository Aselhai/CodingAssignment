# Age in Seconds Program
# This program will calculate the difference in age in seconds of two friends

import datetime

# Get month, day, year of birth
month_birth_1 = int(input('Person 1: Enter month born (1-12): '))
day_birth_1 = int(input('Person 1: Enter day born (1-31): '))
year_birth_1 = int(input('Person 1: Enter year born (4-digit): '))
month_birth_2 = int(input('Person 2: Enter month born (1-12): '))
day_birth_2 = int(input('Person 2: Enter day born (1-31): '))
year_birth_2 = int(input('Person 2: Enter year born (4-digit): '))

# Get current month, day, year of birth
current_month = datetime.date.today().month
current_day = datetime.date.today().day
current_year = datetime.date.today().year

# Determine number of seconds in a day, average month, and average year
numsecs_day = 24 * 60 * 60
numsecs_year = 365 * numsecs_day

avg_numsecs_year = ((4 * numsecs_year) + numsecs_day) // 4
avg_numsecs_month = avg_numsecs_year // 12

# Calculate approximate age in seconds
numsecs_1900_dob_1 = ((year_birth_1 - 1900) * avg_numsecs_year) + \
                   ((month_birth_1 - 1) * avg_numsecs_month) + \
                   (day_birth_1 * numsecs_day)
numsecs_1900_today_1 = (current_year - 1900 * avg_numsecs_year) + \
                   (current_month - 1 * avg_numsecs_month) + \
                   (current_day * numsecs_day)

numsecs_1900_dob_2 = ((year_birth_2 - 1900) * avg_numsecs_year) + \
                   ((month_birth_2 - 1) * avg_numsecs_month) + \
                   ((day_birth_2) * numsecs_day)
numsecs_1900_today_2 = (current_year - 1900 * avg_numsecs_year) + \
                   (current_month - 1 * avg_numsecs_month) + \
                   (current_day * numsecs_day)

age_in_secs_1 = numsecs_1900_today_1 - numsecs_1900_dob_1
age_in_secs_2 = numsecs_1900_today_2 - numsecs_1900_dob_2

value = abs(age_in_secs_1 - age_in_secs_2)

# output results
print('Age difference in seconds:', value)
