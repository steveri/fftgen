Notes 06/2021: Yeah most of this information is old and outdated but
imma leave it here because me lazy.


#### add_copyright.csh

<pre>
add_copyright.csh - add copyright info to a file
EXAMPLE: "add_copyright.csh rtl/mux.vp"
</pre>


#### bsr.awk
<pre>

bsr.awk - Because verilator does not support $bitstoreal, and because
I want to display floating-point numbers in debug printouts, I wrote
bsr.awk. It works like this: in the verilog code, instead of 

  $display("t1 = %9.6f", $bitstoshortreal(t1));

you insert

  $display("t1 = bsr'%08x", $bitstoshortreal(t1));

such that your simulation emits an output line something like:

  % simv mydesign
  ...
  t1 = bsr'3f800000
  ...

So then you run bsr.awk and that turns all instances of "bsr'XXXXXXXX"
into the equivalent floating point number like so:

  % simv | bsr.awk %9.6f
  ...
  t1 =  1.000
  ...




For a good time try:
  % bsr.awk help

TODO
- better README file...maybe include a guide to all the stuff in the bin directory
- at the same time, could maybe clean up all the unnecessary cruft...



</pre>

#### simv_analysis

tools for analyzing simv log for correctness

FIXME/TODO should move to ../tst/bin probably


