#!/usr/bin/python

# Builds a test array based on input npoints e.g. for npoints=8:
# test_array = [1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0]
#
# Performs an fft on the test array to provide a "GOLDEN MODEL" result
# With real and imaginary portions in separate columns e.g.
# 
#      ______GOLDEN MODEL______
#      0     4.000     0.000
#      1     1.000    -2.414
#      2     0.000     0.000
#      3     1.000    -0.414
#      4     0.000     0.000
#      5     1.000     0.414
#      6     0.000     0.000
#      7     1.000     2.414
# 
#------------------------------------------------------------------------
from pprint import pprint
def fft_numpy(npoints, nunits, DBG=0):
    # Note: 'nunits' is unused!

    # from scipy.fftpack import fft
    from numpy import fft

    # Build a step-function test array of input datapoints, e.g. for npoints=8:
    # test_array = [1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0]
    n2 = int(npoints) >> 1
    test_array = ([1.0] * n2) + ([0.0] * n2)
    if DBG:
        print("")
        print("test_array = ", end='')
        pprint(test_array)
        print("")

    # Calculate the fft
    fft_results = fft.fft(test_array)

    # Unpack results into separate real and imaginary arrays
    ar=[]; ai=[]
    for c in fft_results:
        ar = ar + [ c.real ]
        ai = ai + [ c.imag ]

    # Optional debugging
    if DBG:
        print("")
        print("     ______GOLDEN MODEL______")
        for i in range(npoints):
            print(f"  {i:4d} {ar[i]:9.3f} {ai[i]:9.3f}")
        print("")

    return (ar+ai)

fft_numpy(8, "unused", DBG=1)
