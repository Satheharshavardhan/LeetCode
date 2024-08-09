def maximum_gain(s, x, y):
    larger = max(x, y)
    gain = 0

    if larger == x:
        while 'ab' in s:
            s = s.replace('ab', '', 1)
            gain += x
        while 'ba' in s:
            s = s.replace('ba', '', 1)
            gain += y
    else:
        while 'ba' in s:
            s = s.replace('ba', '', 1)
            gain += y
        while 'ab' in s:
            s = s.replace('ab', '', 1)
            gain += x

    return gain
