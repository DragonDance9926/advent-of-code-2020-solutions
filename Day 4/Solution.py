# -*- coding: utf-8 -*-
import re
#Input handling
with open('input.txt') as f:
    x = f.read().split('\n\n')

passport = []

#Splitting passports
for a in x:
    j = a.split()
    info = {}
    for k in j:
        key = k.split(":")[0]
        value = k.split(":")[1]
        info[key] = value
    passport.append(info)
    
  


def part1(passport):
    c = 0
    for a in passport:
        check = ('byr' in a) and('iyr' in a) and('eyr' in a) and('hgt' in a) and ('hcl' in a) and ('ecl' in a) and ('pid' in a)
        if check:
            c+= 1
    return c

def part2(passport):
    c = 0
    for a in passport:
        #byr
        check1 = ('byr' in a)  and (len(a['byr']) ==4) and (int(a['byr']) >= 1920) and (int(a['byr']) <= 2002)
        #iyr
        check2 = ('iyr' in a) and (len(a['iyr']) ==4)and (int(a['iyr']) >= 2010) and (int(a['iyr']) <= 2020)
        #eyr
        check3 = ('eyr' in a) and (len(a['eyr']) ==4) and (int(a['eyr']) >= 2020) and (int(a['eyr']) <= 2030)
        #hgt
        if ('hgt' in a):
            x = a['hgt'][-2:]
            check4 = False
            if x == "cm":
                check4 = ( (int(a['hgt'][:-2]) <= 193)) and  (int(a['hgt'][:-2]) >= 150)
            elif x == "in":
                check4 = ( (int(a['hgt'][:-2]) <= 76)) and  (int(a['hgt'][:-2]) >= 59)
        else:
            check4 = False
        #hcl
        check5 = ('hcl' in a) and bool(re.search("^#[[0-9]|[a-f]|[A-F]{6}",a['hcl']))
        #ecl
        check6 = ('ecl' in a) and bool(re.search("amb|blu|brn|gry|grn|h",a['ecl']))
        #pid
        check7 = ('pid' in a) and bool(re.search("[0-9]{9}",a['pid']))
        if (check1 and check2 and check3 and check4 and check5 and check6 and check7):
            c += 1
    return c
                
print(part1(passport))
print(part2(passport))