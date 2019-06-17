# perl --version | grep . | head -1
genesis2_path=`command -v Genesis2`

if [ "$genesis2_path" != "" ]; then
  echo "Found existing Genesis2 '$genesis2_path'"

else
  echo "Looks like Genesis2 is not yet set up. Looking in /tmp..."

  if [ -d /tmp/Genesis2 ]; then
    echo "Found existing Genesis2 in /tmp/Genesis2..."
  else
    echo "Installing new Genesis2 in /tmp/Genesis2..."
    git clone https://github.com/StanfordVLSI/Genesis2.git /tmp/Genesis2

    # 05/2019 REMOVED Compress subdir from repository omg finally so don't need this
    # huh.  seems to break if don't remove distrib Zlib?
    # Compress::Raw::Zlib object version 2.060 does not match bootstrap parameter 2.033 at /tmp/Genesis2/Genesis2Tools/PerlLibs/ExtrasForOldPerlDistributions/Compress/Raw/Zlib.pm line 98.
    # /bin/rm -rf /tmp/Genesis2/Genesis2Tools/PerlLibs/ExtrasForOldPerlDistributions/Compress

    # 06/2019 OMG now it's back. In "Archive" for some reason...?
    # FIXME maybe check github log to see who did this..?
    # Compilation failed in require at /tmp/Genesis2/.../Archive/Zip.pm line 12.
    # BEGIN failed--compilation aborted at /tmp/Genesis2/.../Archive/Zip.pm line 12.
    /bin/rm -rf /tmp/Genesis2/Genesis2Tools/PerlLibs/ExtrasForOldPerlDistributions/Archive/

  fi

  # Set path, environment variables
  export GENESIS_HOME=/tmp/Genesis2/Genesis2Tools
  export PATH=".:$GENESIS_HOME/bin:$GENESIS_HOME/gui/bin:$PATH"

  if [ "$PERL5LIB" == "" ]; then
    export PERL5LIB="$GENESIS_HOME/PerlLibs/ExtrasForOldPerlDistributions"
  else
    export PERL5LIB="$PERL5LIB:$GENESIS_HOME/PerlLibs/ExtrasForOldPerlDistributions"
  fi

fi

# Alternatively could maybe do this...
# If running locally, use existing Genesis2 install...
# if (hostname == kiwi) setenv GENESIS_HOME /cad/genesis2/r11879/Genesis2Tools/

