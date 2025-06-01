genesis2_path=`command -v Genesis2` || echo okay

if [ "$genesis2_path" != "" ]; then
  echo "Found existing Genesis2 '$genesis2_path'"

else
  export GENESIS_HOME=/tmp/Genesis2
  echo "Looks like Genesis2 is not yet set up. Looking for $GENESIS_HOME..."
  if [ -d $GENESIS_HOME ]; then
    echo "Found existing Genesis2 in $GENESIS_HOME..."
  else
    echo "Installing new Genesis2 in $GENESIS_HOME..."
    git clone https://github.com/StanfordVLSI/Genesis2.git $GENESIS_HOME

    echo "Installing version $gsha_good"
    (cd $GENESIS_HOME;  git checkout 4db41fd)

  fi

  # Set path, environment variables
  export PATH=".:$GENESIS_HOME/bin:$GENESIS_HOME/gui/bin:$PATH"
  export PERL5LIB=$GENESIS_HOME/PerlLibs:/$GENESIS_HOME/PerlLibs/ExtrasForOldPerlDistributions:$PERL5LIB
fi
