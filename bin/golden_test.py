#!/usr/bin/python3
import os
import sys
import re

# Compares FFT log file from rtl simulation, against a golden model.
# Summarizes results from each and says either PASS or FAIL.

# This script should produce same results as the prior perl version
# "golden_test.pl". E.g. to compare the two
# 
#   f=../tst/regress/old/verlint/fft.log
#   golden_test.pl $f 8 1 2port > tmp.pl
#   golden_test.py $f 8 1 2port > tmp.py
#   diff tmp.p[ly]

# Set one or more of these vars to "1" to test the script
DBG = 0
DBG9 = 0

# Help message
if (len(sys.argv) != 5):
    scriptname = sys.argv[0];
    print(f"""
    DESCRIPTION: Generates correct fft answers and compares vs. <logfile>

    USAGE:
        {scriptname} <logfile> <npoints> <n_butterfly_units> <sram_type>

    Examples:
      {scriptname} fft.log  8    1 2port
      {scriptname} simv.log 1024 4 1port
      {scriptname} ../tst/regress/old/verlint/fft.log 8 1 2port

    To test failure mechanism, use sram_type "test_error"
      {scriptname} fft.log  8    1 test_error
      

    """)
    exit(13)

# Process command-line arguments
[ LOGFILE, npoints, nunits, sram_type ] = sys.argv[1:]

print(f'''
Comparing FFT log '{LOGFILE}' vs. gold model (GM)
with npoints={npoints}, nunits={nunits}, sram_type='{sram_type}'\
''')

########################################################################
# Set FFTGEN_DIR as the path to the local fftgen repo.
# Assumes that this script lives in FFTGEN_DIR/bin
# E.g. scriptdir='/home/steveri/github/fftgen/bin'
scriptdir=os.path.dirname(os.path.realpath(__file__))
FFTGEN_DIR=os.path.dirname(scriptdir)

# Compare results in "$FFTGEN_DIR/$LOGFILE" against result of running golden model

def main():
    do_test(npoints, nunits, sram_type, DBG=0); exit()

def do_test(npoints, nunits, sram_type, DBG=0):
    '''Compare results in <LOGFILE> against result of running golden model'''

    # Examples:
    #   do_test  8, 1, "2port"
    #   do_test 16, 4, "1port"

    if DBG: print('do_test', npoints, nunits, sram_type)

    # Run the golden model and fetch the results
    gm_results = golden_model(npoints, nunits)
    if DBG: print('gm_results=', gm_results)

    fft_results = do_fft()      # Fetch results found in fft log <LOGFILE>
    print('')  # ? yeah i dunno

    if DBG: print('fft_results=', fft_results)

    # If lengths don't match, maybe user got command line args wrong (???)
    # gm_results=range(9) # Uncomment to check error message
    quick_check(LOGFILE, len(gm_results), len(fft_results))

    # Secret sram type to test error handling; inserts a single faulty datapoint
    if (sram_type == "test_error"):
        sram_type = "1port"
        fft_results[3] = "99999"   # Guarantees at least one error

    nerrors = 0
    nerrors += print_results("Real", npoints, gm_results, fft_results)
    nerrors += print_results("Imag", npoints, gm_results, fft_results)

    if DBG: print('found', nerrors, 'errors')

    test_result = "PASS" if (nerrors == 0) else "FAIL"
    plural      = "s"    if (nerrors != 1) else ""
    print(f"{test_result}: {nerrors:d} mismatched result{plural} --- {npoints} {nunits} {sram_type}")

def quick_check(LOGFILE, ngr, nfr):
    'Check to see that gm and fft got same number of results e.g. 16 if npoints=8'
    # If lengths don't match, maybe user got command line args wrong (???)
    # gm_results=range(9) # Uncomment to check error message
    if (ngr != nfr):
        print(f'''\
ERROR: Golden model produced {ngr} results and FFT produced {nfr}.
   Double-check to see that number of results in '{LOGFILE}'
   matches your command-line specification 'npoints={npoints}'.
''')
        exit(13)

