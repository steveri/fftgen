cat <<EOF

# FIXME pretty sure this (below) is WRONG, or at least outdated, see
# latest bash version (setup_genesis.sh) to see how it should work...

EOF

# perl --version | grep . | head -1
set genesis2_path = `which Genesis2`

if ("$genesis2_path" != "") then
  echo "Found existing Genesis2 '$genesis2_path'"

else
  echo "Looks like Genesis2 is not yet set up. Looking in /tmp..."

  if (-d /tmp/Genesis2) then
    echo "Found existing Genesis2 in /tmp/Genesis2..."
  else
    echo "Installing new Genesis2 in /tmp/Genesis2..."
    git clone https://github.com/StanfordVLSI/Genesis2.git /tmp/Genesis2

    # 05/2019 REMOVED Compress subdir from repository omg finally
    # huh.  seems to break if don't remove distrib Zlib?
    # Compress::Raw::Zlib object version 2.060 does not match bootstrap parameter 2.033 at /tmp/Genesis2/Genesis2Tools/PerlLibs/ExtrasForOldPerlDistributions/Compress/Raw/Zlib.pm line 98.
    # /bin/rm -rf /tmp/Genesis2/Genesis2Tools/PerlLibs/ExtrasForOldPerlDistributions/Compress

  endif

  # Set path, environment variables
  setenv GENESIS_HOME /tmp/Genesis2/Genesis2Tools
  set path=(. $GENESIS_HOME/bin $GENESIS_HOME/gui/bin $path)

  if (! $?PERL5LIB) then
    setenv PERL5LIB $GENESIS_HOME/PerlLibs/ExtrasForOldPerlDistributions
  else
    setenv PERL5LIB "$PERL5LIB":$GENESIS_HOME/PerlLibs/ExtrasForOldPerlDistributions
  endif

endif

# Alternatively could maybe do this...
# If running locally, use existing Genesis2 install...
# if (hostname == kiwi) setenv GENESIS_HOME /cad/genesis2/r11879/Genesis2Tools/

cat <<EOF

# FIXME pretty sure this (above) is WRONG, or at least outdated, see
# latest bash version (setup_genesis.sh) to see how it should work...

EOF