def do_fft(DBG=0):

    ##############################################################################
    # Print results from FFT log file

    cmd = f"cat ./{LOGFILE} | awk -f {FFTGEN_DIR}/bin/process_test5.awk | egrep '^ix'"
    fft = my_syscall(cmd)

    # Above command should have yielded fft = e.g.
    #
    # ix00: SRAM000 t5 13500: Wrote(f) wr_data_i mem[0] <= ( 8.000000, 0.000000)
    # ix01: SRAM003 t5 13500: Wrote(f) wr_data_i mem[0] <= ( 1.000000,-5.027340)
    # ix02: SRAM006 t5 14500: Wrote(f) wr_data_i mem[0] <= ( 0.000000, 0.000000)
    # ix03: SRAM005 t5 14500: Wrote(f) wr_data_i mem[0] <= ( 1.000000,-1.496606)
    # ix04: SRAM004 t5 15500: Wrote(f) wr_data_i mem[0] <= ( 0.000000, 0.000000)
    # ix05: SRAM007 t5 15500: Wrote(f) wr_data_i mem[0] <= ( 1.000000,-0.668179)
    # ix06: SRAM002 t5 16500: Wrote(f) wr_data_i mem[0] <= ( 0.000000, 0.000000)
    # ix07: SRAM001 t5 16500: Wrote(f) wr_data_i mem[0] <= ( 1.000000,-0.198912)

    # Optional debugging
    if DBG: print(cmd)
    if DBG: print(fft)

    # Build ar, ai arrays containing real and imaginary numbers in above lines

    ar = []   # Real parts of complex numbers
    ai = []   # Imaginary parts of complex numbers
    for line in fft.split('\n'):

        # From sample line
        # "ix05: SRAM007 t5 15500: Wrote(f) wr_data_i mem[0] <= ( 1.000000,-0.668179)"
        # Want to extract (ix,real,imag) = ("5","1.000000","-0.668179")

        parse = re.search(r'^ix([0-9]+).*\( *([^ ,]*), *([^ ,]*).$', line)
        if parse:
            [ ix, real, imag ] = [ parse.group(1), parse.group(2), parse.group(3) ]

            # E.g. if index ix=3, we should be about to push the fourth number in each array
            assert len(ar) == int(ix); ar = ar + [ real ]
            assert len(ai) == int(ix); ai = ai + [ imag ]

    # Debugging
    if DBG:
        print('real', ar)
        print('imag', ai)
        print("     ______________FFT___________")
        for ix in range(0,len(ar)):
            print(f"    {ix:4d} {ar[ix]:>9s}    {ai[ix]:>9s}")

    return (ar + ai)

def golden_model(npoints, nunits, DBG=0):
    '''Can use either perl or python golden model!'''
  # return golden_model_perl( npoints, nunits, DBG=0)
    return golden_model_numpy(npoints, nunits, DBG=0)

def golden_model_numpy(npoints, nunits, DBG=0):     # Note: 'nunits' is unused!
    '''Calculate FFT of a step-down function'''

    # Build a step-function test array of input datapoints, e.g. for npoints=8:
    # test_array = [1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0]
    n2 = int(npoints) >> 1  # Divide by two and still be integer
    test_array = ([1.0] * n2) + ([0.0] * n2)
    if DBG:
        print("")
        print("test_array = ", end='')
        pprint(test_array)
        print("")

    # Calculate the fft
    from numpy import fft; fft_results = fft.fft(test_array)

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

def golden_model_perl(npoints, nunits, DBG=0):
    '''Invoke the Golden Model and capture the results'''

    # E.g. my gm = my_syscall(f"{golden_model} 8 1")
    # Add egrep filter to eschew any lines with non-numeric
    # characters (probably not strictly necessary).
    golden_model = f"{FFTGEN_DIR}/bin/fft_golden_model.pl"
    cmd = f"{golden_model} {npoints} {nunits} | egrep -v '[a-zZ-Z]'"
    gm = my_syscall(cmd)
    if DBG:
        print("")
        print("     ______GOLDEN MODEL______")
        print(gm)
        print("")

    # Example:
    #      ______GOLDEN MODEL______
    #        0    4.000     0.000
    #        1    1.000    -2.414
    #        2    0.000     0.000
    #        3    1.000    -0.414
    #        4    0.000     0.000
    #        5    1.000     0.414
    #        6    0.000     0.000
    #        7    1.000     2.414

    # Build ar, ai arrays containing real and imaginary numbers from each line.
    # Each line looks like this: " 1   1.000   -2.414"

    ar = []   # Real part of complex number
    ai = []   # Imaginary part of complex number
    for line in gm.split('\n'):
        parse = re.search(r'\s*(\S+)\s*(\S+)\s*(\S+)', line)
        if parse:
            [ ix, real, imag ] = [ parse.group(1), parse.group(2), parse.group(3) ]

            # E.g. if index ix=3, we should be about to push the fourth number in each array
            assert len(ar) == int(ix); ar = ar + [ real ]
            assert len(ai) == int(ix); ai = ai + [ imag ]

    if DBG:
        print('real', ar)
        print('imag', ai)
        print("     _________GOLDEN MODEL_______")
        for ix in range(0,len(ar)):
            print(f"    {ix:4d} {ar[ix]:>9s}    {ai[ix]:>9s}")

    return (ar + ai)


def print_results(rtype, npoints, gm_results, fft_results, DBG=0):
    '''Compare GM/FFT real or imaginary results according to rtype "Real" or not'''

    nerrors   = 0;
    nwarnings = 0;

    # E.g. if npoints=8, then [0..7] are real nums and [8,15] are corresponding imag pts.
    npoints=int(npoints)
    [ first, last ] = [0, npoints] if (rtype == "Real") else [npoints, 2*npoints]

    print(f"{rtype} results:      GM          FFT")

    # Each result MUST match to at least one decimal place;
    # emit warning if errors at two or three d.p.

    for i in range(first, last):

        # Format with three, two and one sig figs
        g = gm_results[i]; f = fft_results[i]

        # Enable this block to test the warnings and errors
        if (0):
            if (i == 11): f = -0.415  # 3-fig warn vs. -2.414
            if (i == 13): f =  0.424  # 2-fig warn vs.  0.414
            if (i == 15): f =  2.511  # ERROR vs. 2.414

        [gr3,fr3] = sigfig(g, f, '%.3f', '[-]0[.]000','0.000')
        [gr2,fr2] = sigfig(g, f, '%.2f', '[-]0[.]00' ,'0.00' )
        [gr1,fr1] = sigfig(g, f, '%.1f', '[-]0[.]0'  ,'0.0'  )

        # ERROR if no match @ one sig figs.
        # Warning if no match @ two or three sig figs.

        status = ""
        if DBG: print(i, gr1, fr1)

        if (gr1 != fr1):
                status = f" *** ERROR '{gr1}' ne '{fr1}'";
                nerrors = nerrors + 1

        elif (gr2 != fr2):
            status = " *** WARNING mismatch at 2nd sig fig";
            nwarnings = nwarnings + 1

        elif (gr3 != fr3):
            status = " *** WARNING mismatch at 3rd sig fig";
            nwarnings = nwarnings + 1

        print(f"             {gr3:>9s}    {fr3:>9s}{status}")

    print('')
    return nerrors

def sigfig(g, f, fmt, neg, pos, DBG=0):
    '''
    E.g. if (g,f)=(0.1234,5.6789) and fmt="%.1", return ("0.1","5.6")
    Also, disallow minus-zero, i.e. turn e.g. "-0.00" into "0.00"
    '''
    gr = fmt % float(g); fr = fmt % float(f)

    # Oh this is annoying; must canonicalize e.g. "-0.000" => "0.000"
    # fr='-0.0'; fr='-0.00'; fr='-0.000'
    fr = re.sub(neg, pos, fr); gr = re.sub(neg, pos, gr)
    
    # Debugging
    if DBG: print(f'GM  {fmt} = {gr} ({g})')
    if DBG: print(f'FFT {fmt} = {fr} ({f})')
    if DBG: print('')

    # return [gr.strip(), fr.strip()] # Don't need the strip anymore, right?
    return [gr, fr]

# Same as shell `backtick` e.g. result=`echo foo | sed 's/oo/ox/'`
#   shell: result=`echo foo | sed 's/oo/ox/'`
#   this:  result= my_syscall("echo foo | sed 's/oo/ox/'")
def my_syscall(cmd):
    '''Example: [status,stdout,stderr]=my_syscall("echo foo | sed 's/oo/ox/'")
    '''
    from subprocess import run, PIPE
    p = run(cmd, shell=True, stdout=PIPE, stderr=PIPE)
    #
    [exit_status, stdout, stderr] = [
        p.returncode, p.stdout.decode(), p.stderr.decode() ]
    #
    return stdout

main()


